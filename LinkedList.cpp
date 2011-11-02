#include <stdlib.h>
#include "LinkedList.h"

LinkedList* LLInit(LinkedList** list)
{
  *list = (LinkedList*)malloc(sizeof(LinkedList));
  if ( *list ) 
  {
    (*list)->n = 0;
    (*list)->head = NULL;
  }
  return *list;
}

Node* LLInsert(LinkedList* list, void* element)
{
  Node* node = (Node*)malloc(sizeof(Node));
  if ( node )
  {
    node->data = element;
    node->next = list->head;
    list->head = node;
    ++list->n;
  }
  return node;
}

void* LLExtract(LinkedList* list)
{
  if ( list->n > 0 )
  {
    Node* node = list->head;
    list->head = node->next;
    --list->n;
    return node->data;
  }
  return NULL;
}

int LLSize(LinkedList* list)
{
  return list->n;
}

void LLDestroy(LinkedList* list)
{
  Node* p = list->head;
  while ( p )
  {
    Node* tmp = p;
    p = tmp->next;
    free(tmp);
  }
  free(list);
}

void LLReverse(LinkedList* list)
{
  Node* p = NULL;
  Node* n = list->head;
  while ( n )
  {
    Node* tmp = n->next;
    n->next = p;
    p = n;
    n = tmp;
  }
  list->head = p;
}

LinkedList* LLSplice(LinkedList* list, int no)
{
  int initialSize = list->n;
  Node* prev = NULL;
  Node* p = list->head; 
  int i = 0;
  while ( i < no && p )
  {
    prev = p;
    p = p->next;
    ++i;
  }
  LinkedList* ret = NULL;
  LLInit(&ret);
  list->n = i;
  if ( prev )
    prev->next = NULL;
  ret->n = initialSize - i;
  ret->head = p;
  return ret;
}

void LLCopy(LinkedList* dst, LinkedList* src)
{
  LLClear(dst);
  for ( Node* p = src->head; p; p = p->next )
  {
    LLInsert(dst, p->data);
  }
}

void LLClear(LinkedList* list)
{
  Node* p = list->head;
  while ( p )
  {
    Node* next = p->next;
    free(p);
    p = next;
  }
  list->head = NULL;
  list->n = 0;
}

void LLOnEach(LinkedList* list, void (*func)(void*))
{
  Node* p = list->head;
  while ( p )
  {
    (*func)(p->data);
    p = p->next;
  }
}

