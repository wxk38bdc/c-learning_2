#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"
#include"stack.h"
#define NUM 20

void testOP() {
    int n = 50000; // 数组大小，根据需要调整
    int* a = (int*)malloc(n * sizeof(int)); // 动态分配数组
    int* tmp = (int*)malloc(n * sizeof(int)); // 为归并排序准备临时数组

    // 生成n个随机数填充数组
    srand(time(NULL)); // 设置随机种子
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100000; // 生成0到99999之间的随机数
    }

    // 临时数组用于存储原数组，防止排序过程修改原数组
    int* copy = (int*)malloc(n * sizeof(int));

    // 测试不同的排序算法
    clock_t start, end; // 用于计时

    // 插入排序测试
    memcpy(copy, a, n * sizeof(int)); // 每次排序前复制原数组
    start = clock();
    InsertSort(copy, n);
    end = clock();
    printf("Insertion Sort took %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 希尔排序测试
    memcpy(copy, a, n * sizeof(int));
    start = clock();
    ShellSort(copy, n);
    end = clock();
    printf("Shell Sort took %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 选择排序测试
    memcpy(copy, a, n * sizeof(int));
    start = clock();
    SelectSort(copy, n);
    end = clock();
    printf("Selection Sort took %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 冒泡排序测试
    memcpy(copy, a, n * sizeof(int));
    start = clock();
    BubbleSort(copy, n);
    end = clock();
    printf("Bubble Sort took %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 堆排序测试
    memcpy(copy, a, n * sizeof(int));
    start = clock();
    HeapSort(copy, n);
    end = clock();
    printf("Heap Sort took %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 快速排序测试
    memcpy(copy, a, n * sizeof(int));
    start = clock();
    QuickSort(copy, 0, n - 1);
    end = clock();
    printf("Quick Sort took %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 归并排序测试
    memcpy(copy, a, n * sizeof(int));
    start = clock();
    MergeSort(copy, n);
    end = clock();
    printf("Merge Sort took %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 计数排序测试
    memcpy(copy, a, n * sizeof(int));
    start = clock();
    CountSort(copy, n);
    end = clock();
    printf("Count Sort took %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(a); // 释放原数组内存
    free(copy); // 释放临时数组内存
    free(tmp); // 释放归并排序临时数组内存
}
int main()
{
    //测试时间复杂度
    testOP();

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
	ShellSort(a, sz_a);//希尔排序
	//SelectSort(a, sz_a);//选择排序
	//HeapSort(a, sz_a);//堆排序
	//BubbleSort(a, sz_a);//冒泡排序
	//QuickSort(a, 0, sz_a - 1);//快速排序
	//QuickSortNonR(a, 0, sz_a - 1);//非递归快速排序
	//MergeSort(a, sz_a);//归并排序
	//MergeSortNonR(a, sz_a);//归并排序非递归
	//CountSort(a, sz_a);//计数排序
	
    PrintArray(a, sz_a);

	//外排序
	//MergesortFile("random_numbers.txt");
	return 0;
}