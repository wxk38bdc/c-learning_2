#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//˳���
////��̬˳�����ƣ���С�̶���
//typedef int SLDataType;
//#define N 10
//
//struct SeqList
//{
//	SLDataType data[N];
//	int size;
//};

//��̬˳�����ƣ���С�ɱ䣩
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size;//��ЧԪ�ظ���
	int capacity;//����
}SL, SeqList;

void SeqListInit(SL*s);//��ʼ��
void SeqListDestory(SL* ps);//����
void SeqListPrint(SL* ps);//��ӡ
void SeqlistCheckCapacity(SL* ps);//�������
void SeqListPushBack(SL* ps, SLDataType x);//β��
void SeqListPopBack(SL* ps);//βɾ
void SeqListPushFront(SL* ps, SLDataType x);//ͷ��
void SeqListPopFront(SL* ps);//ͷɾ
void SeqListInsert(SL* ps, int pos, SLDataType x);//����λ�ò���
void SeqListErase(SL* ps, int pos);//����λ��ɾ��

