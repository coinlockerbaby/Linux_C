#include <stdio.h>

struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNode *
reverseList (struct ListNode *head)
{
  struct ListNode *newhead = NULL, *tmp;
  while (head)
    {
      tmp = head->next;
      head->next = newhead;
      newhead = head;
      head = tmp;
    }
}