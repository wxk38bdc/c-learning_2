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