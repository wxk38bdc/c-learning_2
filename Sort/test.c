#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"
int main()
{
	int a[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int sz_a = sizeof(a) / sizeof(a[0]);
	//InsertSort(a, sz_a);//≤Â»Î≈≈–Ú
	ShellSort(a, sz_a);//œ£∂˚≈≈–Ú
	PrintArray(a, sz_a);
	return 0;
}