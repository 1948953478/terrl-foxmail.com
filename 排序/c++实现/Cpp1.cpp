#include <iostream>
using namespace std;
#include <time.h>
#include<assert.h>
#include<stack>
#define M 100 /* ִ�д��� */
#define N 500 /* �����С */

void Menu();//�˵�����
void BubbleSort(int *a, size_t n);//1��ð������
void InsertSort(int *a, size_t n);//2,��������
void SheelSort(int *a, size_t n);//3,ϣ������
void SelectSort(int *a, size_t n);//4,ѡ������
void QuickSort(int *a, size_t left, size_t right);//5�����������㷨
void HeapSort(int *a, size_t n);//6��������
void MergeSort(int* a, size_t n);//7,�鲢����
void CountSort(int *a, size_t n);//8,��������
void LSDSort(int *a, size_t n);//9����������




void Menu()
{
	cout << "**********************************************\n";
	cout << "*****************1��ð������******************\n";
	cout << "*****************2����������******************\n";
	cout << "*****************3��ϣ������******************\n";
	cout << "*****************4��ѡ������******************\n";
	cout << "***************5�����������㷨****************\n";
	cout << "*****************6��������********************\n";
	cout << "*****************7���鲢����******************\n";
	cout << "*****************8����������******************\n";
	cout << "*****************9����������******************\n";
	cout << "*******************0���˳�********************\n";
	cout << "**********************************************\n";
	cout << "��ѡ��һ��������㷨�� " << endl;
}
//1��ð������
void BubbleSort(int *a, size_t n)
{
	int i, j;
	int tmp;
	for (i = 1; i < n; i++)
	{
		for (j = n-1; j >= i; j--)
		{
			if (a[j + 1] < a[j])
			{
				tmp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = tmp;
			}
		}
	}
}

//2,��������
void InsertSort(int *a, size_t n)
{
	int i;
	int j;
	for (i = 2; i <= n; i++)
	{
		a[0] = a[i];
		j = i - 1;
		while (a[0] < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = a[0];
	}
}

//3,ϣ������
void SheelSort(int *a, size_t n)
{
	assert(a);
	int gub = n / 2;//�ȶ�������Ϊn/2
	while (gub > 0)
	{
		for (size_t i = gub; i < n; ++i)//�ӵ�gub�����ݴ���ʼ���н���
		{
			int tmp = a[i];
			int end = i - gub;
			while (end >= 0 && tmp < a[end])
			{
				a[end + gub] = a[end];
				end = end - gub;
			}
			a[end + gub] = tmp;
		}
		gub /= 2;
	}
}

//4,ѡ������
void SelectSort(int *a, size_t n)
{
	assert(a);
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		size_t MinIndex = left;
		size_t MaxIndex = right;
		for (size_t i = left; i <= right; ++i)
		{
			if (a[i] < a[MinIndex])
			{
				MinIndex = i;
			}
			if (a[i] > a[MaxIndex])
			{
				MaxIndex = i;
			}

		}
		swap(a[left], a[MinIndex]);
		if (MaxIndex == left)
		{
			MaxIndex = MinIndex;
		}
		swap(a[right], a[MaxIndex]);
		++left;
		--right;
	}
}

//5�����������㷨
int PartSort(int *a, size_t left, size_t right)

{
	int i, j;
	static int w = 0;
	int temp;
	i = left;
	j = right;
	temp = a[i];
	do
	{
		while ((a[j]>temp) && (i<j))
		{
			j--;
			w++;
		}
		if (i<j)
		{
			a[i] = a[j];
			i++;
			w++;
		}
		while ((a[i]<= temp) && (i<j))
		{
			i++;
			w++;
		}
		if (i<j)
		{
			a[j] = a[i];
			j--;
			w++;
		}
	} while (i != j);
	a[i] = temp;
	return i;
}

void QuickSort(int *a, size_t left, size_t right)
{
	assert(a);
	if (left >= right)
	{
		return;
	}
	int div = PartSort(a, left, right);
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);
}

//6��������
void AdjustDown(int *a, size_t n, int root)
{
	size_t parent = root;
	size_t child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			swap(a[child], a[parent]);
			parent = child;;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int *a, size_t n)
{
	assert(a);
	int parent = (n - 2) >> 1;
	//����
	for (; parent >= 0; --parent)
	{
		AdjustDown(a, n, parent);
	}
	for (int i = n - 1; i >= 0; --i)
	{
		swap(a[0], a[i]);
		AdjustDown(a, i, 0);
	}
}

//7���鲢����
void _MergeSort(int* src, int* dst, int left, int right)
{
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	//[left,mid],[mid+1,right]
	_MergeSort(src, dst, left, mid);
	_MergeSort(src, dst, mid + 1, right);

	int begin1 = left; int begin2 = mid + 1;
	int index = 0;

	while (begin1 <= mid && begin2 <= right)
	{
		if (src[begin1] < src[begin2])
			dst[index++] = src[begin1++];
		else
			dst[index++] = src[begin2++];
	}

	while (begin1 <= mid)
		dst[index++] = src[begin1++];
	while (begin2 < right)
		dst[index++] = src[begin2++];

	int i = 0; int j = left;
	while (i < index)
		src[j++] = dst[i++];
}
void MergeSort(int* arr, size_t len)
{
	assert(arr);
	assert(len > 0);
	int *tmp = new int[len];
	_MergeSort(arr, tmp, 0, len - 1);
}

//8,��������
void CountSort(int *a, size_t n)
{
	int i, j, k;
	int C[N + 1] = { 0 };  /*���ڼ�����C���������Ԫ�س�ֵΪ0*/
	for (i = 0; i<n; i++)
		C[a[i]]++;    /*���磬R[i].keyΪ6ʱ��C[6]++��C[R[i].key]��R[i].key���ֵĴ���*/
	k = 0;
	for (j = 0; j <= N; j++)    /*����ÿһ��j*/
	for (i = 1; i <= C[j]; i++)   /*j=R[j].key���ֹ�C[j]�����˼�������Ľ��*/
		a[k++] = j;
}

//9����������
size_t GetMaxDigit(int *a, size_t n)
{
	size_t digit = 1;
	size_t base = 10;
	for (size_t i = 0; i < n; i++)
	{
		while (a[i] >= base)
		{
			base *= 10;
			digit++;
		}
	}
	return digit;
}
void LSDSort(int *a, size_t n)
{
	size_t maxDigit = GetMaxDigit(a, n);
	size_t base = 1;
size_t i;
	size_t *bucket = new size_t[n];
	while ((maxDigit--) > 0)
	{
		size_t counts[10] = { 0 };
		size_t start[10] = { 0 };
		start[0] = 0;

		for ( i = 0; i < n; i++)
		{
			size_t num = (a[i] / base) % 10;
			counts[num]++;
		}
		for ( i = 1; i < 10; i++)
		{
			start[i] = start[i - 1] + counts[i - 1];
		}

		for ( i = 0; i < n; i++)
		{
			size_t num = (a[i] / base) % 10;
			bucket[start[num]++] = a[i];
		}
		memcpy(a, bucket, sizeof(size_t)*n);
		base *= 10;
	}
}


void main() 
{
	int a[N], i, j, p;
	Menu();
	do{
		cin >> p;
		double start, finish; /* ���忪ʼ��ʱ��ͽ�����ʱ�� */
		start = (double)clock(); 
		for (j = 0; j<M; j++) 
		{ /* ִ��M�� */
			for (i = 0; i<N; *(a + i++) = rand() % 10); /* ÿ�ζ�����������¸�ֵ */
			switch (p)
			{
			case 1:BubbleSort(a, N); 
				break;
			case 2:InsertSort(a, N);
				break;
			case 3:SheelSort(a, N);
					break;
			case 4:SelectSort(a, N);
					break;
			case 5:QuickSort(a, 0, N - 1);
					break;
			case 6:HeapSort(a, N);
					break;
			case 7:MergeSort(a, N);
				break;
			case 8:CountSort(a, N);
					break;
			case 9:LSDSort(a, N);
			case 0:break;
			default:break;
			}
		}
		finish = (double)clock();
		printf("%.4fms\n", (finish - start));
	} while (p != 0);
}
