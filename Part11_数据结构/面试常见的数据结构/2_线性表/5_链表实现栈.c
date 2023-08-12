#include <stdio.h>
#include <stdlib.h>

typedef int E;
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

void
printStack (LNode *head)
{
  while (head->next)
    {
      head = head->next;
      printf ("%d ", head->element);
    }
}

int
main ()
{
  LNode head;
  initStack (&head);
  for (int i = 1; i <= 5; i++)
    {
      pushStack (&head, i * 10);
    }
  printStack (&head);
  printf ("\n");
  while (!isEmpty(&head))
    {
      printf ("%d ", popStack (&head));
    }
}