#include <stdio.h>

struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNode *
removeDuplicateNodes (struct ListNode *head)
{
  if (head == NULL)
    return NULL;
  struct ListNode *node = head;
  while (node)
    {
      struct ListNode *p = node;
      while (p->next)
        {
          if (p->next->val == node->val)
            {
              p->next = p->next->next;  //  如果p的next与node的val一样 那么p的next连到下个节点
            }
          else
            {
              p = p->next;
            }
        }
      node = node->next;
    }
  return head;
}