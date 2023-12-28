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
//    char clipboard[201]; // ¼ôÌù°å
//    int clipIndex = 0;
//
//    // ¼ôÇÐ²Ù×÷
//    for (int i = cutStart - 1; i < cutEnd; i++) {
//        clipboard[clipIndex++] = str[i];
//        for (int j = i; j < len; j++) {
//            str[j] = str[j + 1];
//        }
//        i--;
//        cutEnd--;
//        len--;
//    }
//    clipboard[clipIndex] = '\0'; // ½áÊø¼ôÌù°å×Ö·û´®
//
//    // Õ³Ìù²Ù×÷
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
//        insertPos = strlen(str); // Èç¹ûÎ´ÕÒµ½£¬ÔòÉèÖÃÎª×Ö·û´®Ä©Î²
//    }
//
//    // ÔÚinsertPosÎ»ÖÃ²åÈëclipboardÄÚÈÝ
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
