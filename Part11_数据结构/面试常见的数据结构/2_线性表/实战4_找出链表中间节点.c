#include <stdio.h>
struct ListNode
{
  int val;
  struct ListNode *next;
};
// 快慢指针法
// 慢指针走一步 快指针走两步

struct ListNode *
middleNode (struct ListNode *head)
{
  struct ListNode *fast = head;
  struct ListNode *slow = head;
  while (fast->next)
    {
      fast = fast->next->next;
      slow = slow->next;
    }
  return slow;
}