#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main()
//{
//	int* p = (int*)malloc(40);//malloc���ص���void*���ͣ�����Ҫǿת
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		p[i] = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", p[i]);
//	}
//	free(p);
//	p = NULL;//��ֹҰָ��
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int* p = (int*)calloc(10,sizeof(int));//calloc��ʼ��Ϊ0
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", p[i]);
	}
	//�ռ䲻������Ҫ����
	int* ptr = (int*)realloc(p, 20*sizeof(int));//������p���գ�Ҫ���µ�ָ��
	//realloc���Ȱ�ԭ���Ŀռ俽�����µĿռ䣬���ͷ�ԭ���Ŀռ�
	//����µĿռ����ʧ�ܣ�ԭ���Ŀռ仹�ڣ�����Ҫ���µ�ָ�����
	//����µĿռ����ɹ���ԭ���Ŀռ���ͷ��ˣ�����Ҫ���µ�ָ�����
	if (ptr == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	else
	{
		p = ptr;
	}

	free(p);
	p = NULL;//��ֹҰָ��
	return 0;
}