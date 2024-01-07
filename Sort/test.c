#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"
int main()
{
	int a[] = { 9,8,7,6,5,4,3,2,1,0,1,5,6,7,9,10,2};
	int sz_a = sizeof(a) / sizeof(a[0]);
	//InsertSort(a, sz_a);//≤Â»Î≈≈–Ú
	//ShellSort(a, sz_a);//œ£∂˚≈≈–Ú
	//SelectSort(a, sz_a);//—°‘Ò≈≈–Ú
	//HeapSort(a, sz_a);//∂—≈≈–Ú
	//BubbleSort(a, sz_a);//√∞≈›≈≈–Ú
	QuickSort(a, 0, sz_a - 1);//øÏÀŸ≈≈–Ú
	PrintArray(a, sz_a);
	return 0;
}