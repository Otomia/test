#pragma once
#include"common.h"


typedef struct DCListNode
{
	DataType data;
	struct DCListNode *prev;
	struct DCListNode *next;
}DCListNode;

typedef struct DCList
{
	DCListNode *first;
	DCListNode *last;
	size_t    size;
}DCList;

DCListNode* _Buynode(DataType x)
{
	DCListNode *s = (DCListNode*)malloc(sizeof(DCListNode));
	assert(s != NULL);
	s->data = x;
	s->prev = NULL;
	s->next = NULL;
	return s;
}
void DCListInit(DCList *plist);

void DCListInit(DCList *plist)
{
	DCListNode *s = _Buynode(0);
	plist->first = plist->last = s;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;
	plist->size == 0;
}