#define _CRT_SECURE_NO_WARNINGS 1

#include"stack.h"
//��ʼ��
void stackInit(stack* pst)
{
	assert(pst);
	pst->_a = (STDataType*)malloc(sizeof(STDataType) * 4);
	pst->_top = 0;
	pst->_capacity = 4;
}
//����
void stackDestroy(stack* pst)
{
	assert(pst);
	free(pst->_a);
	pst->_a = NULL;
	pst->_top = pst->_capacity = 0;
}
//��ջ
void stackPush(stack* pst, STDataType x) 
{
	assert(pst);
	if (pst->_top == pst->_capacity) 
	{
		// ����
		pst->_capacity *= 2;
		STDataType* tmp = (STDataType*)realloc(pst->_a, sizeof(STDataType) * pst->_capacity);
		if (tmp == NULL) 
		{
			printf("realloc fail\n");
			exit(-1);
		}
		pst->_a = tmp;
	}
	pst->_a[pst->_top] = x;
	pst->_top++;
}

//��ջ
void stackPop(stack* pst)
{
	assert(pst);
	assert(pst->_top > 0);
	pst->_top--;
}
int stackSize(stack* pst)
{
	assert(pst);
	return pst->_top;
}
int stackEmpty(stack* pst)
{
	assert(pst);
	//�ǿ�ջ����1�����Ƿ���0
	return pst->_top == 0 ? 1 : 0;
}
STDataType stackTop(stack* pst)
{
	assert(pst);
	assert(pst->_top > 0);
	return pst->_a[pst->_top - 1];
}