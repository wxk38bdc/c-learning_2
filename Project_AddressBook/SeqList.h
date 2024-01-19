#pragma once
#include"Contact.h"

typedef struct PersonInfo SLDataType;
//��̬˳���
typedef struct SeqList
{
	SLDataType* arr;//��̬���ٵ�����
	size_t size;//��ЧԪ�ظ���
	size_t capacity;//����
}SL,Contact;

//��ʼ��
void SLInit(SL* ps);
//����
void SLDestory(SL* ps);
//�ж�����
void SLCheckCapacity(SL* ps);
//��ӡ
void SLPrint(SL* ps);
//β��
void SLPushBack(SL* ps, SLDataType x);
//βɾ
void SLPopBack(SL* ps);
//ͷ��
void SLPushFront(SL* ps, SLDataType x);
//ͷɾ
void SLPopFront(SL* ps);
//����
int SLFind(SL* ps, SLDataType x);
//��posλ�ò���x
void SLInsert(SL* ps, size_t pos, SLDataType x);
//ɾ��posλ�õ�Ԫ��
void SLErase(SL* ps, size_t pos);
