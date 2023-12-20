#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//long long func(int n)
//{
//	long long ret = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (n % i == 0)
//		{
//			ret++;
//		}
//	}
//	return ret;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	long long sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		sum += func(i);
//	}
//	printf("%lld\n", sum);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//    int n = 0;
//    scanf("%d", &n);
//
//    // 使用 malloc 动态分配内存
//    long long* factorCounts = (long long*)malloc((n + 1) * sizeof(long long));
//    if (factorCounts == NULL) {
//        // 如果内存分配失败，则退出
//        printf("Memory allocation failed\n");
//        return 1;
//    }
//
//    // 初始化因数计数数组
//    for (int i = 0; i <= n; i++) {
//        factorCounts[i] = 0;
//    }
//
//    // 计算每个数的因数数量
//    for (int i = 1; i <= n; i++) {
//        for (int j = i; j <= n; j += i) {
//            factorCounts[j]++;
//        }
//    }
//
//    // 计算总的因数数量
//    long long sum = 0;
//    for (int i = 1; i <= n; i++) {
//        sum += factorCounts[i];
//    }
//
//    printf("%lld\n", sum);
//
//    // 释放动态分配的内存
//    free(factorCounts);
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//void reverse(char*left)
//{
//	int len=strlen(left);
//	char* right = left + len - 1;
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void processstrings(char* str)
//{
//	int leadzero = 0;
//	int len = strlen(str);
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		if (str[i] != '0')
//		{
//			break;
//		}
//		else {
//			leadzero++;
//		}
//	}
//
//	if (leadzero == len)
//	{
//		str[1] = '\0';
//	}
//
//	else if (leadzero > 0 && leadzero < len)
//	{
//		for (i = 0; i < len - leadzero; i++)
//		{
//			str[i] = str[i + leadzero];
//		}
//		str[len - leadzero] = '\0';
//	}
//}
//int main()
//{
//	char s[30] = { 0 };
//	scanf("%s", s);
//	int flag = 0;
//	int len = strlen(s);
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		if(s[i]=='.')
//		{
//			flag = 1;
//			break;
//		}
//		if (s[i] == '/')
//		{
//			flag = 2;
//			break;
//		}
//		if(s[i]=='%')
//		{
//			flag = 3;
//			break;
//		}
//	}
//	if (flag == 0)
//	{
//		reverse(s);
//		processstrings(s);
//		printf(s);
//	}
//	else if (flag == 1)
//	{
//		char* s1 = strtok(s, ".");
//		char* s2 = strtok(NULL, ".");
//		reverse(s1);
//		processstrings(s1);
//		reverse(s2);
//		for(i=strlen(s2)-1;i>=0;i--)
//		{
//			if (s2[i] != '0')
//			{
//				break;
//			}
//			else if(i>=1)
//			{
//				s2[i] = '\0';
//			}
//		}
//		printf("%s.", s1);
//		printf("%s", s2);
//	}
//else if (flag == 2)
//	{
//		char* s1 = strtok(s, "/");
//		char* s2 = strtok(NULL, "/");
//		reverse(s1);
//		processstrings(s1);
//		reverse(s2);
//		processstrings(s2);
//		printf("%s/", s1);
//		printf("%s", s2);
//	}
//	else if (flag == 3)
//	{
//		char* s1 = strtok(s, "%");
//		reverse(s1);
//		processstrings(s1);
//		printf("%s%%", s1);
//	}
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char tofind[11] = { 0 };
	char str[100001] = { 0 };
	fgets(tofind, 11, stdin);
	fgets(str, 100001, stdin);
	int lent=strlen(tofind);
	int lens = strlen(str);
	int i = 0;
	int j = 0;
	for (i = 0; i < lent; i++)
	{
		tofind[i]=tolower(tofind[i]);
	}
	for (i = 0; i < lens; i++)
	{
		str[i] = tolower(str[i]);
	}
	tofind[lent - 1] = '\0';
	lent--;
	str[lens - 1] = '\0';
	lens--;
	int space[10000] = { 0 };//存储每个单词前的空格数
    int inWord = 0; // 标记是否在单词内部
    for (i = 0; i < lens; i++) {
        if (str[i] == ' ') {
            if (inWord) {
                // 如果之前在单词中，现在遇到空格，表示单词结束
                inWord = 0;
                j++; // 移动到下一个单词
            }
            else {
                // 如果不在单词中，累加空格数量
                space[j]++;
            }
        }
        else {
            // 如果不是空格，标记正在处理单词
            inWord = 1;
        }
    }
    // 确保单词结束时索引正确
    if (inWord) {
        j++;
    }
    for (i = 0; i < j; i++)
    {
        if (i != 0)
        {
            space[i]++;
        }
    }
	char words[10000][50] = { 0 };
	int worsnum = 0;
	
	char* p = strtok(str, " ");
	while (p != NULL)
	{
		strcpy(words[worsnum++], p);
		p = strtok(NULL, " ");
	}
	//统计单词出现的次数
	int flag = 0;
	int first_index= 0;
	int count = 0;
	for (i = 0; i < worsnum; i++)
	{
		if (strcmp(words[i], tofind) == 0)
		{
			count++;
		}
		if (count == 1&&flag==0)
		{
			flag = 1;
			first_index = i;
		}
	}
	if(count==0)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d ", count);
	//printf("%d\n", first_index);
	int sum = space;
	for (i = 0; i < first_index; i++)
	{
		sum=sum+strlen(words[i])+space[i];
	}
	printf("%d\n", sum);
	return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//int main()
//{
//char tofind[11] = { 0 };
//char str[100001] = { 0 };
//fgets(tofind, 11, stdin);
//fgets(str, 100001, stdin);
//int lent=strlen(tofind);
//int lens = strlen(str);
//int i = 0;
//    int space[10000] = { 0 }; // 存储每个单词前的空格数
//    int j = 0; // 单词索引
//    int inWord = 0; // 标记是否在单词内部
//
//    for (i = 0; i < lens; i++) {
//        if (str[i] == ' ') {
//            if (inWord) {
//                // 如果之前在单词中，现在遇到空格，表示单词结束
//                inWord = 0;
//                j++; // 移动到下一个单词
//            }
//            else {
//                // 如果不在单词中，累加空格数量
//                space[j]++;
//            }
//        }
//        else {
//            // 如果不是空格，标记正在处理单词
//            inWord = 1;
//        }
//    }
//    // 确保单词结束时索引正确
//    if (inWord) {
//        j++;
//    }
//    for (i = 0; i < j; i++)
//    {
//        if (i != 0)
//        {
//            space[i]++;
//        }
//    }
//    //输出每个单词前的空格数
//for (i = 0; i < j; i++) {
//    printf("%d ", space[i]);
//}
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//
//int main() {
//    char tofind[11] = { 0 };
//    char str[100001] = { 0 };
//    fgets(tofind, 11, stdin);
//    fgets(str, 100001, stdin);
//
//    // 移除换行符
//    if (str[strlen(tofind) - 1] == '\n') tofind[strlen(tofind) - 1] = '\0';
//    if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';
//
//    // 转换为小写
//    for (int i = 0; i<strlen(tofind); i++) {
//        tofind[i] = tolower(tofind[i]);
//    }
//    for (int i = 0; i<strlen(str); i++) {
//        str[i] = tolower(str[i]);
//    }
//
//    char words[10000][50] = { 0 };
//    int spaces[10000] = { 0 }; // 存储每个单词前的空格数
//    int worsnum = 0, spaceCount = 0, index = 0;
//
//    while (str[index]) {
//        if (str[index] == ' ') {
//            spaceCount++;
//            index++;
//            continue;
//        }
//
//        int wordStart = index;
//        while (str[index] && str[index] != ' ') {
//            index++;
//        }
//
//        strncpy(words[worsnum], str + wordStart, index - wordStart);
//        words[worsnum][index - wordStart] = '\0';
//        spaces[worsnum] = spaceCount;
//        spaceCount = 1; // 为下一个单词重置空格计数
//        worsnum++;
//    }
//
//    // 统计单词出现的次数
//    int first_index = -1, count = 0;
//    for (int i = 0; i < worsnum; i++) {
//        if (strcmp(words[i], tofind) == 0) {
//            count++;
//            if (first_index == -1) first_index = i;
//        }
//    }
//
//    if (count == 0) {
//        printf("-1\n");
//    }
//    else {
//        printf("%d ", count);
//        int sum = 0;
//        for (int i = 0; i <= first_index; i++) {
//            sum += strlen(words[i]) + spaces[i];
//        }
//        printf("%d\n", sum); // 不包括第一次出现单词前的空格
//    }
//
//    return 0;
//}
