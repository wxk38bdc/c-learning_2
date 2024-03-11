#define _CRT_SECURE_NO_WARNINGS
#include "heap.h"
//小堆
void HeapInit(Heap* pHeap)
{
	assert(pHeap);
	pHeap->data = (HeapDataType*)malloc(sizeof(HeapDataType) * 3);
	if (pHeap->data == NULL)
	{
		assert(0);
		return;
	}
	pHeap->size = 0;
	pHeap->capacity = 3;
}
void HeapDestroy(Heap* pHeap)
{
	assert(pHeap);
	free(pHeap->data);
	pHeap->data = NULL;
	pHeap->size = 0;
	pHeap->capacity = 0;
}
void AdjustDown(Heap* pHeap, size_t parent)//大堆
{
	assert(pHeap);
	size_t child = parent * 2 + 1;
	while (child < pHeap->size)
	{
		if (child + 1 < pHeap->size && pHeap->data[child + 1] > pHeap->data[child])
		{
			child++;
		}
		if (pHeap->data[child] > pHeap->data[parent])
		{
			swap(pHeap->data[child], pHeap->data[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void AdjustDown_Array(HeapDataType* arr, size_t parent, size_t size)
{
	size_t child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && arr[child + 1] > arr[child])
		{
			child++;
		}
		if (arr[child] > arr[parent])
		{
			swap(arr[child], arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void AdjustUp(Heap* pHeap, size_t child)//大堆
{
	assert(pHeap);
	size_t parent = (child - 1) / 2;
	while (child > 0)
	{
		if (pHeap->data[child] > pHeap->data[parent])
		{
			swap(pHeap->data[child], pHeap->data[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapPush(Heap* pHeap, HeapDataType x)
{
	assert(pHeap);
	if (pHeap->size == pHeap->capacity)
	{
		pHeap->capacity *= 2;
		pHeap->data = (HeapDataType*)realloc(pHeap->data, sizeof(HeapDataType) * pHeap->capacity);
		if (pHeap->data == NULL)
		{
			assert(0);
			return;
		}
	}
	pHeap->data[pHeap->size] = x;
	pHeap->size++;
	AdjustUp(pHeap, pHeap->size - 1);
}
void HeapPop(Heap* pHeap)
{
	assert(pHeap);
	if (pHeap->size == 0)
	{
		return;
	}
	swap(pHeap->data[0], pHeap->data[pHeap->size - 1]);
	pHeap->size--;
	AdjustDown(pHeap, 0);
}
HeapDataType HeapTop(Heap* pHeap)
{
	assert(pHeap);
	assert(pHeap->size > 0);
	return pHeap->data[0];
}
size_t HeapSize(Heap* pHeap)
{
	assert(pHeap);
	return pHeap->size;
}
bool HeapEmpty(Heap* pHeap)
{
	assert(pHeap);
	return pHeap->size == 0;
}
void HeapPrint(Heap* pHeap)
{
	assert(pHeap);
	for (size_t i = 0; i < pHeap->size; i++)
	{
		cout << pHeap->data[i] << " ";
	}
	cout << endl;
}

void HeapArrayInit(Heap* pHeap, HeapDataType* arr, size_t size)//将数组初始化成堆
{
	assert(pHeap);
	assert(arr);
	pHeap->data = (HeapDataType*)malloc(sizeof(HeapDataType) * size);
	if (pHeap->data == NULL)
	{
		assert(0);
		return;
	}
	memcpy(pHeap->data, arr, sizeof(HeapDataType) * size);
	pHeap->size = pHeap->capacity = size;
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		AdjustDown(pHeap, i);
	}
}

void HeapSort(HeapDataType* arr, size_t n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown_Array(arr, i, n);
	}
	for (int i = 0; i < n; i++)
	{
		swap(arr[0], arr[n - 1 - i]);
		AdjustDown_Array(arr, 0, n - 1 - i);
	}
}
