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
void HeapSort(int* a, int n);

//ð������
void BubbleSort(int* a, int n);

//��������
void QuickSort(int* a, int left, int right);

//�鲢����
void MergeSort(int* a, int n);

//��������
void CountSort(int* a, int n);

//Ͱ����
void BucketSort(int* a, int n);

//��������
void RadixSort(int* a, int n);

//��ӡ����
void PrintArray(int* a, int n);