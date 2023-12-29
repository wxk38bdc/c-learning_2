#define _CRT_SECURE_NO_WARNINGS 1

#include"stack.h"
#include"queue.h"
void test1()
{
	//后进先出是相对入的时候在栈里的数据
//先进先出是相对入的时候在队列里的数据
	stack st;
	stackInit(&st);
	stackPush(&st, 1);
	stackPush(&st, 2);
	stackPush(&st, 3);
	stackPush(&st, 4);

	while(!stackEmpty(&st))
	{
		printf("%d ", stackTop(&st));
		stackPop(&st);
	}
	stackDestroy(&st);
}
void test2()
{
	queue qu;
	queueInit(&qu);
	queuePush(&qu, 1);
	queuePush(&qu, 2);
	queuePush(&qu, 3);
	queuePush(&qu, 4);

	while (!queueEmpty(&qu))
	{
		printf("%d ", queueFront(&qu));
		queuePop(&qu);
	}
	queueDestroy(&qu);

}
int main()
{
	//test1();
	test2();
	return 0;
}