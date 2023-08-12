#include <stdio.h>
#include <stdlib.h>

typedef int E;

typedef struct ListNode
{
  E element;
  struct ListNode *next;
  struct ListNode *prev;
} ListNode;

void
initList (ListNode *head)
{
  head->prev = NULL;
  head->next = NULL;
}

// 双向链表插入
int
insertList (ListNode *head, E element, int index)
{
  // 判断index的有效性
  if (index < 1)
    return 0;
  while (--index) //  定位到前驱节点
    {
      head = head->next;
      if (head == NULL) // 如果前驱已经是null则不做操作
        return 0;
    }
  ListNode *node = malloc (sizeof (ListNode));
  if (node == NULL)
    return 0; //   如果内存申请失败返回
  node->element = element;
  if (head->next != NULL)
    {
      node->next = head->next; // 让node指向目标位置结点
      node->next->prev = node; // 让目标位置节点的prev指向node
    }
  else
    {
      node->next = NULL;
    }
  head->next = node;
  node->prev = head;
}

int
deleteList (ListNode *head, int index)
{
  if (index < 1)
    return 0;
  while (--index)
    {
      head = head->next;
      if (head == NULL) // 如果前驱节点是null 直接返回
        return 0;
    }
  if (head->next == NULL) // 如果待删除节点是null 直接返回
    return 0;
  ListNode *tmp = head->next;
  if (head->next->next != NULL)
    {
      head->next = head->next->next;
      tmp->next->prev = head;
    }
  else
    {
      head->next = NULL;
    }

  free (tmp);
}

int
main ()
{
  ListNode head;
  initList (&head);
  for (int i = 1; i <= 5; i++)
    {
      insertList (&head, i, i);
    }
  deleteList (&head,5);
  // 正向遍历
  ListNode *node = &head;
  do
    {
      node = node->next;
      printf ("%d -> ", node->element);
    }
  while (node->next != NULL);

  // // 反向遍历
  // printf ("\n");
  // do
  //   {
  //     printf ("%d -> ", node->element);
  //     node = node->prev;
  //   }
  // while (node->prev != NULL);
}