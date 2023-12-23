#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int STDataType;
typedef struct stack
{
	STDataType* _a;//��̬���ٵ�����
	int _top;//ջ�����±�
	int _capacity;
}stack;

void stackInit(stack* pst);//��ʼ��
void stackDestroy(stack* pst);//����
void stackPush(stack* pst, STDataType x);//��ջ
void stackPop(stack* pst);//��ջ
int stackSize(stack* pst);//����ջ�Ĵ�С
int stackEmpty(stack* pst);//����0��ʾ�ǿգ�����1��ʾ��
STDataType stackTop(stack* pst);//����ջ��Ԫ��