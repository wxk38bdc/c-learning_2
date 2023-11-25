#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int main()
//{
//    char str1[] = "hello world.";
//    char str2[] = "hello world.";
//    const char* str3 = "hello world.";
//    const char* str4 = "hello world.";
//
//    if (str1 == str2)
//        printf("str1 and str2 are same\n");
//    else
//        printf("str1 and str2 are not same\n");
//
//    if (str3 == str4)
//        printf("str3 and str4 are same\n");
//    else
//        printf("str3 and str4 are not same\n");
//
//    return 0;
//}


//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//char* my_strcat(char* dest, const char* src)
//{
//	char* tmp = dest;
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	while (*src)
//	{
//		*dest++ = *src++;
//	}
//	*dest = '\0';
//	return tmp;
//}
//int main()
//{
//	char arr[20] = { 0 };
//	char arr1[] = "hello ";
//	char arr2[] = "world";
//	strcpy(arr, arr1);
//	my_strcat(arr, arr2);
//	printf("%s", arr);
//	return 0;
//}

//int my_strcmp2(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 && *str2 && *str1 == *str2)
//	{
//		str1++;
//		str2++;
//	}
//	return *str1 - *str2;
//}

//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	return *str1 - *str2;
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcde";
//	char arr3[] = "abcdefg";
//	int ret1 = my_strcmp(arr1, arr2);
//	int ret2 = my_strcmp(arr1, arr3);
//	printf("%d\n", ret1);
//	printf("%d\n", ret2);
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//char*my_strstr(const char* str1, const char* str2)
//{
//	char* cp = (char*)str1;
//	char* s1 = NULL;
//	char* s2 = NULL;
//	if (*str2 == '\0')
//	{
//		return NULL;
//	}
//	while (*cp)
//	{
//		s1 = cp;
//		s2 = (char*)str2;
//		//处理特殊情况
//		while (*s1 && *s2 && (*s1 == *s2))
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return cp;
//		}
//		cp++;
//	}
//	return NULL;
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "bcdef";
//	char* ret = my_strstr(arr1, arr2);
//	printf("%s", ret);
//	return 0;
//}

//#include<stdio.h>
//int my_strlen(const char* str)
//{
//	int count = 0;
//	while (*str++)
//	{
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abcdddddaaa";
//	int ret = my_strlen(arr);
//	printf("%d", ret);
//	return 0;
//}


//#include<stdio.h>
//#include<assert.h>
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*dest++ = *src++);
//	return ret;
//}
//int main()
//{
//	char arr1[] = "xxxxxxxxxxxx";
//	char arr2[] = "abcdef";
//	my_strcpy(arr1, arr2);
//	printf("%s", arr1);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char str[] = "This is a simple string";
//	char* pch;
//	pch = strstr(str, "simple");
//	strncpy(pch, "sample", 6);
//	printf("%s\n", str);
//	return 0;
//}
//输出：This is a sample string

#include<stdio.h>
#include<string.h>
char* my_strtok(char* str, const char* p)
{
	static char* pStart = NULL;
	if (str != NULL)
	{
		pStart = str;
	}
	if (pStart == NULL)
	{
		return NULL;
	}
	char* ret = pStart;
	while (*pStart)
	{
		const char* tmp = p;
		while (*tmp)
		{
			if (*tmp == *pStart)
			{
				*pStart = '\0';
				pStart++;
				return ret;
			}
			tmp++;
		}
		pStart++;
	}
	if (*pStart == '\0')
	{
		pStart = NULL;
		return ret;
	}
}
int main()
{
	char arr[] = "zhangsan@qq.com";
	char tmp[50] = { 0 };
	strcpy(tmp, arr);
	const char* p = "@.";
	char* ret = NULL;
	for(ret = strtok(tmp, p); ret != NULL; ret = strtok(NULL, p))
	{
		printf("%s\n", ret);
	}
	return 0;
}