#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<time.h>//用于随机数的产生
#include<stdbool.h>

//插入排序
void InsertSort(int* a, int n);

//希尔排序
void ShellSort(int* a, int n);

//选择排序
void SelectSort(int* a, int n);

//堆排序
void AdjustDown(int* a, int n, int root);
void HeapSort(int* a, int n);

//冒泡排序
void BubbleSort(int* a, int n);

//快速排序
int GetMidIndex(int* a, int begin, int end);
int PartSort1(int* a, int begin, int end);
int PartSort2(int* a, int begin, int end);
int PartSort3(int* a, int begin, int end);
void QuickSort(int* a, int left, int right);
void QuickSortNonR(int* a, int left, int right);//非递归快速排序

//归并排序
void Merge(int* a, int left, int mid, int right, int* tmp);
void _MergeSort(int* a, int left, int right, int* tmp);
void MergeSort(int* a, int n);
void MergeSortNonR(int* a, int n);
void MergesortFile(const char* file);//外排序

//计数排序
void CountSort(int* a, int n);

//桶排序
void BucketSort(int* a, int n);

//基数排序
void RadixSort(int* a, int n);

//打印数组
void PrintArray(int* a, int n);

//交换
void Swap(int* a, int* b);

//猴子排序:随机打乱数组，检查是否有序，直到有序为止
bool isSorted(int* a, int n);
void shuffle(int* a, int n);
void MonkeySort(int* a, int n);