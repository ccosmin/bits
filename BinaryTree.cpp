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

Tree* TreeMin(Tree* tree)
{
  if ( tree && tree->left )
    return TreeMin(tree->left);
  else
    return tree;
}

Tree* TreeMax(Tree* tree)
{
  if ( tree && tree->right )
    return TreeMax(tree->right);
  else
    return tree;
}

Tree* TreeSearch(Tree* tree, void* element, int (*comp)(const void*, const void*))
{
  int res = (*comp)(element, tree->data); 
  if ( res < 0 )
    return tree->left ? TreeSearch(tree->left, element, comp) : NULL;
  else if ( res > 0 )
    return tree->right ? TreeSearch(tree->right, element, comp) : NULL;
  else
    return tree;
}

static void TreeDoDelete(Tree* toDelete)
{
  if ( toDelete->left && toDelete->right )
  {
    Tree* minTree = TreeMin(toDelete->right);
    toDelete->data = minTree->data;
    TreeDoDelete(minTree);
  }
  else if ( toDelete->left )
  {
    toDelete->data = toDelete->left->data;
    TreeDestroy(toDelete->left);
  }
  else if ( toDelete->right )
  {
    toDelete->data = toDelete->right->data;
    TreeDestroy(toDelete->right);
  }
  else
  {
    if ( toDelete->parent )
    {
      if ( toDelete->parent->left == toDelete )
        toDelete->parent->left = NULL;
      else if ( toDelete->parent->right == toDelete )
        toDelete->parent->right = NULL;
    }
    TreeDestroy(toDelete);
  }
}

int TreeDelete(Tree* tree, void* element, int (*comp)(const void*, const void*))
{
  Tree* toDelete = TreeSearch(tree, element, comp);
  if ( toDelete )
  {
    TreeDoDelete(toDelete);
    return 1;
  }
  return 0;
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

