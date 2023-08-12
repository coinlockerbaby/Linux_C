#include <stdio.h>
struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNode *
getIntersectionNode (struct ListNode *headA, struct ListNode *headB)
{
  struct ListNode *p = headA, *q = headB;
  while (p != q)
    {
      if (p == NULL)
        p = headB;
      else
        p = p->next;

      if (q == NULL)
        q = headA;
      else
        q = q->next;
    }
  return q;
}