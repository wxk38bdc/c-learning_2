#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void SLTest01()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 5);
	SLPrint(&sl);
	SLPopFront(&sl);
	SLPrint(&sl);

}
int main()
{
	SLTest01();
	return 0;
}