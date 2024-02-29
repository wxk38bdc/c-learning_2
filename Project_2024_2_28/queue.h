#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include<stdbool.h>
typedef int QueueDataType;
typedef struct QueueNode
{
	QueueDataType data;
	struct QueueNode* next;
}Node;

typedef struct Queue
{
	Node* head;
	Node* tail;
	size_t size;
}Queue;

void QueueInit(Queue* q)
{
	//´´½¨ÉÚ±øÎ»
	q->head = q->tail = (Node*)malloc(sizeof(Node));
	q->head->next = NULL;
	q->size = 0;
}

void QueuePush(Queue* q, QueueDataType x)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = x;
	newNode->next = NULL;
	q->tail->next = newNode;
	q->tail = newNode;
	q->size++;
}

void QueuePop(Queue* q)
{
	assert(q->head->next != NULL);
	Node* toDelete = q->head->next;
	q->head->next = toDelete->next;
	if (q->tail == toDelete)
	{
		q->tail = q->head;
	}
	free(toDelete);
	q->size--;
}

QueueDataType QueueFront(Queue* q)
{
	assert(q->head->next != NULL);
	return q->head->next->data;
}

QueueDataType QueueBack(Queue* q)
{
	assert(q->head->next != NULL);
	return q->tail->data;
}

bool QueueEmpty(Queue* q)
{
	return q->head->next == NULL;
}

size_t QueueSize(Queue* q)
{
	//Node* cur = q->head->next;
	//int count = 0;
	//while (cur != NULL)
	//{
	//	count++;
	//	cur = cur->next;
	//}
	//return count;
	return q->size;
}

void QueueDestroy(Queue* q)
{
	while (q->head->next != NULL)
	{
		QueuePop(q);
	}
	free(q->head);
	q->head = q->tail = NULL;
}

void QueuePrint(Queue* q)
{
	Node* cur = q->head->next;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void test01()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePrint(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePrint(&q);
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));
	printf("size = %d\n", QueueSize(&q));
	printf("empty = %d\n", QueueEmpty(&q));
	QueueDestroy(&q);
}