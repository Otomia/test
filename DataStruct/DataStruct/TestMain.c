#include"common.h"
//#include"seqlist.h"
//#include"slist.h"
//#include"sclist.h"
//#include"dlist.h"
//#include"dclist.h"
//#include"queue.h"
//#include"stack.h"
//#include"bintree.h"
#include"bst.h"

int main()
{
	int ar[] = { 54,23,76,25,34,3,7,8,9,5,1,70 };
	int n = sizeof(ar) / sizeof(int);
	BSTree bst;
	BSTInit(&bst);
	for (int i = 0; i < n; ++i)
	{
		BSTreeInsert(&bst, ar[i]);
	}
	BSTNode *p = BSTreeMax(&bst);
	p = BSTFind(&bst, 53);

	BSTErase(&bst, 23);

	system("pause");
	return 0;
}

#if 0
int main()
{
	char *VLR = "ABCDEFGH";
	char *LVR = "CBEDFAGH";
	char *LRV = "CEFDBHGA";


	char *str = "ABC##DE##F##G#H##";
	BinTree bt,bt1;
	BinTreeInit(&bt);

	//BinTreeCreate(&bt);

	int n = strlen(LVR);
	CreateBinTree_VLR_LVR(&bt, VLR, LVR, n);

	//CreateBinTreeByStr(&bt, str);
	printf("VLR: ");
	//PreOrder(&bt);
	PreOrderNor(&bt);
	printf("\n");
	printf("LVR: ");
	//InOrder(&bt);
	InOrderNor(&bt);
	printf("\n");
	printf("LRV: ");
	//PostOrder(&bt);
	PostOrderNor(&bt);
	printf("\n");
	printf("Level: ");
	LevelOrder(&bt);
	printf("\n");

	printf("Size = %d\n", Size(&bt));
	printf("Height = %d\n", Height(&bt));

	system("pause");
	return 0;
}


int main()
{
	Stack st;
	int s;
	StackInit(&st, 10);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	StackPush(&st, 6); 
	StackPush(&st, 7);

	StackShow(&st);
	printf("-------------------------\n");
	StackPop(&st);
	StackPop(&st);
	StackShow(&st);
	printf("-------------------------\n");
	s = StackTop(&st);
	printf("%d\n", s);

	StackClear(&st);
	StackDestroy(&st);
	system("pause");
	return 0;
}




int main()
{
	ListQueue Q;
	ListQueueInit(&Q);

	ListQueuePush(&Q, 1);
	ListQueuePush(&Q, 2);
	ListQueuePush(&Q, 3);
	ListQueuePush(&Q, 4);
	ListQueuePush(&Q, 5);
	ListQueuePush(&Q, 7);

	ListQueueShow(&Q);
	system("pause");
	return 0;
}

int main()
{
	Queue Q;
	int p;
	QueueInit(&Q,10);
	QueuePush(&Q, 1);
	QueuePush(&Q, 2);
	QueuePush(&Q, 3);
	QueuePush(&Q, 5);
	QueuePush(&Q, 4);
	QueueShow(&Q);

	p = QueueFront(&Q);
	printf("%d\n", p);
	QueueShow(&Q);
	QueuePop(&Q);
	QueuePop(&Q); 
	QueuePop(&Q);
	QueueShow(&Q);   
	system("pause");
	return 0;
}
 


int main(int argc, char *argv[])
{
	//SeqList mylist;
	//SeqListInit(&mylist, DEFAULT_SIZE);
	//SListNode *p = NULL;
	//SList mylist;
	//SListInit(&mylist);
	//SCList mylist;
	//SCListInit(&mylist);
	//SCListNode *p = NULL;

	DList mylist;
	DListInit(&mylist);

	DListNode *p = NULL;
	DataType item;
	int pos;
	bool flag;
	int select = 1;
	while (select)
	{
		printf("************************************\n");
		printf("* [0] quit_system   [1] push_back *\n");
		printf("* [2] push_front    [3] show_list *\n");
		printf("* [4] pop_back      [5] pop_front *\n");
		printf("* [6] find_pos      [7] find_val  *\n");
		printf("* [8] insert_pos    [9] delete_val*\n");
		printf("* [10] delete_pos   [11] length   *\n");
		printf("* [12] remove_all   [13] reverse  *\n");
		printf("* [14] sort         [15] clear    *\n");
		printf("************************************\n");
		printf("��ѡ��->");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("������Ҫ���������(��-1����)->");
			while (scanf("%d", &item), item != -1)
			{
				//SeqListPushBack(&mylist, item);
				//SListPushBack(&mylist, item);
				//SCListPushBack(&mylist, item);
				DListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("������Ҫ���������(��-1����)->");
			while (scanf("%d", &item), item != -1)
			{
				//SeqListPushFront(&mylist, item);
				//SListPushFront(&mylist, item);
				//SCListPushFront(&mylist, item);
				DListPushFront(&mylist, item);
			}
			break;
		case 3:
			//SeqListShow(&mylist);
			//SListShow(&mylist);
			//SCListShow(&mylist);
			DListShow(&mylist);
			break;
		case 4:
			//SeqListPopBack(&mylist);
			break;
		case 5:
			//SeqListPopFront(&mylist);
			break;
		case 6:
			printf("������Ҫ�����±�->");
			scanf("%d", &pos);
			//printf("Ҫ��ѯ�����ݣ�%d\n",SeqListFindByPos(&mylist,pos));
			break;
		case 7:
			printf("������Ҫ���ҵ�����->");
			scanf("%d", &item);
			/*index = SeqListFindByVal(&mylist, item);
			if (index == -1)
				printf("Ҫ��ѯ������%d������\n", item);
			else
				printf("Ҫ��ѯ���ݵ��±�Ϊ-> %d\n", index);
				*/
			p = DListFindByVal(&mylist, item);
			if (p == NULL)
				printf("%d���ݲ�����\n", item);
			else
				printf("%d���ݵĵ�ַ��%p\n",item,p);//&p��p


			break;
		case 8:
			//printf("����������λ��->");
			//scanf("%d", &pos);
			printf("��������������->");
			scanf("%d", &item);
			//flag = SCListInsertByVal(&mylist,item);
			//if (flag)
				//printf("����ɹ���\n");
			//else
				//printf("����ʧ�ܡ�\n");
				
			break;
		case 9:
			printf("������Ҫɾ����Ԫ��->");
			scanf("%d", &item);
			//flag = SeqListDeleteVal(&mylist, item);
			//flag = SListEraseByVal(&mylist, item);
			//flag = SCListEraseByVal(&mylist, item);
			flag = DListEraseByVal(&mylist, item);
			if (flag)
				printf("ɾ��%d�ɹ�.\n", item);
			else
				printf("ɾ��%dʧ��.\n", item);
				
			break;
		case 10:
			printf("������Ҫɾ����λ��->");
			scanf("%d", &pos);
			/*flag = SeqListDeletePos(&mylist, pos);
			if (flag)
				printf("ɾ���ɹ�.\n");
			else
				printf("ɾ��ʧ��.\n");
				*/
			break;
		case 11:
			//printf("˳�����Ϊ%d\n", SeqListLength(&mylist));
			//printf("������Ϊ%d\n", SListLength(&mylist));
			//printf("������Ϊ%d\n", SCListLength(&mylist));
			break;
		case 12:
			printf("������Ҫɾ��������->");
			scanf("%d", &item);
			//SeqListRemoveAll(&mylist, item);
			break;
		case 13:
			//SCListReverse(&mylist);
			break;
		case 14:
			//SeqListSort(&mylist);
			break;
		case 15:
			break;
		}
	}
	//SeqListDestroy(&mylist);
	return 0;
}
#endif