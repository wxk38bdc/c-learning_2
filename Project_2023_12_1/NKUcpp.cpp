#define _CRT_SECURE_NO_WARNINGS 1

//void print(int arr[][101], int n)
//{
//	int i = 0, j = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//	cout<<endl;
//	}
//}

//#include<iostream>
//using namespace std;
//#include<cstdio>
//#include<cstring>
////题目1 easy matrix 未通过
//int check_0(int arr[])//4个数中有几个0
//{
//	int i = 0;
//	int ret = 0;
//	for (i = 0; i < 4; i++)
//	{
//		if (arr[i] == 0)
//		{
//			ret++;
//		}
//	}
//	return ret;
//}
//int evenJudge(int arr[][101], int n)
//{
//	int i = 0, j = 0;
//	int ret = 0;
//	for (i = 0; i < n / 2; i++)
//	{
//		for (j = 0; j < n / 2; j++)
//		{
//			if ((arr[i][j] == arr[n - 1 - i][n - 1 - j]) && (arr[i][j] == arr[n - 1 - j][i]) && (arr[i][j] == arr[j][n - 1 - i]))
//			{
//				continue;
//			}
//			else
//			{
//				int tmp[4] = { 0 };
//				tmp[0] = arr[i][j];
//				tmp[1] = arr[n - 1 - i][n - 1 - j];
//				tmp[2] = arr[n - 1 - j][i];
//				tmp[3] = arr[j][n - 1 - i];
//				int num0 = check_0(tmp);
//				if (num0 == 0 || num0 == 4)
//				{
//					ret += 0;
//				}
//				else if (num0 == 1 || num0 == 3)
//				{
//					ret += 1;
//				}
//				else
//				{
//					ret += 2;
//				}
//			}
//		}
//	}
//	return ret;
//}
//int oddJudge(int arr[][101], int n)
//{
//	int i = 0, j = 0;
//	int ret = 0;
//	for (i = 0; i < n / 2; i++)
//	{
//		for (j = 0; j < n / 2; j++)
//		{
//			if ((arr[i][j] == arr[n - 1 - i][n - 1 - j]) && (arr[i][j] == arr[n - 1 - j][i]) && (arr[i][j] == arr[j][n - 1 - i]))
//			{
//				continue;
//			}
//			else
//			{
//				int tmp[4] = { 0 };
//				tmp[0] = arr[i][j];
//				tmp[1] = arr[n - 1 - i][n - 1 - j];
//				tmp[2] = arr[n - 1 - j][i];
//				tmp[3] = arr[j][n - 1 - i];
//				int num0 = check_0(tmp);
//				if (num0 == 0 || num0 == 4)
//				{
//					ret += 0;
//				}
//				else if (num0 == 1 || num0 == 3)
//				{
//					ret += 1;
//				}
//				else
//				{
//					ret += 2;
//				}
//			}
//		}
//	}
//	for (i = n / 2, j = 0; j < n / 2; j++)
//	{
//		if ((arr[i][j] == arr[n - 1 - i][n - 1 - j]) && (arr[i][j] == arr[n - 1 - j][i]) && (arr[i][j] == arr[j][n - 1 - i]))
//		{
//			continue;
//		}
//		else
//		{
//			int tmp[4] = { 0 };
//			tmp[0] = arr[i][j];
//			tmp[1] = arr[n - 1 - i][n - 1 - j];
//			tmp[2] = arr[n - 1 - j][i];
//			tmp[3] = arr[j][n - 1 - i];
//			int num0 = check_0(tmp);
//			if (num0 == 0 || num0 == 4)
//			{
//				ret += 0;
//			}
//			else if (num0 == 1 || num0 == 3)
//			{
//				ret += 1;
//			}
//			else
//			{
//				ret += 2;
//			}
//		}
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr_c[101][101] = { 0 };
//	int n = 0;
//	int arr[101][101] = { 0 };
//	scanf("%d", &n);
//	int i = 0, j = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%s", arr_c[i]);
//	}
//	//将字符数组转换为数字数组
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//
//			if (arr_c[i][j] >= '0' && arr_c[i][j] <= '9')
//			{
//				arr[i][j] = arr_c[i][j] - '0';
//			}
//		}
//	}
//	//判断
//	int result = 0;
//	if (n % 2 == 0)
//	{
//		result = evenJudge(arr, n);
//	}
//	else
//	{
//		result = oddJudge(arr, n);
//	}
//	printf("%d", result);
//
//	return 0;
//}



//题目 奇数
//int* singleNumber(int* nums, int numsSize, int* returnSize)
//{
//    *returnSize = 2;
//    int* ans = (int*)malloc(2 * sizeof(int));
//    int result = nums[0];
//    for (int i = 1; i < numsSize; i++)
//    {
//        result ^= nums[i];
//    }
//    int pos = 0;
//    for (int i = 0; i < 32; i++)
//    {
//        if (result & ((size_t)1 << i))
//        {
//            pos = i;
//            break;
//        }
//    }
//    ans[0] = 0;
//    ans[1] = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] & ((size_t)1 << pos))
//        {
//            ans[0] ^= nums[i];
//        }
//        else
//        {
//            ans[1] ^= nums[i];
//        }
//    }
//    return ans;
//}
//int main() {
//    int n;
//    scanf("%d", &n);
//    int* arr = new int[2 * n];
//    for (int i = 0; i < 2 * n; i++) 
//    {
//        scanf("%d", &arr[i]);
//    }
//    int returnSize = 0;
//	int* ans = singleNumber(arr, 2 * n, &returnSize);
//    printf("%d %d", ans[0], ans[1]);
//    delete[] arr;
//    return 0;
//}

//题目 奇数
//#include<iostream>
//using namespace std;
//#include<cstdio>
//#include <cstdlib>
//int main() {
//    int n;
//    scanf("%d", &n);
//
//    long long* nums = (long long*)malloc(2 * n * sizeof(long long));
//
//    if (nums == NULL) {
//        fprintf(stderr, "Memory allocation failed\n");
//        return 1;
//    }
//
//    long long xor_result = 0;
//
//    // 读入数字并对所有数字进行异或操作
//    for (int i = 0; i < 2 * n; i++) {
//        scanf("%lld", &nums[i]);
//        xor_result ^= nums[i];
//    }
//
//    // 找到异或结果中第一个为1的位
//    long long mask = 1;
//    while ((xor_result & mask) == 0) {
//        mask <<= 1;
//    }
//
//    // 分组并再次异或得到两个出现奇数次的数字
//    long long result1 = 0, result2 = 0;
//    for (int i = 0; i < 2 * n; i++) {
//        if ((mask & nums[i]) == 0) {
//            result1 ^= nums[i];
//        }
//        else {
//            result2 ^= nums[i];
//        }
//    }
//
//    // 输出较小的数字在前
//    if (result1 < result2) {
//        printf("%lld %lld\n", result1, result2);
//    }
//    else {
//        printf("%lld %lld\n", result2, result1);
//    }
//
//    free(nums); // 释放动态分配的内存
//
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include <cstdlib>
//using namespace std;
//#include <stdio.h>
//
//int count;
//
//// 深度优先搜索函数
//void dfs(int n, int prev, int len) {
//    if (len == n) {
//        count++;
//        return;
//    }
//
//    for (int i = 1; i <= 3; i++) {
//        if (i != prev) {
//            dfs(n, i, len + 1);
//        }
//    }
//}
//
//// 计算满足条件的数字串数量
//long long countValidStrings(int n) {
//    count = 0;
//    // 从数字1开始搜索
//    dfs(n, 0, 0);
//    return count;
//}
//
//int main() {
//    int n;
//
//    // 读取输入的数据
//    while (scanf("%d", &n) == 1) {
//        // 调用函数计算满足条件的数字串数量
//        long long result = countValidStrings(n);
//        printf("%lld\n", result);
//    }
//
//    return 0;
//}
