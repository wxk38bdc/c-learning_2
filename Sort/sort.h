#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<time.h>//����������Ĳ���

//��������
void InsertSort(int* a, int n);

//ϣ������
void ShellSort(int* a, int n);

//ѡ������
void SelectSort(int* a, int n);

//������
void AdjustDown(int* a, int n, int root);
void HeapSort(int* a, int n);

//ð������
void BubbleSort(int* a, int n);

//��������
int GetMidIndex(int* a, int begin, int end);
int PartSort1(int* a, int begin, int end);
int PartSort2(int* a, int begin, int end);
int PartSort3(int* a, int begin, int end);
void QuickSort(int* a, int left, int right);
void QuickSortNonR(int* a, int left, int right);//�ǵݹ��������

//�鲢����
void Merge(int* a, int left, int mid, int right, int* tmp);
void _MergeSort(int* a, int left, int right, int* tmp);
void MergeSort(int* a, int n);
void MergeSortNonR(int* a, int n);

//��������
void CountSort(int* a, int n);

//Ͱ����
void BucketSort(int* a, int n);

//��������
void RadixSort(int* a, int n);

//��ӡ����
void PrintArray(int* a, int n);

//����
void Swap(int* a, int* b);