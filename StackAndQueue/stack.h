#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int STDataType;
typedef struct stack
{
	STDataType* _a;//动态开辟的数组
	int _top;//栈顶的下标
	int _capacity;
}stack;

void stackInit(stack* pst);//初始化
void stackDestroy(stack* pst);//销毁
void stackPush(stack* pst, STDataType x);//入栈
void stackPop(stack* pst);//出栈
int stackSize(stack* pst);//返回栈的大小
int stackEmpty(stack* pst);//返回0表示非空，返回1表示空
STDataType stackTop(stack* pst);//返回栈顶元素