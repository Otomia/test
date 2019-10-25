#pragma once
#include"common.h"

struct BinTreeNode;
#define QueueDataType struct BinTreeNode*

typedef struct Queue
{
	QueueDataType *base;
	size_t capacity;
	size_t front;
	size_t tail;
}Queue;

#define DEFAULT_QUEUE_SIZE 8


bool QueueIsEmpty(Queue *q)
{
	return q->front == q->tail;
}
bool QueueIsFull(Queue *q)
{
	return q->tail == q->capacity;
}
void QueueInit(Queue *q, int sz);
void QueuePush(Queue *q, QueueDataType x);
void QueuePop(Queue *q);
QueueDataType QueueFront(Queue *q);

void QueueInit(Queue *q, int sz)
{
	q->capacity = sz > DEFAULT_QUEUE_SIZE ? sz : DEFAULT_QUEUE_SIZE;
	q->base = (QueueDataType*)malloc(sizeof(QueueDataType)*q->capacity);
	assert(q->base != NULL);
	q->front = q->tail = 0;
}

void QueuePush(Queue *q, QueueDataType x)
{
	if (QueueIsFull(q))
	{
		printf("队列已满，不能入队.");
		return;
	}
	q->base[q->tail++] = x;
}
void QueuePop(Queue *q)
{
	if (QueueIsEmpty(q))
	{
		printf("队列已空，不能出队.");
		return;
	}
	q->front++;
}
QueueDataType QueueFront(Queue *q)
{
	if (QueueIsEmpty(q))
	{
		printf("队列已空，不能取队头元素.");
		return 0;
	}
	return q->base[q->front];
}



#if 0
typedef struct Queue
{
	DataType *base;
	size_t capacity;
	size_t front;
	size_t tail;
}Queue;

#define DEFAULT_QUEUE_SIZE 8


bool QueueIsEmpty(Queue *q)
{return q->front == q->tail;}
bool QueueIsFull(Queue *q)
{return q->tail == q->capacity;}
void QueueInit(Queue *q,int sz);
void QueueShow(Queue *q);
void QueuePush(Queue *q, DataType x);
void QueuePop(Queue *q);
DataType QueueFront(Queue *q);
void QueueInit(Queue *q,int sz)
{
	q->capacity = sz > DEFAULT_QUEUE_SIZE ? sz : DEFAULT_QUEUE_SIZE;
	q->base = (DataType*)malloc(sizeof(DataType)*q->capacity);
	assert(q->base != NULL);
	q->front = q->tail = 0;
}

void QueuePush(Queue *q, DataType x)
{
	if (QueueIsFull(q))
	{
		printf("队列已满，不能入队.");
		return;
	}
	q->base[q->tail++] = x;
}
void QueuePop(Queue *q)
{
	if (QueueIsEmpty(q))
	{
		printf("队列已空，不能出队.");
		return;
	}
	q->front++;
}
DataType QueueFront(Queue *q)
{
	if (QueueIsEmpty(q))
	{
		printf("队列已空，不能取队头元素.");
		return 0;
	}
	return q->base[q->front];
}

void QueueShow(Queue *q)
{
	for (int i = q->front; i < q->tail; i++)
	{
		printf("%d ", q->base[i]);
	}
	printf("\n");
}
#endif


typedef struct ListQueueNode
{
	DataType data;
	struct ListQueueNode *next;
}ListQueueNode;

typedef struct ListQueue
{
	ListQueueNode *front;
	ListQueueNode *tail;
}ListQueue;

void ListQueueInit(ListQueue *q);
void ListQueuePush(ListQueue *q, DataType x);
void ListQueuePop(ListQueue *q);
void ListQueueShow(ListQueue *q);
DataType ListQueueFront(ListQueue *q);
void ListQueueInit(ListQueue *q)
{
	q->front = q->tail = NULL;
}
void ListQueuePush(ListQueue *q, DataType x)
{
	ListQueueNode *s = (ListQueueNode*)malloc(sizeof(ListQueueNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	if (q->front = NULL)
	{
		q->front = q->tail = s;
		return;
	}
	q->tail->next = s;
	q->tail = s;
}
void ListQueuePop(ListQueue *q)
{
	if (q->front != NULL)
	{
		ListQueueNode *p = q->front;
		q->front = q->front->next;
		free(p);
	}
}
void ListQueueShow(ListQueue *q)
{
	assert(q != NULL);
	ListQueueNode *p = q->front;
	if (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
DataType ListQueueFront(ListQueue *q)
{
	return 0;
}

