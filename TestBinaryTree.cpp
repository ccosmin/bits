#include <string.h>
#include <stdlib.h>

#include "Testing.h"
#include "BinaryTree.h"

static int Comparator(const void* v1, const void* v2)
{
  int* vc1 = (int*)v1; 
  int* vc2 = (int*)v2; 
  return *vc1 < *vc2 ? -1 : (*vc1 == *vc2 ? 0 : 1);  
}

static void PrintElements(void* element)
{
  printf("%d ", *(int*)element);
}

static void FreeElement(void* element)
{
  free(element);
}

TEST(TestBinaryTree, TestInsertion)
{
  Tree* tree = NULL;
  int* element = (int*)malloc(sizeof(int));
  *element = 100;
  TreeInsert(&tree, element, NULL, Comparator);
  element = (int*)malloc(sizeof(int));
  *element = 50;
  TreeInsert(&tree, element, NULL, Comparator);
  element = (int*)malloc(sizeof(int));
  *element = 2000;
  TreeInsert(&tree, element, NULL, Comparator);
  printf("\n");
  TreePreOrder(tree, PrintElements);
  TreePreOrder(tree, FreeElement);
  TreeDestroy(tree);
}

TEST(TestBinaryTree, TestLimits)
{
  Tree* tree = NULL;
  int* element = (int*)malloc(sizeof(int));
  *element = 100;
  TreeInsert(&tree, element, NULL, Comparator);
  element = (int*)malloc(sizeof(int));
  *element = 50;
  TreeInsert(&tree, element, NULL, Comparator);
  element = (int*)malloc(sizeof(int));
  *element = 2000;
  TreeInsert(&tree, element, NULL, Comparator);
  EXPECT_EQ(50, *(int*)TreeMin(tree)->data);
  EXPECT_EQ(2000, *(int*)TreeMax(tree)->data);
  TreePreOrder(tree, FreeElement);
  TreeDestroy(tree);
}

TEST(TestBinaryTree, TestDelete)
{
  Tree* tree = NULL;
  int* element = (int*)malloc(sizeof(int));
  *element = 100;
  TreeInsert(&tree, element, NULL, Comparator);
  element = (int*)malloc(sizeof(int));
  *element = 50;
  TreeInsert(&tree, element, NULL, Comparator);
  element = (int*)malloc(sizeof(int));
  *element = 2000;
  TreeInsert(&tree, element, NULL, Comparator);
  int ielement = 50;
  EXPECT_TRUE(TreeSearch(tree, &ielement, Comparator)); 
  EXPECT_TRUE(TreeDelete(tree, &ielement, Comparator));
  TreePreOrder(tree, FreeElement);
  TreeDestroy(tree);
}

