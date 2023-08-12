#include <stdio.h>
#include <stdlib.h>

typedef int E;

typedef struct Queue
{
  E *arrary;
  int capacity;
  int font, rear; // 队首 队尾指针
} ArrayQueue;

int
initQueue (ArrayQueue *queue)
{
  queue->arrary = malloc (sizeof (E) * 10);
  // 判断是否申请成功
  if (queue->arrary == NULL)
    return 0;
  queue->capacity = 10;
  queue->font = 0;
  queue->rear = 0;
  return 1;
}

// 入队
int
enQueue (ArrayQueue *queue, E element)
{
  if (((queue->rear + 1) % queue->capacity) == queue->font) //  判断队列是否满
    return 0;
  queue->rear = (queue->rear + 1) % queue->capacity; // 循环队列的循环实现
  queue->arrary[queue->rear] = element;
  return 1;
}
// 判断是否为空列表
int
isEmpty (ArrayQueue *queue)
{
  return queue->font == queue->rear;
}

// 出队
E
disQueue (ArrayQueue *queue)
{
  queue->font = (queue->font + 1) % queue->capacity;  
  return queue->arrary[queue->font];
}

// 打印队列
void
printQueue (ArrayQueue *queue)
{
  for (int i = queue->font + 1; i <= queue->rear; i++)
    {
      printf ("%d ", queue->arrary[i]);
    }
}

int
main ()
{
  ArrayQueue queue;
  initQueue (&queue);
  for (int i = 0; i < 5; i++)
    {
      enQueue (&queue, i * 10);
    }
  printQueue (&queue);
  printf ("\n");
  while (!isEmpty(&queue))
    {
      printf ("%d ", disQueue (&queue));
    }
}
