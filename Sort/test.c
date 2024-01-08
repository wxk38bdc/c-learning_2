#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"
#include"stack.h"
#define NUM 20
int main()
{
	//生成随机数
	srand((unsigned int)time(NULL));
	int a[NUM] = { 0 };
	int i = 0;
	for (i = 0; i < NUM; i++)
	{
		a[i] = rand() % 100;
	}
	PrintArray(a, NUM);
	int sz_a = sizeof(a) / sizeof(a[0]);
	//InsertSort(a, sz_a);//插入排序
	//ShellSort(a, sz_a);//希尔排序
	//SelectSort(a, sz_a);//选择排序
	//HeapSort(a, sz_a);//堆排序
	//BubbleSort(a, sz_a);//冒泡排序
	//QuickSort(a, 0, sz_a - 1);//快速排序
	//QuickSortNonR(a, 0, sz_a - 1);//非递归快速排序
	//MergeSort(a, sz_a);//归并排序
	MergeSortNonR(a, sz_a);//归并排序非递归
	PrintArray(a, sz_a);
	return 0;
}