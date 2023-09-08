#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define POOL_NUM 10

// 任务队列链表
typedef struct Task
{
  void *(*func) (void *arg); // 返回值是指针的函数指针
  void *arg;
  struct Task *next;
} Task;
// 线程池
typedef struct ThreadPool
{
  pthread_mutex_t taskLock;
  pthread_cond_t newTask; // 条件变量
  pthread_t tid[POOL_NUM];
  Task *queue_head; // 定义任务队列的头部
  int buzywork;     // 有几个线程在工作
} ThreadPool;

ThreadPool *pool;

void *
workThread (void *arg)
{
  while (1)
    {
      pthread_mutex_lock (&pool->taskLock);
      pthread_cond_wait (&pool->newTask, &pool->taskLock);
      // 从队列取出任务
      Task *ptask = pool->queue_head;
      pool->queue_head = pool->queue_head->next;
      pthread_mutex_unlock (&pool->taskLock);
      ptask->func (ptask->arg);
      pool->buzywork--;
    }
}

void
pool_init ()
{
  pool = malloc (sizeof (ThreadPool));
  pthread_mutex_init (&pool->taskLock, NULL);
  pthread_cond_init (&pool->newTask, NULL);
  pool->queue_head = NULL;
  pool->buzywork = 0;
  // 创建线程
  for (int i = 0; i < POOL_NUM; i++)
    {
      pthread_create (&pool->tid[i], NULL, workThread, NULL);
    }
}

// 写个任务用于插入
void *
realWork (void *arg)
{
  printf ("Finish work %d\n", (int)arg);
}

void
pool_add_task (int arg)
{
  // 先创建新任务
  Task *newTask;
  pthread_mutex_lock (&pool->taskLock);
  while (pool->buzywork >= POOL_NUM)
    {
      // 如果在运行线程大于线程池线程数
      // pthread_cond_wait无法接收后面来的任务的信号
      // 所以这里需要进行一段时间的延时等待有的线程空闲
      // 在sleep前面解锁是为了让workthread线程都可以运行
      pthread_mutex_unlock (&pool->taskLock);
      usleep (18000);
      pthread_mutex_lock (&pool->taskLock);
    }
  pthread_mutex_unlock (&pool->taskLock);
  // 初始化任务的各项参数
  newTask = malloc (sizeof (Task));
  newTask->func = realWork;
  newTask->arg = (void *)arg;
  // 在任务队列中插入任务
  pthread_mutex_lock (&pool->taskLock);
  Task *member = pool->queue_head;
  // 如果任务队列没有队列，直接在链表头放任务
  if (member == NULL)
    {
      pool->queue_head = newTask;
    }
  // 如果队列中有任务，把任务添加到队列末
  else
    {
      while (member->next)
        {
          member = member->next; // 遍历到最后一个节点
        }
      member->next = newTask;
    }
  pool->buzywork++;
  // 通知消费者线程
  pthread_cond_signal (&pool->newTask);
  pthread_mutex_unlock (&pool->taskLock);
}

void
pool_destory ()
{
  Task *head;
  while (pool->queue_head)
    {
      head = pool->queue_head;
      pool->queue_head = pool->queue_head->next;
      free (head);
    }
  pthread_mutex_destroy (&pool->taskLock);
  pthread_cond_destroy (&pool->newTask);
}

int
main ()
{
  pool_init ();
  sleep (15);
  for (int i = 1; i < 20; i++)
    {
      pool_add_task (i);
    }
  sleep (5);
  pool_destory ();
}