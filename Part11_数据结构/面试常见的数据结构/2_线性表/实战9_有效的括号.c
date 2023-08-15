#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef char E;

typedef struct LNode
{
  E element;
  struct LNode *next;
} LNode;

void
initStack (LNode *head)
{
  head->next = NULL;
}

int
pushStack (LNode *head, E element)
{
  LNode *node = malloc (sizeof (LNode));
  if (node == NULL)
    return 0;
  node->element = element;
  LNode *tmp = head->next;
  head->next = node;
  node->next = tmp;
  return 1;
}

int
isEmpty (LNode *head)
{
  return head->next == NULL;
}

E
popStack (LNode *head)
{
  LNode *tmp = head->next;
  head->next = head->next->next;
  E e = tmp->element;
  free (tmp);
  return e;
}

bool
isValid (char *s)
{
  LNode head;
  initStack (&head);
  int i = 0;
  while (s[i] != '\0')
    {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        pushStack (&head, s[i]);
      else
        {
          if (isEmpty (&head))  // 如果栈被提前耗尽那么返回false
            return false;
          if (s[i] == ')' && popStack (&head) != '(')
            return false;
          if (s[i] == '}' && popStack (&head) != '{')
            return false;
          if (s[i] == ']' && popStack (&head) != '[')
            return false;
        }
      i++;
    }
  return isEmpty (&head);  // 如果栈里面还有东西那么返回false
}