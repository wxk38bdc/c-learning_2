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
QDataType queueFront(queue* pq);//返回队头元素
QDataType queueBack(queue* pq);//返回队尾元素
int queueEmpty(queue* pq);//判断队列是否为空,为空返回1，否则返回0
int queueSize(queue* pq);//返回队列中元素的个数

#endif // !QUEUE_H