#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
////用递归将10进制转换为2进制
//void binary(int n)
//{
//	if (n > 1)
//	{
//		binary(n / 2);
//	}
//	printf("%d", n % 2);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	binary(n);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("交换前:a=%d b=%d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("交换后:a=%d b=%d", a, b);
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int count = 0;
//    for (int i = 0; i < 32; i++)
//    {
//        if (n&(1<<i))
//        {
//            count++;
//        }
//    }
//    printf("%d", count);
//    return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int odd_number[16] = { 0 };
//	int even_number[16] = { 0 };
//	int i = 0;
//	for (i = 0; i < 32; i += 2)
//	{
//		odd_number[i / 2] = (num >> i) & 1;
//	}
//	for (i = 1; i < 32; i += 2)
//	{
//		even_number[i / 2] = (num >> i) & 1;
//	}
//	printf("奇数位:");
//	for (i = 15; i >= 0; i--)
//	{
//		printf("%d ", even_number[i]);
//	}
//	printf("\n");
//	printf("偶数位:");
//	for (i = 15; i >= 0; i--)
//	{
//		printf("%d ", odd_number[i]);
//	}
//	return 0;
//}

//#include<stdio.h>
////求两个整数二进制格式有多少个位不同
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	int count = 0;
//	int ab = a ^ b;
//	for (int i = 0; i <= 31; i++)
//	{
//		if (ab & (1 << i))
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}
