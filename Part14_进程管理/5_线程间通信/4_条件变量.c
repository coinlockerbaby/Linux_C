#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_cond_t hasTaxi = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// 出租车结构体
struct taxi
{
  int num;
  struct taxi *next;
};

struct taxi *head = NULL; // 链表头

// 生产者线程
// 出租车到达
void *
taxiarv (void *argv)
{
  printf ("taxi arrived thread\n");
  pthread_detach (pthread_self ());
  struct taxi *tx;
  int i = 1;
  while (1)
    {
      tx = malloc (sizeof (struct taxi));
      tx->num = i++;
      printf ("taxi %d comming\n", tx->num);
      pthread_mutex_lock (&mutex);
      tx->next = head;
      head = tx; // 让head始终处于链表头
      pthread_cond_signal (&hasTaxi);
      pthread_mutex_unlock (&mutex);
      sleep (1);
    }
}

void *
takeTaxi (void *argv)
{
  printf ("take taxi thread\n");
  pthread_detach (pthread_self ());
  struct taxi *tx;
  while (1)
    {
      pthread_mutex_lock (&mutex);
      while (head == NULL)
        {
          pthread_cond_wait (&hasTaxi, &mutex);
        }
      tx = head;
      head = head->next;
      printf ("%d take taxi %d\n",(int)argv, tx->num);
      free (tx);
      pthread_mutex_unlock (&mutex);
    }
}

int
main ()
{
  pthread_t tid1, tid2;
  pthread_create (&tid1, NULL, taxiarv, NULL);
  pthread_create (&tid2, NULL, takeTaxi, (void*)1);
  pthread_create (&tid2, NULL, takeTaxi, (void*)2);
  pthread_create (&tid2, NULL, takeTaxi, (void*)3);

  while (1)
    {
      sleep (1);
    }
}