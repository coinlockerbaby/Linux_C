#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

int
main ()
{
  hash *HT;
  int key;
  int data[] = { 23, 34, 14, 38, 46, 16, 68, 15, 7, 31, 26 };
  if ((HT = hash_create ()) == NULL)
    return -1;
  for (int i = 0; i < sizeof (data) / sizeof (int); i++)
    {
      hash_insert (HT, data[i]);
    }
  printf ("input :");
  scanf ("%d", &key);
  LNode *r = hash_search (HT, key);
  if (r == NULL)
    printf ("not found\n");
  else
    printf ("found: %d %d\n", key, r->key);
}