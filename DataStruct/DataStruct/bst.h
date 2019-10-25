#pragma once
#include"common.h"

//二叉查找树
#define BSTDataType int

typedef struct BSTNode
{
	BSTDataType data;
	struct BSTNode *leftChild;
	struct BSTNode *rightChild;
}BSTNode;

typedef struct BSTree
{
	BSTNode *root;
}BSTree;

void BSTInit(BSTree *pbst);
bool BSTreeInsert(BSTree *pbst, BSTDataType x);
bool BSTreeInsert_1(BSTNode **t, BSTDataType x);

BSTNode* BSTreeMin(BSTree *pbst);
BSTNode* BSTreeMin_1(BSTNode *t);
BSTNode* BSTreeMax(BSTree *pbst);
BSTNode* BSTreeMax_1(BSTNode *t);

BSTNode* BSTFind(BSTree *pbst,BSTDataType key);
BSTNode* BSTFind_1(BSTNode *t, BSTDataType key);

bool BSTErase(BSTree *pbst, BSTDataType key);
bool BSTErase_1(BSTNode **t, BSTDataType key);

void BSTInit(BSTree *pbst)
{
	pbst->root = NULL;
}

bool BSTreeInsert(BSTree *pbst, BSTDataType x)
{
	return BSTreeInsert_1(&pbst->root, x);
}
bool BSTreeInsert_1(BSTNode **t, BSTDataType x)
{
	if (*t == NULL)//引发异常
	{
		*t = (BSTNode*)malloc(sizeof(BSTNode));
		(*t)->data = x;
		(*t)->leftChild = NULL;
		(*t)->rightChild = NULL;
		return true;
	}
	else if (x < (*t)->data)
	{
		BSTreeInsert_1(&(*t)->leftChild, x);
	}
	else if (x > (*t)->data)
	{
		BSTreeInsert_1(&(*t)->rightChild, x);
	}
	else
		return false;
}

BSTNode* BSTreeMin(BSTree *pbst)
{
	return BSTreeMin_1(pbst->root);
}
BSTNode* BSTreeMin_1(BSTNode *t)
{
	if (t == NULL)
		return t;
	while (t->leftChild != NULL)
		t = t->leftChild;
	return t;
}
BSTNode* BSTreeMax(BSTree *pbst)
{
	return BSTreeMax_1(pbst->root);
}
BSTNode* BSTreeMax_1(BSTNode *t)
{
	if (t == NULL)
		return t;
	while (t->rightChild != NULL)
		t = t->rightChild;
	return t;
}

BSTNode* BSTFind(BSTree *pbst, BSTDataType key)
{
	return BSTFind_1(pbst->root, key);
}

BSTNode* BSTFind_1(BSTNode *t, BSTDataType key)
{
	if (t == NULL)
		return NULL;
	if (t->data == key)
		return t;
	else if (t->data < key)
		BSTFind_1(t->rightChild, key);
	else if (t->data > key)
		BSTFind_1(t->leftChild, key);
}

bool BSTErase(BSTree *pbst, BSTDataType key)
{
	return BSTErase_1(&pbst->root, key);
}
bool BSTErase_1(BSTNode **t, BSTDataType key)
{
	if (*t == NULL)
		return false;
	if ((*t)->data > key)
		BSTErase_1(&(*t)->leftChild, key);
	if ((*t)->data < key)
		BSTErase_1(&(*t)->rightChild, key);
	else
	{
		BSTNode *p = *t;
		if (p->leftChild == NULL && p->rightChild == NULL)
		{
			free(p);
			*t = NULL;
		}
		else if (p->leftChild != NULL && p->rightChild == NULL)
		{
			*t = (*t)->leftChild;
			free(p);
		}
		else if (p->leftChild == NULL && p->rightChild != NULL)
		{
			*t = (*t)->rightChild;
			free(p);
		}
		else//?
		{
			BSTNode *q = p->leftChild;
			while (q->rightChild != NULL)
				q = q->rightChild;
			p->data = q->data;
			BSTErase_1(&(*t)->leftChild, p->data);
		}
	}
	return true;
}

