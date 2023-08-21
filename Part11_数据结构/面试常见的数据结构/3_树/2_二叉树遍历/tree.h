#ifndef __TREE_H__
#define __TREE_H__

#include <stdio.h>
#include <stdlib.h>

typedef char E;

typedef struct TreeNode
{
  E element;
  struct TreeNode *left, *right;
} TreeNode;

TreeNode *tree_create ();

void preorder (TreeNode *head);

void inorder (TreeNode *head);

void postorder (TreeNode *head);

#endif