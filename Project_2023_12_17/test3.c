#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//int func(int i)
//{
//	return 2 * i * i - 1;
//}
//int main()
//{
//	int n;
//	char ch;
//	scanf("%d", &n);
//	getchar();
//	scanf("%c", &ch);
//	int num = 1;
//	while (1)
//	{
//		if (func(num) <= n && func(num + 1) > n)
//		{
//			break;
//		}
//		num++;
//	}
//	//printf("num==%d\n", num);
//	int ret = n - func(num);
//
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 2 * num - 1; i++)
//	{
//		for (j = 0; j < 2 * num - 1; j++)
//		{
//			if ((j >= i && i + j <= 2 * num - 2) || (j <= i && i + j >= 2 * num - 2))
//			{
//				printf("%c", ch);
//			}
//			else if (j > i && i + j > 2 * num - 2)
//			{
//				continue;
//			}
//			else
//			{
//				printf(" ");
//			}
//		}
//		printf("\n");
//	}
//	printf("%d\n", ret);
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int arr[10] = { 0 };
//	char str[1000] = { 0 };
//	scanf("%s", str);
//	int i = 0;
//	for(i=0;i<strlen(str);i++)
//	{
//		arr[str[i] - '0']++;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		if (arr[i] != 0)
//		{
//			printf("%d:%d\n", i, arr[i]);
//		}
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<limits.h>
//#include<stdlib.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int i = 0;
//	long long* id = (long long*)malloc(sizeof(long long) * n);
//	int* tmp = (int*)malloc(4 * n);
//	int* test = (int*)malloc(4 * n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%lld %d %d", &id[i], &tmp[i], &test[i]);
//	}
//	int m = 0;
//	scanf("%d", &m);
//	int* marr = (int*)malloc(sizeof(int) * m);
//	for (i = 0; i < m; i++)
//	{
//		scanf("%d", &marr[i]);
//	}
//	for (i = 0; i < m; i++)
//	{
//		int j = 0;
//		for (j = 0; j < n; j++)
//		{
//			if (marr[i] == tmp[j])
//			{
//				printf("%lld %d\n", id[j], test[j]);
//			}
//		}
//	}
//	free(id);
//	free(tmp);
//	free(test);
//	free(marr);
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char str1[10001] = { 0 };
//	char str2[10001] = { 0 };
//	fgets(str1, 10001, stdin);
//	str1[strlen(str1) - 1] = '\0';
//	scanf("%s", str2);
//	int i = 0;
//	int j = 0;
//	int flag = 0;
//	for (i = 0; i < strlen(str1); i++)
//	{
//		flag = 0;
//		for(j=0;j<strlen(str2);j++)
//		{
//			if (str1[i] == str2[j])
//			{
//				flag = 1;
//				break;
//			}
//		}
//		if(flag== 0)
//		{
//			printf("%c", str1[i]);
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//void cutPaste(char* str, int cutStart, int cutEnd, char* pre, char* post) {
//    int len = strlen(str);
//    char clipboard[201]; // 剪贴板
//    int clipIndex = 0;
//
//    // 剪切操作
//    for (int i = cutStart - 1; i < cutEnd; i++) {
//        clipboard[clipIndex++] = str[i];
//        for (int j = i; j < len; j++) {
//            str[j] = str[j + 1];
//        }
//        i--;
//        cutEnd--;
//        len--;
//    }
//    clipboard[clipIndex] = '\0'; // 结束剪贴板字符串
//
//    // 粘贴操作
//    int insertPos = -1;
//    char* found = strstr(str, pre);
//    while (found) {
//        if (strncmp(found + strlen(pre), post, strlen(post)) == 0) {
//            insertPos = found - str + strlen(pre);
//            break;
//        }
//        found = strstr(found + 1, pre);
//    }
//
//    if (insertPos == -1) {
//        insertPos = strlen(str); // 如果未找到，则设置为字符串末尾
//    }
//
//    // 在insertPos位置插入clipboard内容
//    char temp[201];
//    strcpy(temp, str + insertPos);
//    strcpy(str + insertPos, clipboard);
//    strcpy(str + insertPos + strlen(clipboard), temp);
//}
//
//int main() {
//    char str[201];
//    int n, cutStart, cutEnd;
//    char pre[6], post[6];
//
//    scanf("%200s", str);
//    scanf("%d", &n);
//
//    for (int i = 0; i < n; i++) {
//        scanf("%d %d %5s %5s", &cutStart, &cutEnd, pre, post);
//        cutPaste(str, cutStart, cutEnd, pre, post);
//    }
//
//    printf("%s\n", str);
//    return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int processAlice(char* str, int* arr, int len)
//{
//	int i = 0;
//	int flag = 0;
//	for (i = 0; i < len; i++)
//	{
//		if (arr[i] == 0)
//		{
//			flag = 1;
//			break;
//		}
//	}
//	if (flag == 0)
//	{
//		return -1;
//	}
//	for (i = 0; i < len; i++)
//	{
//		int j = len - 1;
//		for (j = len - 1; j >= 0; j--)
//		{
//			if (arr[j] == 0)
//			{
//				break;
//			}
//		}
//		if (arr[i] == 0)
//		{
//			if (str[i] != 'a')
//			{
//				str[i] = 'a';
//				arr[i] = 1;
//				break;
//			}
//			else if(str[i]=='a'&&i != j)
//			{
//				continue;
//			}
//			else//找到倒数第一个未修改的字符，并+1
//			{
//				str[j]++;
//				arr[j] = 1;
//			}
//		}
//	}
//	return 0;
//}
//int processBob(char* str, int* arr, int len)
//{
//	int i = 0;
//	int flag = 0;
//	for (i = 0; i < len; i++)
//	{
//		if (arr[i] == 0)
//		{
//			flag = 1;
//			break;
//		}
//	}
//	if (flag == 0)
//	{
//		return -1;
//	}
//	for (i = 0; i < len; i++)
//	{
//		int j = 0;
//		for (j = len - 1; j > 0; j--)
//		{
//			if (arr[j] == 0)
//			{
//				break;
//			}
//		}
//		if (arr[i] == 0)
//		{
//			if (str[i] != 'z')
//			{
//				str[i] = 'z';
//				arr[i] = 1;
//				break;
//			}
//			else if (str[i] == 'z' && i != j)
//			{
//				continue;
//			}
//			else//找到倒数第一个未修改的字符，并-1
//			{
//				str[j]--;
//				arr[j] = 1;
//			}
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	while (n--)
//	{
//		char str[1001] = { 0 };
//		scanf("%s", str);
//		int len = strlen(str);
//		int* arr = (int*)malloc(sizeof(int) * len);
//		memset(arr, 0, sizeof(int) * len);
//		while (1)
//		{
//			int a = processAlice(str, arr, len);
//			if (a == -1)break;
//			int b = processBob(str, arr, len);
//			if (b == -1)break;
//		}
//		printf("%s\n", str);
//		free(arr);
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//void test(int n)
//{
//	if (n == 0 || n == 1)
//	{
//		printf("1\n");
//	}
//	else
//	{
//		int a = 1;
//		int b = 1;
//		int c = a + b;
//		while (n >= 2)
//		{
//			c = a + b;
//			a = b;
//			b = c;
//			n--;
//		}
//		printf("%d\n", c);
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	test(n);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//typedef struct stu {
//	char id[39];
//	char name[39];
//	double cn;
//	double math;
//	double eng;
//} stu;
//
//void bubbleSortId(stu* array, int n) {
//	stu temp;
//
//	for (int i = 0; i < n - 1; ++i) {
//		for (int j = 0; j < n - i - 1; ++j) {
//			if (strcmp(array[j].id, array[j + 1].id) > 0) {
//				temp = array[j];
//				array[j] = array[j + 1];
//				array[j + 1] = temp;
//			}
//		}
//	}
//}
//
//void bubbleSortMath(stu* array, int n) {
//	stu temp;
//
//	for (int i = 0; i < n - 1; ++i) {
//		for (int j = 0; j < n - i - 1; ++j) {
//			if (array[j].math < array[j + 1].math) {
//				temp = array[j];
//				array[j] = array[j + 1];
//				array[j + 1] = temp;
//			}
//		}
//	}
//}
//
//void bubbleSortCn(stu* array, int n) {
//	stu temp;
//
//	for (int i = 0; i < n - 1; ++i) {
//		for (int j = 0; j < n - i - 1; ++j) {
//			if (array[j].cn < array[j + 1].cn) {
//				temp = array[j];
//				array[j] = array[j + 1];
//				array[j + 1] = temp;
//			}
//		}
//	}
//}
//
//void bubbleSortEng(stu* array, int n) {
//	stu temp;
//
//	for (int i = 0; i < n - 1; ++i) {
//		for (int j = 0; j < n - i - 1; ++j) {
//			if (array[j].eng < array[j + 1].eng) {
//				temp = array[j];
//				array[j] = array[j + 1];
//				array[j + 1] = temp;
//			}
//		}
//	}
//}
//
//void printSorted(stu* arr, int n) {
//	for (int i = 0; i < n; ++i) {
//		printf("%s %s\n", arr[i].id, arr[i].name);
//	}
//}
//
//int main() {
//	int n;
//	scanf("%d", &n);
//
//	stu s[n];
//	for (int i = 0; i < n; ++i) {
//		scanf("%s %s %lf %lf %lf", s[i].id, s[i].name, &s[i].math, &s[i].cn, &s[i].eng);
//	}
//
//	double choice;
//	scanf("%lf", &choice);
//	if (choice != 1 && choice != 2 && choice != 3) {
//		printf("ERROR\n");
//		return 1;
//	}
//	bubbleSortId(s, n);
//	if (choice == 1) {
//		bubbleSortMath(s, n);
//		printSorted(s, n);
//	}
//	else if (choice == 2) {
//		bubbleSortCn(s, n);
//		printSorted(s, n);
//	}
//	else if (choice == 3) {
//		bubbleSortEng(s, n);
//		printSorted(s, n);
//	}
//
//	return 0;
//}