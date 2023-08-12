#include <stdio.h>
#include <stdlib.h>

typedef int E;

typedef struct LNode
{
  E element;
  struct LNode *next;
} LNode;

typedef struct Queue
{
  LNode *front, *rear;
} LinkQueue;


// 判断队列为空
int
isEmpty (LinkQueue *queue)
{
  return queue->front == queue->rear;
}


int
initQueue (LinkQueue *queue)
{
  LNode *node = malloc (sizeof (LNode));
  if (node == NULL)
    return 0;
  node->next = NULL;
  queue->front = queue->rear = node;
  return 1;
}

// 入队
int
enQueue (LinkQueue *queue, E element)
{
  LNode *node = malloc (sizeof (LNode));
  if (node == NULL)
    return 0;
  node->next = NULL;
  node->element = element;
  queue->rear->next = node; // 开始的时候rear = front 然后后面每次入队的时候
                            // rear.next都会指向新node 然后再让read = node
  queue->rear = node;
  return 1;
}

// 出队
E
deQueue (LinkQueue *queue)
{
  if (!isEmpty (queue))
    {
      LNode *tmp = queue->front->next;
      queue->front->next = queue->front->next->next;
      E e = tmp->element;
      if (queue->rear == tmp) // 如果只剩下一个元素 直接回到最初状态
        queue->rear = queue->front;
      free (tmp);
      return e;
    }
}

// 打印队列
void
printQueue (LinkQueue *queue)
{
  LNode *node = queue->front;
  while (node->next)
    {
      node = node->next;
      printf ("%d ", node->element);
    }
}


int
main ()
{
  LinkQueue queue;
  initQueue (&queue);
  for (int i = 0; i < 5; i++)
    {
      enQueue (&queue, i * 10);
    }
  printQueue (&queue);
  printf ("\n");
  while (!isEmpty (&queue))
    {
      printf ("%d ", deQueue (&queue));
    }
}