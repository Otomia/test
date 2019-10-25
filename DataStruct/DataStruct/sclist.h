#pragma once
#ifndef _SCLIST_H_
#define _SCLIST_H_

#include "common.h"

typedef struct SCListNode
{
	DataType data;
	struct SCListNode *next;
}SCListNode;

typedef struct SCList
{
	SCListNode *first;
	SCListNode *last;
	size_t     size;
}SCList;

SCListNode* _Buynode(DataType x)
{
	SCListNode *s = (SCListNode*)malloc(sizeof(SCListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;

}
void SCListInit(SCList* plist);
void SCListPushBack(SCList *plist, DataType x);
void SCListShow(SCList *plist);
void SCListPushFront(SCList *plist, DataType x);
SCListNode* SCListFindByVal(SCList *plist, DataType key);
bool SCListEraseByVal(SCList *plist, DataType key);
size_t SCListLength(SCList *plist);
bool SCListInsertByVal(SCList *plist, DataType x);//未完成
void SCListClear(SCList *plist);
void SCListDestroy(SCList *plist);
void SCListReverse(SCList *plist);
void SCListSort(SCList *plist);

void SCListInit(SCList* plist)
{
	SCListNode *s = _Buynode(0);
	plist->first = plist->last = s;
	plist->last->next = plist->first;
	plist->size = 0;
}
void SCListShow(SCList *plist)
{
	assert(plist != NULL);
	SCListNode *p = plist->first->next;
	while (p != plist->first)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

void SCListPushBack(SCList *plist, DataType x)
{
	assert(plist != NULL);
	SCListNode *s = _Buynode(x);
	plist->last->next = s;
	plist->last = s;
	plist->last->next = plist->first;
	plist->size++;
}

void SCListPushFront(SCList *plist, DataType x)
{
	assert(plist != NULL);
	SCListNode *s = _Buynode(x);
	s->next = plist->first->next;
	plist->first->next = s;
	if (plist->size == 0)
		plist->last = s;
	plist->size++;
}

SCListNode* SCListFindByVal(SCList *plist, DataType key)
{
	assert(plist != NULL);
	SCListNode *p = plist->first->next;
	while (p != plist->first && p->data != key)
		p = p->next;
	return p;
}

bool SCListEraseByVal(SCList *plist, DataType key)
{
	assert(plist != NULL);
	SCListNode *p,*q;
	p = SCListFindByVal(plist, key);
	if (p == NULL)
		return false;
	q = plist->first;
	while(q->next != p)
		q = q->next;
	if (plist->last == p)
	{
		plist->last = q;
		plist->last->next = plist->first;
	}
	q->next = p->next;
	free(p);
	plist->size--;
	return true;
}

size_t SCListLength(SCList *plist)
{
	return plist->size;
}

//要求列表有序
bool SCListInsertByVal(SCList *plist, DataType x)
{
	assert(plist != NULL);
	SCListNode *p, *s;
	p = plist->first;
	s = _Buynode(x);
	while (p->next != plist->first && p->next->data < x)
		p = p->next;
	if (p->next == plist->first)
	{
		plist->last = s;
		plist->last->next = plist->first;
	}
	else
		s->next = p->next;
	p->next = s;

	plist->size++;
	return true;
}

void SCListReverse(SCList *plist)
{
	assert(plist != NULL);
	SCListNode *p,*q;
	p = plist->first->next;
	if (p->next == plist->first)
		return;
	q = p->next;
	plist->last = p;
	plist->last->next = plist->first;
	while (q != plist->first)
	{
		p = q;
		q = q->next;
		p->next = plist->first->next;
		plist->first->next = p;
	}
}

void SCListSort(SCList *plist)
{
	assert(plist != NULL);
	SCListNode *p, *q;
	p = plist->first->next;
	
}

void SCListClear(SCList *plist)
{
	SCListNode *p = plist->first->next;
	if (p == NULL)
		return;
	while (p != NULL)
	{
		plist->first->next = p->next;
		free(p);
		p = plist->first->next;
	}
	plist->first = plist->last;
	plist->last->next = plist->first;
	plist->size = 0;
}

void SCListDestroy(SCList *plist)
{
	SCListClear(plist);
	free(plist->first);
	plist->first = plist->last = NULL;
	plist->size = 0;
}
#endif