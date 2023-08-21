#include "tree.h"

TreeNode *
tree_create ()
{
  E element;
  TreeNode *node;
  scanf ("%c", &element);
  if (element == '#')
    return NULL;
  if ((node = malloc (sizeof (TreeNode))) == NULL)
    {
      printf ("malloc failed\n");
      return NULL;
    }
  node->element = element;
  node->left = tree_create ();
  node->right = tree_create ();
  return node;
}

// 先序遍历
void
preorder (TreeNode *head)
{
  if (head == NULL)
    return;
  printf ("%c", head->element);
  preorder (head->left);
  preorder (head->right);
}

// 中序遍历
void
inorder (TreeNode *head)
{
  if (head == NULL)
    return;
  inorder (head->left);
  printf ("%c", head->element);
  inorder (head->right);
}

// 后序遍历
void
postorder (TreeNode *head)
{
  if (head == NULL)
    return;
  postorder (head->left);
  postorder (head->right);
  printf ("%c", head->element);
}

int
main ()
{
  TreeNode *head;
  if ((head =  tree_create()) == NULL)
    return -1;
  preorder (head);
}