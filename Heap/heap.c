#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"
void Swap(HPDataType* a, HPDataType* b)
{
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}
//ǰ�᣺����root֮�⣬����λ���Ѿ�����С�ѵ�����
void AdjustDown(HPDataType* a, int n, int root)//���µ���
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])
			child++;
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapInit(Heap* php, HPDataType* a, int n)
{
	php->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if(php->_a == NULL)
	{
		assert(0);
		return;
	}
	memcpy(php->_a, a, sizeof(HPDataType) * n);
	php->_size = n;
	php->_capacity = n;
	//����:�����һ����Ҷ�ӽڵ㿪ʼ���µ���
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(php->_a, php->_size, i);
	}
}
void HeapDestory(Heap* php);//����
void HeapPush(Heap* php, HPDataType x);//����
void HeapPop(Heap* php);//ɾ��
HPDataType HeapTop(Heap* php);//ȡ�Ѷ�Ԫ��