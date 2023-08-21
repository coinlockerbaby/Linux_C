#include <stdio.h>
#include <stdlib.h>

typedef char E;

typedef struct TreeNode
{
  E element;
  struct TreeNode *left, *right;
} TreeNode;

int
main ()
{
  TreeNode *a = malloc (sizeof (TreeNode));
  TreeNode *b = malloc (sizeof (TreeNode));
  TreeNode *c = malloc (sizeof (TreeNode));
  TreeNode *d = malloc (sizeof (TreeNode));
  TreeNode *e = malloc (sizeof (TreeNode));
  TreeNode *f = malloc (sizeof (TreeNode));

  a->element = 'A';
  b->element = 'B';
  c->element = 'C';
  d->element = 'D';
  e->element = 'E';
  f->element = 'F';

  a->left = b;  // A的左孩子是B
  a->right = c; // A的右孩子是C

  b->left = d;  // B的左孩子是D
  b->right = e; // B的右孩子是E

  c->right = f;
  c->right = NULL;
  d->left = d->right = NULL;
  e->left = e->right = NULL;
  f->left = f->right = NULL;
}
