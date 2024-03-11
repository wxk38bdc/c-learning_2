#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include<cstring>
#include<algorithm>
using namespace std;

typedef int HeapDataType;
struct Heap
{
	HeapDataType* data;
	size_t size;
	size_t capacity;
};
void HeapInit(Heap* pHeap);
void HeapDestroy(Heap* pHeap);
void AdjustDown(Heap* pHeap, size_t parent);
void AdjustUp(Heap* pHeap, size_t child);
void HeapPush(Heap* pHeap, HeapDataType x);
void HeapPop(Heap* pHeap);
HeapDataType HeapTop(Heap* pHeap);
size_t HeapSize(Heap* pHeap);
bool HeapEmpty(Heap* pHeap);
void HeapPrint(Heap* pHeap);

void HeapArrayInit(Heap* pHeap, HeapDataType* arr, size_t size);//将数组初始化成堆
void HeapSort(HeapDataType* arr, size_t size);//堆排序
void AdjustDown_Array(HeapDataType* arr, size_t parent, size_t size);//向下调整
#endif // !HEAP_H