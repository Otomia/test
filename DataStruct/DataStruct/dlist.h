#pragma once
#include"common.h"


typedef struct DListNode
{
	DataType data;
	struct DListNode *prev;
	struct DListNode *next;
}DListNode;

typedef struct DList
{
	DListNode *first;
	DListNode *last;
	size_t    size;
}DList;


DListNode* _Buynode(DataType x)
{
	DListNode *s = (DListNode*)malloc(sizeof(DListNode));
	assert(s != NULL);
	s->data = x;
	s->prev = NULL;
	s->next = NULL;
	return s;
}

void DListInit(DList *plist);
void DListShow(DList *plist);
void DListPushBack(DList *plist, DataType x);
void DListPushFront(DList *plist, DataType x);
DListNode* DListFindByVal(DList *plist, DataType key);
bool DListEraseByVal(DList *plist, DataType key);
size_t DListLength(DList *plist);

/*

bool DListInsertByVal(DList *plist, DataType x);//Î´Íê³É
void DListClear(DList *plist);
void DListDestroy(DList *plist);
void DListReverse(DList *plist);
void DListSort(DList *plist);
*/

void DListInit(DList *plist)
{
	DListNode *s = _Buynode(0);
	plist->first = plist->last = s;
	plist->size = 0;
}

void DListShow(DList *plist)
{
	assert(plist != NULL);
	DListNode *p = plist->first->next;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

void DListPushBack(DList *plist, DataType x)
{
	assert(plist != NULL);
	DListNode *s = _Buynode(x);
	plist->last->next = s;
	s->prev = plist->last;
	plist->last = s;
	plist->size++;
}

void DListPushFront(DList *plist, DataType x)
{
	assert(plist != NULL);
	DListNode *s = _Buynode(x);
	
	s->next = plist->first->next;
	s->next->prev = s;
	s->prev = plist->first;
	plist->first->next = s;
	if (plist->size == 0)
		plist->last = s;
	plist->size++;

}

DListNode* DListFindByVal(DList *plist, DataType key)
{
	assert(plist != NULL);
	DListNode *p = plist->first->next;
	while (p != NULL && p->data != key)
		p = p->next;
	return p;
}

bool DListEraseByVal(DList *plist, DataType key)
{
	assert(plist != NULL);
	DListNode *p = DListFindByVal(plist, key);
	if (p == NULL)
		return false;
	if (p==plist->last)
		plist->last = p->prev;
	p->prev->next = p->next;
	p->next->prev = p->prev;

	free(p);
	plist->size--;

	return true;
}
size_t DListLength(DList *plist)
{
	return plist->size;
}

