#include "Testing.h"
#include "LinkedList.h"
#include "MergeSort.h"
#include <string.h>
#include <stdio.h>

void LLInsertArray(LinkedList* list, const char* elements[])
{
  for ( const char** p = elements; *p; ++p )
  {
    LLInsert(list, (void*)*p);
  }
}

int Comparator(void* v1, void* v2)
{
  return strcmp((char*)v1, (char*)v2);
}

void StringPrinter(void* v)
{
  printf("%s ", (const char*)v);
}

TEST(TestMergeSort, TestSort)
{
  LinkedList* linkedList;
  LLInit(&linkedList);
  const char* a[] = { "1", "3", "5", "6", "2", NULL };
  LLInsertArray(linkedList, a);
  MergeSort(linkedList, Comparator);
  LLOnEach(linkedList, StringPrinter);
  LLDestroy(linkedList);
}

