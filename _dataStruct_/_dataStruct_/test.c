#include<stdio.h>
#include<malloc.h>


// ----- ��̬����˳��� ----- //
#define LIST_INIT_SIZE 100  // ���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10 // ���Ա�洢�ռ�ķ�������
typedef int Element;
typedef struct SqList
{
	Element *elem;
	int length;    // ��ǰ����
	int listsize; //��ǰ����Ĵ洢����
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