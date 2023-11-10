#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main()
//{
//	char arr[20] = { 0 };
//	scanf("%s", arr);
//	int len = strlen(arr);
//	for (int i = 0; i < len; i++)
//	{
//		if ((arr[i] - '0') % 2 == 0)
//		{
//			arr[i]='0';
//		}
//		else
//		{
//			arr[i] = '1';
//		}
//	}
//	printf("%d", atoi(arr));
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	const int a = 10;
//	const int* const pa = &a;
//	int** ppa = &pa;
//	**ppa = 20;
//	printf("%d\n", a);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int arr[10]= { 0 };
//	int arr2[10] = { 0 };
//	printf("%d", &arr[9] - &arr2[0]);
//	return 0;
//}

//#include<stdio.h>
//int* test()
//{
//	int a = 10;
//	return &a;
//}
//int main()
//{
//	int* p = test();
//	printf("hehe\n");
//	printf("%d\n",*p);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int arr[] = { 1,2,3,4,5 };
//    short* p = (short*)arr;
//    int i = 0;
//    for (i = 0; i < 4; i++)
//    {
//        *(p + i) = 0;
//    }
//
//    for (i = 0; i < 5; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//	unsigned long pulArray[] = { 6,7,8,9,10 };
//	unsigned long* pulPtr;
//	pulPtr = pulArray;
//	*(pulPtr + 3) += 3;
//	printf("%d,%d\n", *pulPtr, *(pulPtr + 3));
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
////×Ö·û´®ÄæÐò
//void reverse(char* arr, int len)
//{
//	char* left = arr;
//	char* right = arr + len - 1;
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[10001] = { 0 };
//	scanf("%[^\n]", arr);
//	reverse(arr, strlen(arr));
//	printf("%s", arr);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
////×Ö·û´®×óÐý
//void left_move(char* arr, int k, int len)
//{
//	k %= len;
//	while (k--)
//	{
//		char tmp = *arr;
//		int i = 0;
//		for (i = 0; i < len - 1; i++)
//		{
//			*(arr + i) = *(arr + i + 1);
//		}
//		*(arr + len - 1) = tmp;
//	}
//}
//int main()
//{
//	char arr[100] = { 0 };
//	scanf("%s", arr);
//	int len = strlen(arr);
//	int k = 0;
//	scanf("%d", &k);
//	left_move(arr, k, len);
//	printf("%s", arr);
//	return 0;
//}

//#include <stdio.h>
//int my_strlen(char* arr)
//{
//	int count = 0;
//	while (*arr != '\0')
//	{
//		count++;
//		arr++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[100] = { 0 };
//	scanf("%s", arr);
//	int len = my_strlen(arr);
//	printf("%d", len);
//	return 0;
//}

