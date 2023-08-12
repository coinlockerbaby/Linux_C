#include <stdio.h>

struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNode *
rotateRight (struct ListNode *head, int k)
{
  if (head == NULL)
    return 0;
  struct ListNode *node = head;
  // 遍历到最后一个节点
  int count = 1;
  while (node->next)
    {
      node = node->next;
      count++;
    }
  node->next = head; //  先变成环形链表
  node = head;
  for (int i = 1; i < ((count - k) % count); i++) // 遍历到开头的前驱
    {
      node = node->next;
    }
  head = node->next;
  node->next = NULL; // 断开环形链表
  return head;
}
