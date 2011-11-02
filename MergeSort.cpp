#include <stdlib.h>
#include "MergeSort.h"
#include "LinkedList.h"

static void Combine(LinkedList* l1, LinkedList* l2, int (*comparator)(void* left, void* right))
{
  LinkedList* ret = NULL;
  LLInit(&ret);
  Node* p1 = l1->head;
  Node* p2 = l2->head;
  while ( p1 && p2 )
  {
    int cres = (*comparator)(p1->data, p2->data);
    if ( cres < 0 )
    {
      LLInsert(ret, p1->data);
      p1 = p1->next;
    }
    else if ( !cres )
    {
      LLInsert(ret, p1->data);
      LLInsert(ret, p2->data);
      p1 = p1->next;
      p2 = p2->next;
    } 
    else
    {
      LLInsert(ret, p2->data);
      p2 = p2->next;
    }
  }
  while ( p1 )
  {
      LLInsert(ret, p1->data);
      p1 = p1->next;
  }
  while ( p2 )
  {
      LLInsert(ret, p2->data);
      p2 = p2->next;
  }
  LLCopy(l1, ret);
  LLDestroy(ret);
}

void MergeSort(LinkedList* list, int (*comparator)(void* left, void* right))
{
  int size = LLSize(list);
  if ( size > 1 )
  {
    int middle = size / 2;
    LinkedList* spliced = LLSplice(list, middle);
    MergeSort(list, comparator);
    MergeSort(spliced, comparator);
    Combine(list, spliced, comparator);
    LLDestroy(spliced);
  }
}

