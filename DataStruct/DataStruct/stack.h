#pragma once
#include"common.h"



struct BinTreeNode;
#define StackDataType struct BinTreeNode*

#define DEFAULT_STACK_SIZE 100
typedef struct Stack
{
	StackDataType *base;
	size_t capacity;
	size_t top;
}Stack;

void StackInit(Stack *pst, size_t sz);
void StackPush(Stack *pst, StackDataType x);
bool StackIsFull(Stack *pst)
{return pst->top >= pst->capacity;}
bool StackIsEmpty(Stack *pst)
{return pst->top == 0;}
void StackPop(Stack *pst);
void StackShow(Stack *pst);
StackDataType StackTop(Stack *pst);
void StackClear(Stack *pst);
void StackDestroy(Stack *pst);

void StackInit(Stack *pst, size_t sz)
{
	pst->capacity = sz > DEFAULT_STACK_SIZE ? sz : DEFAULT_STACK_SIZE;
	pst->base = (StackDataType*)malloc(sizeof(StackDataType)*pst->capacity);
	assert(pst->base != NULL);
	pst->top = 0;
}

void StackPush(Stack *pst, StackDataType x)
{
	if (StackIsFull(pst))
	{
		printf("栈已满,不能入栈.");
		return;
	}
	pst->base[pst->top++] = x;
}

void StackPop(Stack *pst)
{
	if (StackIsEmpty(pst))
	{
		printf("栈为空.");
		return;
	}
	pst->top--;
}

void StackShow(Stack *pst)
{
	for (int i = pst->top - 1; i >= 0; --i)
	{
		printf("%d ", pst->base[i]);
	}
	printf("\n");

}

StackDataType StackTop(Stack *pst)
{
	if (StackIsEmpty(pst))
	{
		printf("栈已空");
		return 0;
	}
	return pst->base[pst->top-1];
}

void StackClear(Stack *pst)
{
	pst->top = 0;
}

void StackDestroy(Stack *pst)
{
	free(pst->base);
	pst->base = NULL;
	pst->top = pst->capacity = 0;
}