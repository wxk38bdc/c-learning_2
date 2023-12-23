#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int QDataType;
typedef struct queueNode
{
	QDataType _data;
	struct queueNode* _next;
}queueNode;

typedef struct queue
{
	queueNode* _head;
	queueNode* _tail;
}queue;

void queueInit(queue* pq);
void queueDestroy(queue* pq);
void queuePush(queue* pq, QDataType x);
void queuePop(queue* pq);
QDataType queueFront(queue* pq);//���ض�ͷԪ��
QDataType queueBack(queue* pq);//���ض�βԪ��
int queueEmpty(queue* pq);//�ж϶����Ƿ�Ϊ��,Ϊ�շ���1�����򷵻�0
int queueSize(queue* pq);//���ض�����Ԫ�صĸ���

#endif // !QUEUE_H