#include <stdlib.h>
#include <stdio.h>
#include "BinaryTree.h"

Tree* TreeInit(Tree** tree)
{
  *tree = (Tree*)malloc(sizeof(Tree));
  if ( *tree )
  {
    (*tree)->parent = NULL;
    (*tree)->left = NULL;
    (*tree)->right = NULL;
    (*tree)->data = NULL;
  }
  return *tree;
}

Tree* TreeInsert(Tree** tree, void* element, Tree* parent, int (*comp)(const void*, const void*))
{
  if ( !*tree )
  {
    TreeInit(tree);
    (*tree)->parent = parent;
    (*tree)->data = element;
    return *tree;
  }
  else
  {
    if ( (*comp)(element, (*tree)->data) < 0 )
    {
      return TreeInsert(&(*tree)->left, element, *tree, comp);
    }
    else
    {
      return TreeInsert(&(*tree)->right, element, *tree, comp);
    }
  }
}

void TreePreOrder(Tree* tree, void (*func)(void*))
{
  (*func)(tree->data);
  if ( tree->left )
  {
    TreePreOrder(tree->left, func);
  }
  if ( tree->right )
  {
    TreePreOrder(tree->right, func);
  }
}

void TreeInOrder(Tree* tree, void (*func)(void*))
{
  if ( tree->left )
  {
    TreePreOrder(tree->left, func);
  }
  (*func)(tree->data);
  if ( tree->right )
  {
    TreePreOrder(tree->right, func);
  }
}

void TreePostOrder(Tree* tree, void (*func)(void*))
{
  if ( tree->left )
  {
    TreePreOrder(tree->left, func);
  }
  if ( tree->right )
  {
    TreePreOrder(tree->right, func);
  }
  (*func)(tree->data);
}

void TreeDestroy(Tree* tree)
{
  if ( tree->left )
  {
    printf("left ");
    TreeDestroy(tree->left);
    tree->left = NULL;
  }
  if ( tree->right )
  {
    printf("right ");
    TreeDestroy(tree->right);
    tree->right = NULL;
  }
  free(tree);
}

