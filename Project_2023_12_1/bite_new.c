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

//#include <stdio.h>
//int main()
//{
//	//打开文件，写入数据
//	//FILE* pf = fopen("D:\\Windows桌面\\1.txt", "r");
//	FILE* pf = fopen("data.txt", "r");
//	//如果文件打开失败，返回NULL
//	if (pf == NULL)
//	{
//		perror("打开文件失败");
//		return 1;
//	}
//	//读取文件
//	for (int i = 0; i < 10; i++)
//	{
//		int ch = fgetc(pf);
//		printf("%c", ch);
//	}
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	FILE* pfread = fopen("data1.txt", "r");
//	if (pfread == NULL)
//	{
//		perror("打开data1失败");
//		return 1;
//	}
//	FILE* pfwrite = fopen("data2.txt", "w");
//	if (pfwrite == NULL)
//	{
//		fclose(pfread);//关闭文件
//		pfread = NULL;//防止野指针
//		perror("打开data2失败");
//		return 1;
//	}
//	//data1.txt->data2.txt
//	char ch = 0;
//	while (ch = fgetc(pfread) != EOF)//读取文件
//	{
//		fputc(ch, pfwrite);//写入文件
//	}
//
//	fclose(pfread);
//	pfread = NULL;
//	fclose(pfwrite);
//	pfwrite = NULL;
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		perror("打开文件失败");
//		return 1;
//	}
//	char str[20] = { 0 };
//	//读取文件
//	fgets(str, 20, pf);
//	printf("%s", str);//hello world
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//#include <stdio.h>
//typedef struct stu
//{
//	char name[20];
//	int age;
//	float score;
//}stu;
//stu s = { "zhangsan", 20,66.6};
//int main()
//{
//	FILE* pf = fopen("data.txt", "wb");
//	if (pf == NULL)
//	{
//		perror("打开文件失败");
//		return 1;
//	}
//	//二进制的方式写入
//	fwrite(&s, sizeof(stu), 1, pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//#include <stdio.h>
//typedef struct stu
//{
//	char name[20];
//	int age;
//	float score;
//}stu;
//int main()
//{
//	stu s;
//	FILE* pf = fopen("data.txt", "rb");
//	if (pf == NULL)
//	{
//		perror("打开文件失败");
//		return 1;
//	}
//	//二进制的方式读取
//	fread(&s,sizeof(stu), 1, pf);
//	printf("%s %d %.1f\n", s.name, s.age, s.score);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	FILE* pread = fopen("data.txt", "r");
//	if (pread == NULL)
//	{
//		perror("打开data.txt失败");
//		return 1;
//	}
//	FILE* pwrite = fopen("data_copy.txt", "w");
//	if (pwrite == NULL)
//	{
//		fclose(pread);
//		pread = NULL;
//		perror("打开data_copy.txt失败");
//		return 1;
//	}
//	char str[20] = { 0 };
//	fgets(str, 20, pread);
//	fputs(str, pwrite);
//	fclose(pread);
//	pread = NULL;
//	fclose(pwrite);
//	pwrite = NULL;
//	return 0;
//}