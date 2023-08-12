#include <stdio.h>
#include <stdlib.h>

typedef int E;

typedef struct ListNode
{
  E element;
  struct ListNode *next;

} ListNode;

// 传入头结点初始化链表
void
initList (ListNode *node)
{
  node->next = NULL;
}

// 链表插入算法
int
insertList (ListNode *head, E element, int index)
{
  // 判断index的合法性
  if (index < 1)
    return 0;
  // 遍历到位序
  while (--index) // 找到index的前驱节点
    {
      head = head->next;
      if (head == NULL)
        return 0;
    }
  ListNode *node = malloc (sizeof (ListNode));
  if (node == NULL)
    return 0;
  node->element = element;
  node->next = head->next;
  head->next = node;
  return 1;
}

// 链表删除算法
int
deleteList (ListNode *head, int index)
{
  while (--index) // 找到index的前驱节点
    {
      head = head->next;
      if (head == NULL)
        return 0;
    }
  if (head->next == NULL) // 如果index节点是null 那么直接返回
    return 0;
  ListNode *tmp = head->next;    // 把待删除节点地址暂存
  head->next = head->next->next; // 把前驱和后继链接起来
  free (tmp);                    // 把待删除节点删除
}

// 链表获取指定位置的值的指针
E *
getList (ListNode *head, int index)
{
  // 判断参数有效性
  if (index < 1)
    return 0;
  do
    {
      head = head->next;
      if (head == NULL)
        return 0; // 如果
    }
  while (--index);
  return &head->element;
}

// 打印链表所有element
void
printList (ListNode *head)
{
  while (head->next)
    {
      head = head->next;
      printf ("%d ", head->element);
    }
}

// 查找对应元素的位序
int
findList (ListNode *head, E element)
{
  head = head->next;
  int i = 1;
  while (head)
    {
      if (head->element == element)
        return i;
      head = head->next;
      i++;
    }
  return -1;
}

// 求链表长度
int
sizeList (ListNode *head)
{
  int i = 0;
  while (head->next)
    {
      head = head->next;
      i++;
    }
  return i;
}

void
main ()
{
  ListNode head;
  initList (&head); // 初始化节点
  for (int i = 1; i <=30; i++)
    insertList (&head, i ,i);
  printList (&head);
  printf ("\n");
  printf ("%d  ", findList (&head, 3));
  printf ("%d", sizeList (&head));
}
