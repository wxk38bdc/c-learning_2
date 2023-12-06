#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main()
//{
//	int* p = (int*)malloc(40);//malloc返回的是void*类型，所以要强转
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
//	p = NULL;//防止野指针
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int* p = (int*)calloc(10,sizeof(int));//calloc初始化为0
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
	//空间不够，想要扩容
	int* ptr = (int*)realloc(p, 20*sizeof(int));//不能用p接收，要用新的指针
	//realloc会先把原来的空间拷贝到新的空间，再释放原来的空间
	//如果新的空间分配失败，原来的空间还在，所以要用新的指针接收
	//如果新的空间分配成功，原来的空间就释放了，所以要用新的指针接收
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
	p = NULL;//防止野指针
	return 0;
}