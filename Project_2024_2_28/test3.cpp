#define _CRT_SECURE_NO_WARNINGS
#include "heap.h"
#include<ctime>
int main()
{
	srand((unsigned int)time(0));
	//ÀûÓÃ¶ÑÅÅĞò
	int* arr= new int[100];
	for (int i = 0; i < 100; i++)
	{
		arr[i] = rand()%1000;
		cout << arr[i] << " ";
	}
	cout << endl;
	Heap heap;
	HeapInit(&heap);
	for (int i = 0; i < 100; i++)
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

	return 0;
}