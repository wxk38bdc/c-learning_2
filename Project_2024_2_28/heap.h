#pragma once
#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
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

#endif // !HEAP_H