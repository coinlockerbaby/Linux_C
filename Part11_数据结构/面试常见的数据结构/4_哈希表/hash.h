#ifndef __HASH_H__
#define __HASH_H__

#define N 15

typedef int datatype;
typedef struct LNode
{
  datatype key;
  datatype value;
  struct LNode *next;
} LNode;

typedef struct
{
  LNode data[N];

} hash;

hash *hash_create ();
int hash_insert (hash *HT, datatype key);
LNode *hash_search (hash *HT, datatype key);

#endif