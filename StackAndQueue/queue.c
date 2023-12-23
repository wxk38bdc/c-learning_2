#define _CRT_SECURE_NO_WARNINGS 1
#include"queue.h"
void queueInit(queue* pq)
{
	assert(pq);
	pq->_head = pq->_tail = NULL;
}
void queueDestroy(queue* pq)
{
	queueNode* cur = pq->_head;
	while (cur)
	{
		queueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_head = pq->_tail = NULL;
}
void queuePush(queue* pq, QDataType x)
{
	assert(pq);
	queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
	if (newNode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newNode->_data = x;
	newNode->_next = NULL;
	if (pq->_head == NULL)
	{
		pq->_head = pq->_tail = newNode;
	}
	else
	{
		pq->_tail->_next = newNode;
		pq->_tail = newNode;
	}
}
void queuePop(queue* pq)
{
	assert(pq && pq->_head);
	queueNode*next = pq->_head->_next;
	free(pq->_head);
	pq->_head = next;
	if(pq->_head==NULL)
	{
		pq->_tail = NULL;
	}
}
QDataType queueFront(queue* pq)
{
	assert(pq && pq->_head);
	return pq->_head->_data;
}
QDataType queueBack(queue* pq)
{
	assert(pq && pq->_tail);
	return pq->_tail->_data;
}
int queueEmpty(queue* pq)
{
	assert(pq);
	return pq->_head == NULL ? 1 : 0;
}
int queueSize(queue* pq)
{
	assert(pq);
	queueNode* cur = pq->_head;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}