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

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main()
//{
//	int* p = (int*)calloc(10,sizeof(int));//calloc��ʼ��Ϊ0
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
//	//�ռ䲻������Ҫ����
//	int* ptr = (int*)realloc(p, 20*sizeof(int));//������p���գ�Ҫ���µ�ָ��
//	//realloc���Ȱ�ԭ���Ŀռ俽�����µĿռ䣬���ͷ�ԭ���Ŀռ�
//	//����µĿռ����ʧ�ܣ�ԭ���Ŀռ仹�ڣ�����Ҫ���µ�ָ�����
//	//����µĿռ����ɹ���ԭ���Ŀռ���ͷ��ˣ�����Ҫ���µ�ָ�����
//	if (ptr == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	else
//	{
//		p = ptr;
//		printf("\n���ݳɹ�\n");
//	}
//
//	free(p);
//	p = NULL;//��ֹҰָ��
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main()
//{
//	//int*p=realloc(NULL, 20 * sizeof(int));//realloc(NULL,20)�ȼ���malloc(20)
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
//	static char p[] = "hello world!";//��static�洢�ڳ�������������������
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
//	int a[];//���������Ա
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
//    int** arr = (int**)malloc(3 * sizeof(int*)); // Ϊ�з����ڴ�
//    for (int i = 0; i < 3; i++)
//    {
//        arr[i] = (int*)malloc(5 * sizeof(int)); // Ϊ�з����ڴ�
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
//    // �ͷŷ�����ڴ�
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
//	//���ļ���д������
//	//FILE* pf = fopen("D:\\Windows����\\1.txt", "r");
//	FILE* pf = fopen("data.txt", "r");
//	//����ļ���ʧ�ܣ�����NULL
//	if (pf == NULL)
//	{
//		perror("���ļ�ʧ��");
//		return 1;
//	}
//	//��ȡ�ļ�
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
//		perror("��data1ʧ��");
//		return 1;
//	}
//	FILE* pfwrite = fopen("data2.txt", "w");
//	if (pfwrite == NULL)
//	{
//		fclose(pfread);//�ر��ļ�
//		pfread = NULL;//��ֹҰָ��
//		perror("��data2ʧ��");
//		return 1;
//	}
//	//data1.txt->data2.txt
//	char ch = 0;
//	while (ch = fgetc(pfread) != EOF)//��ȡ�ļ�
//	{
//		fputc(ch, pfwrite);//д���ļ�
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
//		perror("���ļ�ʧ��");
//		return 1;
//	}
//	char str[20] = { 0 };
//	//��ȡ�ļ�
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
//		perror("���ļ�ʧ��");
//		return 1;
//	}
//	//�����Ƶķ�ʽд��
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
//		perror("���ļ�ʧ��");
//		return 1;
//	}
//	//�����Ƶķ�ʽ��ȡ
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
//		perror("��data.txtʧ��");
//		return 1;
//	}
//	FILE* pwrite = fopen("data_copy.txt", "w");
//	if (pwrite == NULL)
//	{
//		fclose(pread);
//		pread = NULL;
//		perror("��data_copy.txtʧ��");
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