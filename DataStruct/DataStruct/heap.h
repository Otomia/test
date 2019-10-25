#pragma once
#include"common.h"

#define DEFAULT_HEAP_SIZE 15

typedef struct Heap
{
	DataType *base;
	size_t capacity;
	size_t size;
}Heap;

bool HeapIsFull(Heap *php)
{
	return php->size >= php->capacity;
}
bool HeapIsEmpty(Heap *php)
{
	return php->size == 0;
}

void HeapInit(Heap *php,int sz);


void HeapInit(Heap *php, int sz)
{
	php->capacity = sz > DEFAULT_HEAP_SIZE ? sz : DEFAULT_HEAP_SIZE;
	php->base = (DataType*)malloc(sizeof(DataType)*php->capacity);
	php->size = 0;

}