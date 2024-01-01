#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"
void Swap(HPDataType* a, HPDataType* b)
{
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}
//前提：除了root之外，其他位置已经满足小堆的性质
void AdjustDown(HPDataType* a, int n, int root)//向下调整
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
	//建堆:从最后一个非叶子节点开始向下调整
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(php->_a, php->_size, i);
	}
}
void HeapDestory(Heap* php);//销毁
void HeapPush(Heap* php, HPDataType x);//插入
void HeapPop(Heap* php);//删除
HPDataType HeapTop(Heap* php);//取堆顶元素