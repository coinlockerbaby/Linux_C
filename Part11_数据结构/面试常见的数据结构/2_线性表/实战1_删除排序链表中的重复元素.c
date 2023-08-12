#include <stdio.h>

struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNode *
deleteDuplicates (struct ListNode *head)
{
  if (head == NULL)
    return NULL;
  struct ListNode *node = head;
  while (node->next != NULL)
    {
      if (node->val == node->next->val)
        {
          struct ListNode *tmp = node->next;
          node->next = node->next->next;
          free (tmp);
        }
      else
        {
          node = node->next;
        }
    }
  return head;
}