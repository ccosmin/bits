#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

struct Node
{
	void* data;
	Node* next;
};

struct LinkedList
{
	Node* head;
	int n;
};

LinkedList* LLInit(LinkedList** list);
Node* LLInsert(LinkedList* list, void* element);
void* LLExtract(LinkedList* list);
int LLSize(LinkedList* list);
void LLDestroy(LinkedList* list);
void LLReverse(LinkedList* list);
LinkedList* LLSplice(LinkedList* list, int no);
void LLCopy(LinkedList* dst, LinkedList* src);
void LLClear(LinkedList* list);
void LLOnEach(LinkedList* list, void (*func)(void*));

#endif

