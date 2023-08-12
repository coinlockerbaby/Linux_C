#include <stdio.h>
struct ListNode
{
  int val;
  struct ListNode *next;
};

// 先跑一次记住有多少个节点
struct ListNode *
getKthFromEnd (struct ListNode *head, int k)
{
  if (head == NULL)
    return NULL;
  int count = 0;
  struct ListNode *node = head;
  while (node)
    {
      count ++;
      node = node->next;
    }
  for (int i = 1; i < count; i++)
    {
      head = head->next;
    }
  return head;
}

// 快慢指针法

// struct ListNode *
// getKthFromEnd (struct ListNode *head, int k)
// {
//   struct ListNode *fast = head;
//   struct ListNode *slow = head;
//   for (int i = 0; i < k; i++)
//     {
//       fast = fast->next;
//     }
//   while (fast)
//     {
//       fast = fast->next;
//       slow = slow->next;
//     }
//   return slow;
// }