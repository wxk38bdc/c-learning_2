#define _CRT_SECURE_NO_WARNINGS
#include "heap.h"
#include<ctime>

void testHeap1()
{
	//利用堆找到最小的k个数
	Heap heap;
	HeapInit(&heap);
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	for (int i = 0; i < 10; i++)
	{
		HeapPush(&heap, arr[i]);
	}
	HeapPrint(&heap);
	HeapPop(&heap);
	HeapPrint(&heap);
	HeapPop(&heap);
	HeapPrint(&heap);
	HeapPop(&heap);
	HeapPrint(&heap);
	HeapPop(&heap);

	HeapPush(&heap, 10);
	HeapPrint(&heap);
	HeapPush(&heap, 11);
	HeapPrint(&heap);
}
void testHeap2()
{
	//利用堆排序
	Heap heap;
	HeapInit(&heap);
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	for (int i = 0; i < 10; i++)
	{
		HeapPush(&heap, arr[i]);
	}
	HeapPrint(&heap);
	while (HeapEmpty(&heap) != true)
	{
		cout << HeapTop(&heap) << " ";
		HeapPop(&heap);
	}
	cout << endl;
	HeapDestroy(&heap);
}
int main()
{
	testHeap1();
	//testHeap2();
	return 0;
}