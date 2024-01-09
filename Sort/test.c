#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"
#include"stack.h"
#define NUM 20
int main()
{
	////Éú³ÉËæ»úÊý
	//srand((unsigned int)time(NULL));
	//int a[NUM] = { 0 };
	//int i = 0;
	//for (i = 0; i < NUM; i++)
	//{
	//	a[i] = rand() % 100;
	//}
	//PrintArray(a, NUM);
	//int sz_a = sizeof(a) / sizeof(a[0]);
	//InsertSort(a, sz_a);//²åÈëÅÅÐò
	//ShellSort(a, sz_a);//Ï£¶ûÅÅÐò
	//SelectSort(a, sz_a);//Ñ¡ÔñÅÅÐò
	//HeapSort(a, sz_a);//¶ÑÅÅÐò
	//BubbleSort(a, sz_a);//Ã°ÅÝÅÅÐò
	//QuickSort(a, 0, sz_a - 1);//¿ìËÙÅÅÐò
	//QuickSortNonR(a, 0, sz_a - 1);//·ÇµÝ¹é¿ìËÙÅÅÐò
	//MergeSort(a, sz_a);//¹é²¢ÅÅÐò
	//MergeSortNonR(a, sz_a);//¹é²¢ÅÅÐò·ÇµÝ¹é
	//PrintArray(a, sz_a);
	//ÍâÅÅÐò
	MergesortFile("random_numbers.txt");
	return 0;
}