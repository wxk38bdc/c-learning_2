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

//#include<stdio.h>
//#include<string.h>
//char* my_strtok(char* str, const char* p)
//{
//	static char* pStart = NULL;
//	if (str != NULL)
//	{
//		pStart = str;
//	}
//	if (pStart == NULL)
//	{
//		return NULL;
//	}
//	char* ret = pStart;
//	while (*pStart)
//	{
//		const char* tmp = p;
//		while (*tmp)
//		{
//			if (*tmp == *pStart)
//			{
//				*pStart = '\0';
//				pStart++;
//				return ret;
//			}
//			tmp++;
//		}
//		pStart++;
//	}
//	if (*pStart == '\0')
//	{
//		pStart = NULL;
//		return ret;
//	}
//}
//int main()
//{
//	char arr[] = "zhangsan@qq.com";
//	char tmp[50] = { 0 };
//	strcpy(tmp, arr);
//	const char* p = "@.";
//	char* ret = NULL;
//	for(ret = strtok(tmp, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<errno.h>
//int main()
//{
//	char s[50]= { 0 };
//	fgets(s, 50, stdin);
//	FILE* pf = fopen(s, "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		printf("open success\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//void* my_memcpy(void* dest, const void* src, size_t count)
//{
//	assert(dest && src);
//	void* ret = dest;
//	while (count--)
//	{
//		*(char*)dest = *(char*)src;
//		((char*)dest)++;
//		((char*)src)++;
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[10]={1,2,3,4,5,6,7,8,9,10};
//	int arr2[10] = { 0 };
//	my_memcpy(arr2, arr1 + 5, 5 * sizeof(int));
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//void* my_memmove(void* dest, const void* src, size_t count)
//{
//	assert(dest && src);
//	void* ret = dest;
//	if (dest <= src || (char*)dest >= (char*)src + count)
//	{
//		while (count--)
//		{
//			*(char*)dest = *(char*)src;
//			((char*)dest)++;
//			((char*)src)++;
//		}
//	}
//	else
//	{
//		while (count--)
//		{
//			*((char*)dest + count) = *((char*)src + count);
//		}
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr1 + 2, arr1, 5 * sizeof(int));
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}

////检测大小端字节序
//#include<stdio.h>
//int check_sys()
//{
//	int a = 1;
//	return *(char*)&a;
//}
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("小端字节序\n");
//	}
//	else
//	{
//		printf("大端字节序\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("a=%d,b=%d,c=%d", a, b, c);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//    char a[1000] = { 0 };
//    int i = 0;
//    for (i = 0; i < 1000; i++)
//    {
//        a[i] = -1 - i;
//    }
//    printf("%d", strlen(a));
//    return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//char* my_strncpy(char* dest, const char* src, size_t count)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (count--)
//	{
//		*dest++ = *src++;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[] = "xxxxxxxxxx";
//	char arr2[] = "abcdef";
//	my_strncpy(arr1 + 3, arr2, 3);
//	printf("%s", arr1);
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//char* my_strncat(char* dest, const char* src, size_t count)
//{
//	assert(dest && src);
//	char* tmp = dest;
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	while (count--)
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
//	char arr2[] = "worldxxxxx";
//	strcpy(arr, arr1);
//	my_strncat(arr, arr2, 5);
//	printf("%s", arr);
//	return 0;
//}

//#include<stdio.h>
//int int_cmp(const void* p1, const void* p2)
//{
//	return (*(int*)p1 - *(int*)p2);
//}
//void _swap(void* p1, void* p2, int size)
//{
//	int i = 0;
//	for (i = 0; i < size; i++)
//	{
//		char tmp = *((char*)p1 + i);
//		*((char*)p1 + i) = *((char*)p2 + i);
//		*((char*)p2 + i) = tmp;
//	}
//}
//void bubble(void* base, int count, int size, int(*cmp)(void*, void*))
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < count - 1; i++)
//	{
//		for (j = 0; j < count - i - 1; j++)
//		{
//			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)
//			{
//				_swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
//	int i = 0;
//	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//	printf("%s\n", **++cpp);
//	printf("%s\n", *-- * ++cpp + 3);
//	printf("%s\n", *cpp[-2] + 3);
//	printf("%s\n", cpp[-1][-1] + 1);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int main() {
//    const char* string1 = "Hello";
//    const char* string2 = "Heaven";
//
//    int result = strncmp(string1, string2, 3); // 比较前3个字符
//
//    if (result == 0)
//    {
//        printf("Strings are equal.\n");
//    }
//    else if (result < 0)
//    {
//        printf("String1 is less than String2.\n");
//    }
//    else
//    {
//        printf("String1 is greater than String2.\n");
//    }
//
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//char* my_strstr(const char* str1, const char* str2)
//{
//    while (*str1 != '\0')
//    {
//        const char* h = str1;
//        const char* n = str2;
//
//        // 逐个比较字符
//        while (*n != '\0' && *h == *n)
//        {
//            h++;
//            n++;
//        }
//
//        // 如果子字符串结束，表示完全匹配
//        if (*n == '\0')
//        {
//            return (char*)str1;
//        }
//
//        str1++;
//    }
//
//    return NULL; // 未找到子字符串
//}
//int main() {
//    const char* haystack = "Hello, World!";
//    const char* needle = "0";
//
//    char* result = my_strstr(haystack, needle);
//
//    if (result != NULL) {
//        printf("Substring found at position: %ld\n", result - haystack);
//    }
//    else {
//        printf("Substring not found.\n");
//    }
//
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//    char str[] = "Hello,World,Token";
//    const char delimiters[] = ",";
//
//    // 第一次调用，分解字符串
//    char* token = strtok(str, delimiters);
//
//    while (token != NULL)
//    {
//        printf("Token: %s\n", token);
//
//        // 后续调用，继续分解字符串
//        token = strtok(NULL, delimiters);
//    }
//
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//    // 模拟一个错误码
//    int errnum = 2;
//
//    // 使用 strerror 获取错误消息字符串
//    const char* error_message = strerror(errnum);
//
//    // 打印错误消息
//    printf("Error Message: %s\n", error_message);
//
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int main() {
//    char source[] = "Hello, World!";
//    char destination[20];
//
//    // 使用 memcpy 复制数据
//    memcpy(destination, source, sizeof(source));
//
//    printf("Source: %s\n", source);
//    printf("Destination: %s\n", destination);
//
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//int main()
//{
//	char arr[100][50]= { 0 };
//	int i = 0;
//	while(scanf("%s", arr[i]) != EOF)
//	{
//		i++;
//	}
//	for (int j = i-1; j >=0 ; j--)
//	{
//		printf("%s ", arr[j]);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int lengthOfLastWord(char* s) {
//    int len = strlen(s);
//    int i = len - 1;
//    int count = 0;
//
//    // 跳过末尾的空格
//    while (i >= 0 && s[i] == ' ') {
//        i--;
//    }
//
//    // 计算最后一个单词的长度
//    while (i >= 0 && s[i] != ' ') {
//        count++;
//        i--;
//    }
//
//    return count;
//}
//
//int main()
//{
//	char *arr = "l";
//	int ret = lengthOfLastWord(arr);
//	printf("%d", ret);
//	return 0;
//}

//#include<stdio.h>
////X86环境，小端字节序
//int main()
//{
//	int a[4] = { 1,2,3,4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int n = 9;
//	float* pFloat = (float*)&n;
//	printf("n的值为：%d\n", n);
//	printf("*pFloat的值为：%f\n", *pFloat);
//	*pFloat = 9.0;
//	printf("num的值为：%d\n", n);
//	printf("*pFloat的值为：%f\n", *pFloat);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	float f = 99.7;
//	printf("%f\n", f);
//	return 0;
//}

//#include <stdio.h>
//struct stu
//{
//	int num;
//	char name[10];
//	int age;
//};
//
//void fun(struct stu* p)
//{
//	printf("%s\n", (*p).name);
//	return;
//}
//
//int main()
//{
//	struct stu students[3] = { {9801,"zhang",20},
//							 {9802,"wang",19},
//					{9803,"zhao",18} };
//	fun(students + 1);
//	return 0;
//}

//#include <stdio.h>
//#include<string.h>
//int my_atoi(const char* str)
//{
//	int flag = 1;
//	int ret = 0;
//	int isnum = 0;//标记是否有数字
//	while (*str == ' ')
//	{
//		str++;
//	}
//	if (*str == '-')
//	{
//		flag = -1;
//		str++;
//	}
//	else if (*str == '+')
//	{
//		str++;
//	}
//	while (*str>='0'&&*str<='9')
//	{
//		isnum = 1;
//		ret = ret * 10 + *str - '0';
//		str++;
//	}
//	if (isnum == 0)
//	{
//		return 0;
//	}
//	return ret * flag;
//}
//int main()
//{
//	char arr[100] = { 0 };
//	fgets(arr, 100, stdin);
//	int ret = my_atoi(arr);
//	printf("%d", ret);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int num = 0x12345678;
//	return 0;
//}





