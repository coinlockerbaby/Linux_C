#include <stdio.h>
#include <stdlib.h>

// 链式树的元素类型
typedef char Tree_data;
// 链式树
typedef struct TreeNode
{
  Tree_data element;
  struct TreeNode *left, *right;
} TreeNode;
// 链式队列的元素类型
typedef TreeNode *E;

// 节点
typedef struct LNode
{
  E element;
  struct LNode *next;
} LNode;
// 链式队列
typedef struct LinkQueue
{
  LNode *front, *rear;
} LinkQueue;

// 初始化队列
int
initQueue (LinkQueue *head)
{
  LNode *node = malloc (sizeof (LNode));
  if (node == NULL)
    return 0;
  node->next = NULL;
  head->front = head->rear = node;
  return 1;
}

// 入队
int
enQueue (LinkQueue *head, E element)
{
  LNode *node = malloc (sizeof (LNode));
  if (node == NULL)
    return 0;
  node->next = NULL;
  node->element = element;
  head->rear->next = node;
  head->rear = node;
  return 1;
}

// 判空
int
isEmpty (LinkQueue *head)
{
  return head->front == head->rear;
}

// 出队 （出队需要判空）
E
deQueue (LinkQueue *head)
{
  if (!isEmpty (head))
    {
      LNode *tmp = head->front->next;
      head->front->next = head->front->next->next;
      E e = tmp->element;
      if (head->rear == tmp) // 只有一个元素的出队处理
        head->rear = head->front;
      free (tmp);
      return e;
    }
}


TreeNode *
tree_create ()
{
  Tree_data element;
  TreeNode *node;
  scanf ("%c", &element);
  if (element == '#')
    return NULL;
  if ((node = malloc (sizeof (TreeNode))) == NULL)
    {
      printf ("malloc failed\n");
      return NULL;
    }
  node->element = element;
  node->left = tree_create ();
  node->right = tree_create ();
  return node;
}

void
layerorder (TreeNode *head)
{
  LinkQueue queue;
  if (!initQueue (&queue))
    printf ("initQueue failed\n");
  if (head == NULL)
    return;
  printf ("%c", head->element);
  enQueue (&queue, head);
  while (!isEmpty (&queue))
    {
      E r = deQueue (&queue);
      if (r->left)
        {
          printf ("%c", r->left->element);
          enQueue (&queue, r->left);
        }
      if (r->right)
        {
          printf ("%c", r->right->element);
          enQueue (&queue, r->right);
        }
    }
}

int
main ()
{
  TreeNode *head;
  if ((head = tree_create ()) == NULL)
    return -1;
  layerorder (head);
}