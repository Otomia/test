//#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
/*
#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#define NULL_DATA -1

typedef struct SeqList
{
	DataType *base;
	size_t capacity;
	size_t size;
}SeqList;

//�ڲ�����
static  bool _Inc(SeqList *psl);

bool SeqListIsFull(SeqList *psl);
bool SeqListIsEmpty(SeqList *psl);


void SeqListInit(SeqList* psl, size_t capacity);
void SeqListPushBack(SeqList* psl, DataType x);
void SeqListPushFront(SeqList* psl, DataType x);
void SeqListShow(SeqList* psl);
void SeqListPopBack(SeqList* psl);
void SeqListPopFront(SeqList* psl);

DataType SeqListFindByPos(SeqList* psl, int pos);
int SeqListFindByVal(SeqList* psl, DataType key);
bool SeqListInsertPos(SeqList* psl, int i,DataType x);
bool SeqListDeletePos(SeqList* psl, int pos);
bool SeqListDeleteVal(SeqList* psl, DataType key);
int SeqListLength(SeqList* psl);

void SeqListRemoveAll(SeqList* psl,DataType x);
void SeqListReverse(SeqList* psl);
void SeqListSort(SeqList* psl);
void SeqListClear(SeqList* psl);
void SeqListDestroy(SeqList *psl);


bool _Inc(SeqList *psl)
{
	DataType *new_base =
		(DataType)malloc(sizeof(DataType)*(psl->capacity + INC_SIZE));
	if (new_base == NULL)
		return false;
	memcpy(new_base, psl->base, sizeof(DataType)*psl->capacity);
	free(psl->base);

	psl->base = new_base;
	psl->capacity += INC_SIZE;
	return true;
}

bool SeqListIsFull(SeqList *psl)
{
	if (psl->size == psl->capacity)
		return true;
	return false;
}

bool SeqListIsEmpty(SeqList *psl)
{
	if (psl->size == 0)
		return true;
	return false;
}

//��ʼ��
void SeqListInit(SeqList* psl, size_t capacity)
{
	psl->base = (DataType*)malloc(sizeof(DataType)*capacity);
	psl->capacity = capacity;
	psl->size = 0;
}
//β��
void SeqListPushBack(SeqList* psl, DataType x)
{
	if (SeqListIsFull(psl) && !_Inc(psl))
	{
		printf("˳���������%d���ܲ���.\n",x);
		return;
	}
	psl->base[psl->size++] = x;
}
//ͷ��
void SeqListPushFront(SeqList* psl, DataType x)
{
	if (SeqListIsFull(psl) && !_Inc(psl))
	{
		printf("˳���������%d���ܲ���.\n",x);
		return;
	}
	for (int i = psl->size; i > 0; --i)
	{
		psl->base[i] = psl->base[i - 1];
	}
	psl->base[0] = x;
	psl->size++;
}
//��ʾ
void SeqListShow(SeqList* psl)
{
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->base[i]);
	}
	printf("\n");
}
//βɾ
void SeqListPopBack(SeqList* psl)
{
	//�п�
	if (SeqListIsEmpty(psl))
	{
		printf("˳���Ϊ�գ����ܽ���ɾ��!\n");
		return;
	}
	psl->size--;

}
//ͷɾ
void SeqListPopFront(SeqList* psl)
{
	//�п�
	if (SeqListIsEmpty(psl))
	{
		printf("˳���Ϊ�գ����ܽ���ɾ��!\n");
		return;
	}
	for (int i = 0; i < psl->size; i++)
	{
		psl->base[i] = psl->base[i + 1];
	}
	psl->size--;
}
//ͨ���±����Ԫ��
DataType SeqListFindByPos(SeqList* psl, int pos)
{
	if (pos < 0 || pos >= psl->size)
	{
		printf("��ѯ��λ����Ч��\n");
		return NULL_DATA;
	}
	return psl->base[pos];
}
//ָ���±�Ԫ��ֵ
int SeqListFindByVal(SeqList* psl, DataType key)
{
	for (int i = 0; i < psl->size; i++)
	{
		if (key == psl->base[i])
		{
			return i;
		}
	}
	return -1;
}
//ָ��λ�ò���Ԫ��
bool SeqListInsertPos(SeqList* psl, int pos, DataType x)
{
	if (pos < 0 || pos > psl->size)
	{
		return false;
	}
	if(SeqListIsFull(psl) && !_Inc(psl))
	{
		printf("˳���������%d���ܲ���.\n", x);
		return false;
	}
	for (int i = psl->size; i > pos; i--)
	{
		psl->base[i] = psl->base[i - 1];
	}
	psl->base[pos] = x;
	psl->size++;
	return true;
}
//ɾ��ָ��λ��Ԫ��
bool SeqListDeletePos(SeqList* psl, int pos)
{
	if (pos < 0 || pos >= psl->size)
	{
		return false;
	} 
	for (int i = pos; i < psl->size - 1; i++)
	{
		psl->base[i] = psl->base[i + 1];
	}
	psl->size--;
	return true;
}
//ɾ��ָ��Ԫ��
bool SeqListDeleteVal(SeqList* psl, DataType key)
{
	int pos = SeqListFindByVal(psl, key); //������&psl�ͻ��������
	if (pos == -1)
	{
		return false;
	}
	return SeqListDeletePos(psl, pos);//������&psl�ͻ��������
}
//˳�����
int SeqListLength(SeqList* psl)
{
	if (psl->size == 0)
	{
		printf("˳���Ϊ��!\n");
		return 0;
	}
	return psl->size;
}
//

//˳�������
void SeqListReverse(SeqList* psl)
{
	if (psl->size >= 2)
	{
		int begin = 0;
		int end = psl->size - 1;
		while (begin < end)
		{
			Swap(&(psl->base[begin]),&(psl->base[end]));
			begin++;
			end--;
		}
	}
}

//�Ƴ�����ָ��Ԫ��
void SeqListRemoveAll(SeqList *psl, DataType x)
{
	for (int i = 0; i < psl->size; ++i)
	{
		if (x == psl->base[i])
		{
			for (int j = i; j < psl->size - 1; j++)
				psl->base[j] = psl->base[j + 1];
			psl->size--;
			i--;
		}
	}
}

//˳�������
void SeqListSort(SeqList* psl)
{
	for (int i = 0; i < psl->size - 1; i++)
	{
		for (int j = 0; j < psl->size - i - 1; j++)
		{
			if (psl->base[j] > psl->base[j + 1])
			{
				Swap(&(psl->base[j]), &(psl->base[j + 1]));
			}
		}
	}
}
//�������Ԫ��
void SeqListClear(SeqList* psl)
{
	psl->size = 0;
}
//�ݻ�
void SeqListDestroy(SeqList *psl)
{
	free(psl->base);
	psl->base = NULL;
	psl->capacity = psl->size = 0;
}
#endif /*_SEQLIT_H_*/

