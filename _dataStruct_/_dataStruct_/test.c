#include<stdio.h>
#include<malloc.h>


// ----- 动态分配顺序表 ----- //
#define LIST_INIT_SIZE 100  // 线性表存储空间的初始分配量
#define LISTINCREMENT 10 // 线性表存储空间的分配增量
typedef int Element;
typedef struct SqList
{
	Element *elem;
	int length;    // 当前长度
	int listsize; //当前分配的存储容量
}SqList;


void Init(SqList *L)
{
	L->elem = (Element *)malloc(LIST_INIT_SIZE * sizeof(Element));
	if (!L->elem)
		return;
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
}

int main()
{

}