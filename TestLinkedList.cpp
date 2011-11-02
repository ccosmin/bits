#include "Testing.h"
#include "LinkedList.h"

TEST(TestLinkedList, InitList)
{
  LinkedList* linkedList;
  LLInit(&linkedList);
  LLDestroy(linkedList);
}

TEST(TestLinkedList, InsertElement)
{
  LinkedList* linkedList;
  LLInit(&linkedList);
  int* element = (int*)malloc(sizeof(int));
  *element = 1;
  EXPECT_TRUE(LLInsert(linkedList, element));
  EXPECT_EQ(1, LLSize(linkedList));
  element = (int*)LLExtract(linkedList);
  EXPECT_EQ(1, *element);
  EXPECT_EQ(0, LLSize(linkedList));
  free(element);
  LLDestroy(linkedList);
}

TEST(TestLinkedList, InsertLotsOfElements)
{
  LinkedList* linkedList;
  LLInit(&linkedList);
  for ( int i = 0; i < 1000; ++i )
  {
    int* element = (int*)malloc(sizeof(int));
    *element = i;
    EXPECT_TRUE(LLInsert(linkedList, element));
  }
  EXPECT_EQ(1000, LLSize(linkedList));
  for ( int i = 0; i < 1000; ++i )
  {
    int* element = (int*)LLExtract(linkedList);
    EXPECT_EQ(1000 - i - 1, *element);
    free(element);
  }
  EXPECT_EQ(0, LLSize(linkedList));
  LLDestroy(linkedList);
}

TEST(TestLinkedList, ReverseList)
{
  LinkedList* linkedList;
  LLInit(&linkedList);
  for ( int i = 0; i < 1000; ++i )
  {
    int* element = (int*)malloc(sizeof(int));
    *element = i;
    EXPECT_TRUE(LLInsert(linkedList, element));
  }
  EXPECT_EQ(1000, LLSize(linkedList));
  LLReverse(linkedList);
  for ( int i = 0; i < 1000; ++i )
  {
    int* element = (int*)LLExtract(linkedList);
    EXPECT_EQ(i, *element);
    free(element);
  }
  EXPECT_EQ(0, LLSize(linkedList));
  LLDestroy(linkedList);
}

TEST(TestLinkedList, Splice)
{
  LinkedList* linkedList;
  LLInit(&linkedList);
  int* element = (int*)malloc(sizeof(int));
  *element = 1;
  EXPECT_TRUE(LLInsert(linkedList, element));
  element = (int*)malloc(sizeof(int));
  *element = 2;
  EXPECT_TRUE(LLInsert(linkedList, element));
  element = (int*)malloc(sizeof(int));
  *element = 3;
  EXPECT_TRUE(LLInsert(linkedList, element));
  LinkedList* spliced = LLSplice(linkedList, 1);
  EXPECT_EQ(2, LLSize(spliced));
  element = (int*)LLExtract(spliced);
  EXPECT_EQ(2, *element);
  free(element);
  element = (int*)LLExtract(spliced);
  EXPECT_EQ(1, *element);
  free(element);
  EXPECT_EQ(1, LLSize(linkedList));
  element = (int*)LLExtract(linkedList);
  EXPECT_EQ(3, *element);
  free(element);
  LLDestroy(linkedList);
  LLDestroy(spliced);
}

TEST(TestLinkedList, Clear)
{
  LinkedList* linkedList;
  LLInit(&linkedList);
  int* element = (int*)malloc(sizeof(int));
  *element = 1;
  EXPECT_TRUE(LLInsert(linkedList, element));
  EXPECT_EQ(1, LLSize(linkedList));
  LLClear(linkedList);
  EXPECT_EQ(0, LLSize(linkedList));
  free(element);
  LLDestroy(linkedList);
}

TEST(TestLinkedList, Copy)
{
  LinkedList* linkedList;
  LLInit(&linkedList);
  int* element = (int*)malloc(sizeof(int));
  *element = 1;
  EXPECT_TRUE(LLInsert(linkedList, element));
  EXPECT_EQ(1, LLSize(linkedList));
  LinkedList* copied;
  LLInit(&copied);
  LLCopy(copied, linkedList);
  EXPECT_EQ(1, LLSize(copied));
  free(element);
  LLDestroy(linkedList);
  LLDestroy(copied);
}

