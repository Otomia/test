#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
/*
#ifndef _SLIST_H_
#define _SLIST_H_
#include"common.h"
typedef struct SListNode
{
	DataType data;
	struct SListNode* next;
}SListNode;

typedef struct SList
{
	SListNode* first;
	SListNode* last;
	size_t     size;
}SList;

SListNode* _Buynode(DataType x)
{
	SListNode *s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;
}

void SListInit(SList *plist);
void SListPushBack(SList *plist, DataType x);
void SListPushFront(SList *plist, DataType x);
void SListShow(SList *plist);
SListNode* SListFindByVal(SList *plist, DataType key);
bool SListEraseByVal(SList *plist, DataType key);
int SListLength(SList *plist);
bool SListInsertByVal(SList *plist, DataType x);


void SListClear(SList *plist);
void SListReverse(SList *plist);
void SListDestroy(SList *plist);
void SListInit(SList *plist)
{
	SListNode *s = _Buynode(0);
	plist->first = plist->last = s;
	plist->size = 0;
}
void SListPushBack(SList *plist, DataType x)
{
	assert(plist != NULL);
	SListNode *s = _Buynode(x);
	plist->last->next = s;
	plist->last = s;
	plist->size++;
}

void SListPushFront(SList* plist, DataType x)
{
	assert(plist != NULL);
	SListNode *s = _Buynode(x);
	if (plist->size == 0)
	{
		plist->last = s;
	}
	s->next = plist->first->next;
	plist->first->next = s;
	plist->size++;
}

void SListShow(SList *plist)
{
	SListNode *p = plist->first->next;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}
//按值查找
SListNode* SListFindByVal(SList *plist, DataType key)
{
	assert(plist != NULL);
	SListNode *p = plist->first->next;
	while (p != NULL && p->data != key)
		p = p->next;
	return p;
}

bool SListEraseByVal(SList *plist, DataType key)
{
	assert(plist != NULL);
	SListNode *p,*q;
	p = SListFindByVal(plist, key);

	if (p == NULL)
		return false;
	q = plist->first;
	while (q->next != p)
		q = q->next;
	if (p == plist->last)
		plist->last = q;
	q->next = p->next;
	free(p);

	plist->size--;
	return true;
}
int SListLength(SList *plist)
{
	return plist->size;
}
//要求链表有序
bool SListInsertByVal(SList *plist, DataType x)
{
	assert(plist);
	SListNode *s = _Buynode(x);

	SListNode *p = plist->first;
	while (p->next != NULL && p->next->data < x)
		p = p->next;
	if (p->next == NULL)//尾部插入
		plist->last = s;
	else
		s->next = p->next;
	p->next = s;

	plist->size++;
	return true;
}

void SListClear(SList *plist)
{
	SListNode *p = plist->first->next;
	if (plist->size == 0)
		return;

	while (p != NULL)
	{
		plist->first->next = p->next;
		free(p);
		p = plist->first->next;
	}

	plist->last = plist->first;
	plist->size = 0;
}
void SListReverse(SList *plist)
{
	SListNode *p, *q;
	p = plist->first->next;
	q = p->next;
	plist->last = p;
	plist->last->next = NULL;

	while (q != NULL)
	{
		p = q;
		q = q->next;
		p->next = plist->first->next;
		plist->first->next = p;
	}
}
void SListDestroy(SList *plist)
{
	SListClear(plist);
	free(plist->first);
	plist->first = plist->last = NULL;
	plist->size = 0;
}
#endif 
*/