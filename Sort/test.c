#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"
#include"stack.h"
#define NUM 15

void testOP() {
    int n = 10000; // 数组大小，根据需要调整
    int* a = (int*)malloc(n * sizeof(int)); // 动态分配数组
    int* tmp = (int*)malloc(n * sizeof(int)); // 为归并排序准备临时数组

    // 生成n个随机数填充数组
    srand(time(NULL)); // 设置随机种子
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100000; // 生成0到99999之间的随机数
    }

    //打印数组长度
    printf("数组长度：%d\n", n);

    // 临时数组用于存储原数组，防止排序过程修改原数组
    int* copy = (int*)malloc(n * sizeof(int));

    // 测试不同的排序算法
    clock_t start, end; // 用于计时

    // 插入排序测试
    memcpy(copy, a, n * sizeof(int)); // 每次排序前复制原数组
    start = clock();
   // InsertSort(copy, n);
    end = clock();
    printf("Insertion Sort took %.3f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 希尔排序测试
    memcpy(copy, a, n * sizeof(int));
    start = clock();
    ShellSort(copy, n);
    end = clock();
    printf("Shell Sort took %.3f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 选择排序测试
    memcpy(copy, a, n * sizeof(int));
    start = clock();
  //  SelectSort(copy, n);
    end = clock();
    printf("Selection Sort took %.3f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 冒泡排序测试
    memcpy(copy, a, n * sizeof(int));
    start = clock();
  //  BubbleSort(copy, n);
    end = clock();
    printf("Bubble Sort took %.3f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 堆排序测试
    memcpy(copy, a, n * sizeof(int));
    start = clock();
    HeapSort(copy, n);
    end = clock();
    printf("Heap Sort took %.3f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 快速排序测试
    memcpy(copy, a, n * sizeof(int));
    start = clock();
    QuickSort(copy, 0, n - 1);
    end = clock();
    printf("Quick Sort took %.3f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 非递归快速排序测试
    memcpy(copy, a, n * sizeof(int));
    start = clock();
    QuickSortNonR(copy, 0, n - 1);
	end = clock();
    printf("Non-Recursive Quick Sort took %.3f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 归并排序测试
    memcpy(copy, a, n * sizeof(int));
    start = clock();
    MergeSort(copy, n);
    end = clock();
    printf("Merge Sort took %.3f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 非递归归并排序测试
    memcpy(copy, a, n * sizeof(int));
    start = clock();
    MergeSortNonR(copy, n);
	end = clock();
    printf("Non-Recursive Merge Sort took %.3f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 计数排序测试
    memcpy(copy, a, n * sizeof(int));
    start = clock();
    CountSort(copy, n);
    end = clock();
    printf("Count Sort took %.3f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 桶排序测试
    memcpy(copy, a, n * sizeof(int));
    start = clock();
    BucketSort(copy, n);
	end = clock();
    printf("Bucket Sort took %.3f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 基数排序测试
    memcpy(copy, a, n * sizeof(int));
    start = clock();
    RadixSort(copy, n);
	end = clock();
    printf("Radix Sort took %.3f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    //// 猴子排序测试
    //memcpy(copy, a, n * sizeof(int));
    //start = clock();
    //MonkeySort(copy, n);
    //end = clock();
    //printf("Monkey Sort took %.3f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(a); // 释放原数组内存
    free(copy); // 释放临时数组内存
    free(tmp); // 释放归并排序临时数组内存
}
void test() {
	int a[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	int sz = sizeof(a) / sizeof(a[0]);
	//InsertSort(a, sz);
	//ShellSort(a, sz);
	//SelectSort(a, sz);
	//HeapSort(a, sz);
	//BubbleSort(a, sz);
	//QuickSort(a, 0, sz - 1);
	//QuickSortNonR(a, 0, sz - 1);
	//MergeSort(a, sz);
	//MergeSortNonR(a, sz);
	//CountSort(a, sz);
	//BucketSort(a, sz);
	RadixSort(a, sz);
	PrintArray(a, sz);
}
int main()
{
    //测试时间复杂度
    testOP();

    //test();
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
	//MergeSortNonR(a, sz_a);//归并排序非递归
	CountSort(a, sz_a);//计数排序
    //BucketSort(a, sz_a);//桶排序
    //RadixSort(a, sz_a);//基数排序
    //MonkeySort(a, sz_a);//猴子排序

    PrintArray(a, sz_a);

	//外排序
	//MergesortFile("random_numbers.txt");
	return 0;
}