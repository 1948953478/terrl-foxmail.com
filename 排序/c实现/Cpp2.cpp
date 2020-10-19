#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
typedef int KeyType;
typedef int DataType;
#define MaxSize 60000
typedef struct entry
{
	KeyType key;//����ؼ���
	DataType data;//����������

}Entry;
typedef struct maxheap
{
	int n, MaxHeap;
	Entry D[MaxSize];
}MaxHeap;
typedef struct list
{
	int n;//Ԫ�ظ���
	Entry D[MaxSize];//��̬����
}List;
void InIt(MaxHeap *list, int nSize)
{
	list->n = nSize;
	for (int i = 0; i < nSize; i++)
	{
		list->D[i].key = (int)malloc(nSize * sizeof(int));
		list->D[i].key = 0;
	}
}
void InSert(MaxHeap *list, int nSize)
{
	int i;
	srand((unsigned)time(NULL));
	for (i = 0; i < nSize; i++)
	{
		list->D[i].key = (rand() % 100000+1);
	}
}
void InIt(List *list, int nSize)
{
	list->n = nSize;
	for (int i = 0; i < nSize; i++)
	{
		list->D[i].key = (int)malloc(nSize * sizeof(int));
		list->D[i].key = 0;
	}
}
void InSert(List *list, int nSize)
{
	int i;
	srand((unsigned)time(NULL));
	for (i = 0; i < nSize; i++)
	{
		list->D[i].key = (rand() % 100000+1);
	}
}
void swap(Entry* D, int i, int j)
{
	if (i == j)
		return;
	Entry temp = *(D + i);
	*(D + i) = *(D + j);
	*(D + j) = temp;
}
void AdjustDown(Entry *heap, int s, int m)
{
	Entry temp = heap[s];
	int j;
	for (j = 2 * s; j <= m; j *= 2)
	{
		if (j < m&&heap[j].key < heap[j + 1].key)
			j++;
		if (temp.key > heap[j].key)
			break;
		heap[s] = heap[j];
		s = j;

	}
	heap[s] = temp;
}

//��ѡ������
void SelectSort(List *list) {
	int small, i, j;
	for (i = 0; i < list->n - 1; i++) {
		small = i;                                    //���ÿ�ε�һλԪ���±�
		for (j = i + 1; j < list->n; j++) {
			if (list->D[j].key < list->D[small].key) {  //���ǵݼ�˳��Ƚϴ�С
				small = j;
			}
		}

		if (small != i) {                               //�ж���ʼλ���Ƿ�Ϊ��Сֵ
			swap(list->D, small, i);//������С�ͱ�����㽻��λ��
		}
	}
}

//ֱ�Ӳ�������
void InsertSort(List *list)
{
	int i, j;                                 //i��ʶ������Ԫ���±�
	for (i = 1; i < list->n; i++) {
		Entry insertItem = list->D[i];     //���ÿ�ε�һλԪ��
		for (j = i - 1; j >= 0; j--) {
			//���Ͻ�����������Ԫ������ƶ�,Ϊ������Ԫ�ؿճ�һ��λ��
			if (insertItem.key < list->D[j].key) {
				list->D[j + 1] = list->D[j];
			}
			else break;
		}
		list->D[j + 1] = insertItem;          //������Ԫ��������������������
	}
}
//ð������
void BubbleSort(List *list) {
	int i, j;                    //i��ʶÿ������Χ���һ��Ԫ���±�,ÿ������Ԫ���±귶Χ��0~i
	for (i = list->n - 1; i > 0; i--) {
		bool isSwap = false;    //�̲��������,Ӧ�÷ŵ��ڶ���ѭ��ǰ
		for (j = 0; j < i; j++) {
			if (list->D[j].key > list->D[j + 1].key) {
				swap(list->D, j, j + 1);
				isSwap = true;
			}
		}
		if (!isSwap) break;     //�����������û�з���Ԫ�ؽ���,�������
	}
}
//���л��ַ���
int Partition(List *list, int low, int high) {
	int i = low, j = high + 1;
	Entry pivot = list->D[low];                 //pivot�Ƿָ�Ԫ��
	do {
		do i++;
		while (list->D[i].key < pivot.key);      //iǰ��
		do j--;
		while (list->D[j].key > pivot.key);      //jǰ��
		if (i < j) swap(list->D, i, j);
	} while (i < j);
	swap(list->D, low, j);
	return j;                                   //��ʱj�Ƿָ�Ԫ���±�
}


//��������
void QuickSort(List *list, int low, int high) {   //��������ĵݹ麯��
	int k;
	if (low < high) {                            //��ǰ�������������ٰ���2��Ԫ��
		k = Partition(list, low, high);
		QuickSort(list, low, k - 1);
		QuickSort(list, k + 1, high);
	}
}


//��������
void QuickSort(List *list) {                   //���������㷨�������ú���
	QuickSort(list, 0, list->n - 1);
}
//Merge����
void Merge(List *list, int Temp[], int i1, int j1, int i2, int j2, int *k) {
	int i = i1, j = i2;
	while ((i <= j1) && (j <= j2)) {                       //�����������ж�����,��ѭ��
		if (list->D[i].key <= list->D[j].key) {
			Temp[(*k)++] = list->D[i++].key;         //����СԪ�ش���Temp[*k]
		}
		else Temp[(*k)++] = list->D[j++].key;
	}
	while (i <= j1) Temp[(*k)++] = list->D[i++].key;  //��������1��ʣ��Ԫ�ش���Temp
	while (j <= j2) Temp[(*k)++] = list->D[j++].key;  //��������2��ʣ��Ԫ�ش���Temp
}


//MergeSort������
void MergeSort(List *list) {
	int Temp[MaxSize];
	int i1, j1, i2, j2, i, k, size = 1;              //i1,j1��i2,j2�ֱ������������е���,�½�
	while (size < list->n) {
		i1 = 0;
		k = 0;
		while (i1 + size < list->n) {              //��i1+size < n,��˵����������������,��Ҫ�������ϲ�
			i2 = i1 + size;                      //ȷ��������2���½��������1���Ͻ�
			j1 = i2 - 1;
			if (i2 + size - 1 > list->n - 1) {         //����������2���Ͻ�
				j2 = list->n - 1;
			}
			else j2 = i2 + size - 1;
			Merge(list, Temp, i1, j1, i2, j2, &k);  //�ϲ���������������
			i1 = j2 + 1;                        //ȷ����һ�κϲ���һ�������е��½�
		}
		for (i = 0; i < k; i++) {
			list->D[i].key = Temp[i];
		}
		size *= 2;                            //�����г�������һ��
	}
}
//�������㷨
void HeapSort(MaxHeap *heap)
{
	int i;
	for (i = heap->n / 2; i >=0; i--)//��Ϊ>=0�������һ��������ѵ���
		AdjustDown(heap->D, i, heap->n);
	for (i = heap->n - 1; i > 0; i--)
	{
		swap(heap->D, 0, i);
		if(i>1)//�ڽ̲����������������ѭ��
		AdjustDown(heap->D, 0, i-1);//��i-1����i
	}
}

int main()

{
	double start, finish; /* ���忪ʼ��ʱ��ͽ�����ʱ�� */
	int m, n = 0;
	printf("��������������������\n");
	scanf_s("%d", &n);
	List list;
	InIt(&list, n);
	InSert(&list, n);
	FILE *fp;
	fp = fopen("F:\\���ݿ�\\2018-1-4\\���ݽṹʵ����\\test.txt", "w");
	if (!fp)
	{
		printf("file error!\n");
		exit(1);
	}
	/*for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%d ", list.D[i].key);
	}*/
	fclose(fp);
	printf("\n��ѡ�����򷽷���\n1����ѡ������\n2��ֱ�Ӳ�������\n3��ð������\n4����������\n5����·�ϲ�����\n6��������\n\n");
	scanf_s("%d", &m);
	printf("\n");
	/*if (m!=6)
	{
		printf("ԭ���飺\n");
		for (int i = 0; i < n; i++)
		{
			printf("%d ", list.D[i].key);
		}
		printf("\n");
	}*/
	
	switch (m)
	{
	case 1:
		printf("\n�������м�ѡ������\n\n");
		start = (double)clock();
		SelectSort(&list);
		finish = (double)clock();
		break;
	case 2:
		printf("\n��������ֱ�Ӳ�������\n\n");
		start = (double)clock();
		InsertSort(&list);
		finish = (double)clock();
		break;
	case 3:
		printf("\n��������ð������\n\n");
		start = (double)clock();
		BubbleSort(&list);
		finish = (double)clock();
		break;
	case 4:
		printf("\n�������п�������\n\n");
		start = (double)clock();
		QuickSort(&list);
		finish = (double)clock();
		break;
	case 5:
		printf("\n����������·�ϲ�����\n\n");
		start = (double)clock();
		MergeSort(&list);
		finish = (double)clock();
		break;
	case 6:
		MaxHeap heap;
		InIt(&heap, n);
		InSert(&heap, n);
		printf("ԭ���飺\n");
		for (i = 0; i < n; i++)
		{
			printf("%d ", heap.D[i].key);
		}
		printf("\n");
		printf("\n�������ж�����\n\n");
		start = (double)clock();
		HeapSort(&heap);
		finish = (double)clock();
		printf("��������飺\n");
		for (int i = 0; i < n; i++)
		{
			printf("%d ", heap.D[i].key);
		}
		printf("\n");
		break;
	default:
		break;
	}
	/*if (m != 6)
	{
		printf("��������飺\n");
		for (int i = 0; i < n; i++)
		{
			printf("%d ", list.D[i].key);
		}
		printf("\n\n");
	}*/
	printf("����ʱ�䣺%.4fms\n", (finish-start));
	

	
	return 0;
}