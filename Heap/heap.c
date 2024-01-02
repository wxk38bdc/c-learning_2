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
void AdjustUp(HPDataType* a, int n, int child)//向上调整
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
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
void HeapDestory(Heap* php)//销毁
{
	assert(php);
	free(php->_a);
	php->_a = NULL;
	php->_size = php->_capacity = 0;
}
void HeapPush(Heap* php, HPDataType x)//插入
{
	assert(php);
	if (php->_size == php->_capacity)
	{
		php->_capacity *= 2;
		HPDataType* tmp = (HPDataType*)realloc(php->_a, sizeof(HPDataType) * php->_capacity);
		if (tmp == NULL)
		{
			assert(0);
			return;
		}
		php->_a = tmp;
	}
	php->_a[php->_size++] = x;
	AdjustUp(php->_a, php->_size, php->_size - 1);
}
void HeapPop(Heap* php)//删除堆顶元素
{
	assert(php);
	assert(php->_size > 0);
	Swap(&php->_a[0], &php->_a[php->_size - 1]);
	php->_size--;
	AdjustDown(php->_a, php->_size, 0);
}
HPDataType HeapTop(Heap* php)//取堆顶元素
{
	assert(php);
	assert(php->_size > 0);
	return php->_a[0];
}