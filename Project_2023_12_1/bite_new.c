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

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main()
//{
//	int* p = (int*)calloc(10,sizeof(int));//calloc初始化为0
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", p[i]);
//	}
//	//空间不够，想要扩容
//	int* ptr = (int*)realloc(p, 20*sizeof(int));//不能用p接收，要用新的指针
//	//realloc会先把原来的空间拷贝到新的空间，再释放原来的空间
//	//如果新的空间分配失败，原来的空间还在，所以要用新的指针接收
//	//如果新的空间分配成功，原来的空间就释放了，所以要用新的指针接收
//	if (ptr == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	else
//	{
//		p = ptr;
//		printf("\n扩容成功\n");
//	}
//
//	free(p);
//	p = NULL;//防止野指针
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main()
//{
//	//int*p=realloc(NULL, 20 * sizeof(int));//realloc(NULL,20)等价于malloc(20)
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//char* GetMemory(void)
//{
//	static char p[] = "hello world!";//加static存储在常量区，出作用域不销毁
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int* test(int** p)
//{
//	**p = 10086;
//	return *p;
//}
//int main()
//{
//	int n = 0;
//	int* tmp = &n;
//	tmp = test(&tmp);
//	printf("hello\n");
//	printf("%d", *tmp);
//	return 0;
//}

//#include <stdio.h>
//#include<stdlib.h>
//#include<string.h>
//typedef struct stu {
//	char name[20];
//	int age;
//	int a[];//柔性数组成员
//}stu;
//int main()
//{
//	stu* ps = (stu*)malloc(sizeof(stu) + 10 * sizeof(int));
//	strcpy(ps->name , "zhangsan");
//	
//	ps->age = 20;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		ps->a[i] = 2 * i + 1;
//	}
//	printf("%s\n",ps->name);
//	printf("%d\n", ps->age);
//	for(i=0;i<10;i++)
//		printf("%d ", ps->a[i]);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//    int** arr = (int**)malloc(3 * sizeof(int*)); // 为行分配内存
//    for (int i = 0; i < 3; i++)
//    {
//        arr[i] = (int*)malloc(5 * sizeof(int)); // 为列分配内存
//    }
//    int num = 1;
//    for (int i = 0; i < 3; i++)
//    {
//        for (int j = 0; j < 5; j++)
//        {
//            arr[i][j] = num;
//            num++;
//        }
//    }
//    for (int i = 0; i < 3; i++)
//    {
//        for (int j = 0; j < 5; j++)
//        {
//            printf("%2d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//    // 释放分配的内存
//    for (int i = 0; i < 3; i++)
//    {
//        free(arr[i]);
//    }
//    free(arr);
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//int* getConcatenation(int* nums, int numsSize, int* returnSize) {
//	int* ans = realloc(NULL, 2 * numsSize * sizeof(int));
//	int i = 0;
//	for (i = 0; i < numsSize; i++)
//	{
//		ans[i] = nums[i];
//	}
//	for (i = numsSize; i < numsSize * 2; i++)
//	{
//		ans[i] = nums[i - numsSize];
//	}
//	return ans;
//}