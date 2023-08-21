#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

hash *
hash_create ()
{
  hash *HT;
  if ((HT = (hash *)malloc (sizeof (hash))) == NULL)
    {
      printf ("malloc failed!\n");
      return NULL;
    }
  memset (HT, 0, sizeof (hash));
  return HT;
}
int
hash_insert (hash *HT, datatype key)
{
  LNode *p, *q;
  if (HT == NULL)
    {
      printf ("HT is null\n");
      return -1;
    }
  if ((p = (LNode *)malloc (sizeof (LNode))) == NULL)
    {
      printf ("malloc failed\n");
      return -1;
    }
  p->key = key;
  p->value = key % N;
  p->next = NULL;

  q = &(HT->data[key % N]);
  while (
      q->next
      && q->next->key
             < p->key) // 如果在已有链表中找到比插入的key小的那么继续往后遍历
    q = q->next;
  p->next = q->next;
  q->next = p;
  return 0;
}
LNode *
hash_search (hash *HT, datatype key)
{
  LNode *p;
  if (HT == NULL)
    {
      printf ("HT is null!\n");
      return NULL;
    }
  p = &(HT->data[key % N]);
  while (p->next && p->next->key != key)
    p = p->next;
  if (p->next == NULL) // 如果没找到
    return NULL;
  else
    {
      printf ("found\n");
      return p->next;
    }
}