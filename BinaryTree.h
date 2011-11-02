#ifndef BINARYTREE_H
#define BINARYTREE_H

struct Tree
{
  void* data;
  Tree* parent;
  Tree* left;
  Tree* right;
};

Tree* TreeInit(Tree** tree);
Tree* TreeInsert(Tree** tree, void* element, Tree* parent, int (*comp)(const void*, const void*));
void TreePreOrder(Tree* tree, void (*func)(void*));
void TreeInOrder(Tree* tree, void (*func)(void*));
void TreePostOrder(Tree* tree, void (*func)(void*));
void TreeDestroy(Tree* tree);

#endif

