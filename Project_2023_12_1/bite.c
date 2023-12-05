#define _CRT_SECURE_NO_WARNINGS 1


//#pragma pack(1) // 将对齐数设置为1字节
//
//struct Example {
//    char a;    // 1字节
//    int b;     // 4字节
//    double c;  // 8字节
//};
//
//#pragma pack() // 恢复默认对齐数
//#include <stdio.h>
//int main()
//{
//	struct E1
//	{
//		char c1;
//		int i;
//		char c2;
//	};
//	struct E2
//	{
//		char c1;
//		char c2;
//		int i;
//	};
//	struct E3
//	{
//		double d;
//		char c;
//		int i;
//	};
//	struct E4
//	{
//		char c1;
//		struct E3 e3;
//		double d;
//	};
//	printf("%zd\n", sizeof(struct E1)); // 12
//	printf("%zd\n", sizeof(struct E2)); // 8
//	printf("%zd\n", sizeof(struct E3)); // 16
//	printf("%zd\n", sizeof(struct E4)); // 32
//	return 0;
//}

//#include<stdio.h>
//struct A
//{
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//};
//struct Flags {
//	unsigned int flag1 : 1; // 占用1位
//	unsigned int flag2 : 2; // 占用2位
//	unsigned int flag3 : 3; // 占用3位
//};
//
//int main()
//{
//	printf("struct Flags 占用的空间是：%zd 字节\n",sizeof(struct Flags));
//	return 0;
//}

//#include <stdio.h>
////联合类型的声明
//union Un
//{
//	char c;
//	int i;
//};
//int main()
//{
//	//联合变量的定义
//	union Un un = { 0 };
//	//计算union变量的大小
//	printf("union Un 占用%d字节内存\n", sizeof(un));
//	return 0;
//}

////代码1
//#include <stdio.h>
////联合类型的声明
//union Un
//{
//	char c;
//	int i;
//};
//int main()
//{
//	//联合变量的定义
//	union Un un = { 0 };
//	// 下⾯输出的结果是一样的吗？
//	printf("%p\n", &(un.i));
//	printf("%p\n", &(un.c));
//	printf("%p\n", &un);
//	return 0;
//}

////代码2
//#include<stdio.h>
////联合类型的声明
//union Un
//{
//	char c;
//	int i;
//};
//int main()
//{
//	//联合变量的定义
//	union Un un = { 0 };
//	un.i = 0x11223344;
//	un.c = 0x55;
//	printf("%x\n", un.i);
//	return 0;
//}

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

//#include <stdio.h>
//#include <stdlib.h>
//
//// 判断一个数是否为质数
//int isPrime(int num) {
//    if (num < 2) {
//        return 0;
//    }
//    for (int i = 2; i * i <= num; i++) {
//        if (num % i == 0) {
//            return 0;
//        }
//    }
//    return 1;
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);
//
//    int* crystals = (int*)malloc(n * sizeof(int));
//    int* used = (int*)calloc(n + 1, sizeof(int)); // 用于记录能量是否已经被使用
//    int* energy = (int*)malloc(n * sizeof(int)); // 用于存储每个水晶的能量
//
//    // 初始化能量数组
//    for (int i = 0; i < n; i++) {
//        energy[i] = n - i;
//    }
//
//    int idx = n - 1; // 当前处理的水晶索引
//
//    // 迭代方式生成满足条件的能量排列
//    while (idx >= 0) {
//        while (energy[idx] > 0 && (used[energy[idx]] || !isPrime(idx + 1 + energy[idx]))) {
//            energy[idx]--;
//        }
//
//        if (energy[idx] == 0) {
//            // 当前能量无法满足条件，回溯到上一个水晶
//            used[energy[idx + 1]] = 0;
//            energy[idx] = n - idx;
//            idx--;
//        }
//        else {
//            // 当前能量满足条件，继续处理下一个水晶
//            used[energy[idx]] = 1;
//            idx++;
//
//            if (idx == n) {
//                // 所有水晶处理完毕，输出结果
//                for (int i = 0; i < n; i++) {
//                    crystals[i] = energy[i];
//                }
//                break;
//            }
//        }
//    }
//
//    // 输出结果
//    if (idx == n) {
//        for (int i = 0; i < n; i++) {
//            printf("%d ", crystals[i]);
//        }
//    }
//    else {
//        printf("No solution exists for n = %d.", n);
//    }
//
//    free(crystals);
//    free(used);
//    free(energy);
//    return 0;
//}
//
//#include <stdio.h>
//int main()
//{
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    long long n;
//    scanf("%lld", &n);
//
//    long long* arr = (long long*)malloc(n * sizeof(long long));
//    long long* arr_index = (long long*)malloc(n * sizeof(long long));
//
//    long long i, j = 0;
//    long long count_0 = 0;
//
//    for (i = 0; i < n; i++)
//    {
//        scanf("%lld", &arr[i]);
//        if (arr[i] == 0)
//        {
//            arr_index[j] = i;
//            j++;
//            count_0++;
//        }
//    }
//
//    for (i = 0; i < n; i++)
//    {
//        long long min = 100000;
//        for (j = 0; j < count_0; j++)
//        {
//            if (min > llabs(i - arr_index[j]))
//            {
//                min = llabs(i - arr_index[j]);
//            }
//        }
//        printf("%lld ", min);
//    }
//
//    free(arr);
//    free(arr_index);
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_N 800
//
//// 定义一个函数计算最长的满足“好的一对”的子序列长度
//int longest_good_pair_subsequence(int n, int a[], int b[]) {
//    int** dp = (int**)malloc((n + 1) * sizeof(int*));
//    for (int i = 0; i <= n; ++i) {
//        dp[i] = (int*)malloc((n + 1) * sizeof(int));
//    }
//
//    int result = 0;
//
//    for (int i = 0; i <= n; ++i) {
//        for (int j = 0; j <= n; ++j) {
//            if (i == 0 || j == 0) {
//                dp[i][j] = 0;
//            }
//            else if (a[i - 1] % b[j - 1] == a[i - 2] % b[j - 2]) {
//                dp[i][j] = dp[i - 1][j - 1] + 1;
//                result = result > dp[i][j] ? result : dp[i][j];
//            }
//            else {
//                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
//            }
//        }
//    }
//
//    // 释放动态分配的内存
//    for (int i = 0; i <= n; ++i) {
//        free(dp[i]);
//    }
//    free(dp);
//
//    return result;
//}
//
//int main() {
//    // 读取输入
//    int n;
//    scanf("%d", &n);
//
//    int* a = (int*)malloc(n * sizeof(int));
//    for (int i = 0; i < n; ++i) {
//        scanf("%d", &a[i]);
//    }
//
//    int* b = (int*)malloc(n * sizeof(int));
//    for (int i = 0; i < n; ++i) {
//        scanf("%d", &b[i]);
//    }
//
//    // 输出结果
//    printf("%d\n", longest_good_pair_subsequence(n, a, b));
//
//    // 释放动态分配的内存
//    free(a);
//    free(b);
//
//    return 0;
//}

//#include <stdio.h>
//int getMost(int arr[], int n)
//{
//	int i = 0;
//	int j = 0;
//	int count = 0;
//	int max = 0;
//	for (i = 0; i < n; i++)
//	{
//		count = 0;
//		for (j = 0; j < n; j++)
//		{
//			if (arr[i] == arr[j])
//			{
//				count++;
//			}
//		}
//		if (count > max)
//		{
//			max = count;
//		}
//	}
//	return max;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int arr1[800] = { 0 };
//	int arr2[800] = { 0 };
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr1[i]);
//	};
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr2[i]);
//	};
//	int arr_mod[800] = { 0 };
//	for (i = 0; i < n; i++)
//	{
//		arr_mod[i] = arr1[i] % arr2[i];
//	};
//	int result = getMost(arr_mod, n);//统计出现次数最多的数
//	printf("%d", result);
//	return 0;
//}

//#include <stdio.h>
//
//int count = 0; // 用于记录满足条件的排列个数
//
//// 检查当前排列是否满足条件
//int isValid(int* arr, int length) {
//    for (int i = 0; i < length - 1; ++i) {
//        if (arr[i] == arr[i + 1]) {
//            return 0; // 相邻的数相同，不满足条件
//        }
//    }
//    return 1; // 满足条件
//}
//
//// 递归生成排列
//void generatePermutations(int* arr, int index, int n) {
//    if (index == n) {
//        // 检查生成的排列是否满足条件
//        if (isValid(arr, n) && arr[0] == arr[n - 1]) {
//            count++;
//        }
//        return;
//    }
//
//    for (int i = 1; i <= 3; ++i) {
//        arr[index] = i;
//        generatePermutations(arr, index + 1, n);
//    }
//}
//
//int main() {
//    int n;
//    while (scanf("%d", &n) != EOF) {
//        count = 0;
//        int arr[50]; // 假设 n < 50
//        generatePermutations(arr, 0, n);
//        printf("%d\n", count);
//    }
//
//    return 0;
//}

//#include <stdio.h>
//
//int count = 0; // 用于记录满足条件的排列个数
//
//// 检查当前排列是否满足条件
//int isValid(int* arr, int length) {
//    for (int i = 0; i < length - 1; ++i) {
//        if (arr[i] == arr[i + 1]) {
//            return 0; // 相邻的数相同，不满足条件
//        }
//    }
//    return 1; // 满足条件
//}
//
//// 递归生成排列
//void generatePermutations(int* arr, int index, int n) {
//    if (index == n) {
//        // 检查生成的排列是否满足条件
//        if (isValid(arr, n) && arr[0] == arr[n - 1]) {
//            count++;
//        }
//        return;
//    }
//
//    for (int i = 1; i <= 3; ++i) {
//        arr[index] = i;
//        if (isValid(arr, index + 1)) {
//            generatePermutations(arr, index + 1, n);
//        }
//    }
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//
//int main() {
//    long long n;
//    while (scanf("%lld", &n) != EOF) {
//        if (n == 1) {
//            printf("3\n");
//        }
//        else if (n > 1 && n % 2 == 0) {
//            printf("%lld\n", (long long)(pow(2, (double)(n-1)) - 2));
//        }
//        else if (n > 1 && n % 2 == 1) {
//            printf("%lld\n", (long long)pow(2, (double)(n - 1))+2);
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
////排序
//void bubbleSort(int arr[], int n)
//{
//	int i = 0;
//	int j = 0;
//	int flag = 0;
//	for (i = 0; i < n - 1; i++)
//	{
//		flag = 0;
//		for (j = 0; j < n - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				flag = 1;
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//		if (flag == 0)
//		{
//			break;
//		}
//	}
//}
////古神音阶
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	char str1[2001] = { 0 };
//	char str2[1000] = { 0 };
//	scanf("%s", str1);
//	scanf("%s", str2);
//	//把str1复制到自己后面
//	memmove(str1 + n, str1, n);
//	//判断str2中有无问号?
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	//int flag = 0;//标记是否有问号
//	int count = 0;//标记有几个问号
//	int ifOK = 0;//标记是否有解
//	for (i = 0; i < n; i++)
//	{
//		if (str2[i] == '?')
//		{
//			//flag = 1;
//			count++;
//		}
//	}
//	int ret[1000] = { 0 };
//	int ret_index = 0;
//	//if (flag == 0) 
//	//{
//	//	for (i = 0; i < n; i++)
//	//	{
//	//		if(strncmp(str1+n-i, str2, n) == 0)
//	//		{
//	//			ret[ret_index] = (i + 1) % 12;
//	//			ret_index++;
//	//			ifOK = 1;
//	//		}
//	//	}
//	//	if (ifOK == 0)
//	//	{
//	//		printf("Aminos");
//	//	}
//	//}
//	//else 
//	//{
//		for (i = 0; i < n; i++)//标记str1移位数
//		{
//			k = 0;
//			for (j = 0; j < n; j++)
//			{
//				if(str1[n-i+j]==str2[j] || str2[j] == '?')
//				{
//					k++;
//				}
//			}
//			if (k == n)
//			{
//				ret[ret_index]=(i+1)%n;
//				ret_index++;
//				ifOK = 1;
//			}
//		}
//		if (ifOK == 0)
//		{
//			printf("Aminos");
//		}
//	//}
//	bubbleSort(ret, ret_index);
//	if (ret_index)
//	{
//		for (i = 0; i < ret_index; i++)
//		{
//			printf("%d ", ret[i]);
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int n;
//	int arr[200000] = { 0 };
//	int arr_index[20000] = { 0 };//统计arr数组中的数是否是0，是则存入index数组
//	scanf("%d", &n);
//	int i = 0, j = 0;
//	int count_0 = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//		if (arr[i] == 0)
//		{
//			arr_index[j] = i;
//			j++;
//			count_0++;
//		}
//	}
//
//	for (i = 0; i < n; i++)
//	{
//		int min = 100000;
//		for (j = 0; j < count_0; j++)
//		{
//			if (min > abs(i - arr_index[j]))
//			{
//				min = abs(i - arr_index[j]);
//			}
//		}
//		printf("%d ", min);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//    int n;
//    scanf("%d", &n);
//
//    long long* arr = (long long*)malloc(n * sizeof(long long));
//    int* arr_index = (int*)malloc(n * sizeof(int)); // 使用int存储零值元素的索引
//    long long* result = (long long*)malloc(n * sizeof(long long));
//
//    int count_0 = 0;
//
//    for (int i = 0; i < n; i++) {
//        scanf("%lld", &arr[i]);
//        if (arr[i] == 0) {
//            arr_index[count_0++] = i;
//        }
//    }
//
//    for (int i = 0; i < n; i++) {
//        long long min = LLONG_MAX;
//        for (int j = 0; j < count_0; j++) {
//            if (min > llabs(i - arr_index[j])) {
//                min = llabs(i - arr_index[j]);
//            }
//        }
//        result[i] = min;
//    }
//
//    for (int i = 0; i < n; i++) {
//        printf("%lld ", result[i]);
//    }
//
//    // 释放动态分配的内存
//    free(arr);
//    free(arr_index);
//    free(result);
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	while (num--)
//	{
//		long long n, k;
//		scanf("%lld %lld", &n, &k);
//		int p;
//		scanf("%d", &p);
//		if (p == 0)//能否将n表示为k个非负偶数之和
//		{
//			if (n % 2 == 0)
//			{
//				printf("YES\n");
//			}
//			else
//			{
//				printf("NO\n");
//			}
//		}
//		else//能否将n表示为k个非负奇数之和
//		{
//			if ((k % 2 == 0 && n % 2 != 0) || (k % 2 == 1 && n % 2 == 0))
//			{
//				printf("NO\n");
//			}
//			else if(k > n)
//			{
//				printf("NO\n");
//			}
//			else
//			{
//				printf("YES\n");
//			}
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//
//int main() {
//    int n;
//    scanf("%d", &n);
//
//    long long* arr = (long long*)malloc(n * sizeof(long long));
//    int* result = (int*)malloc(n * sizeof(int));
//
//    int lastZeroIndex = INT_MIN;
//    for (int i = 0; i < n; i++) {
//        scanf("%lld", &arr[i]);
//        if (arr[i] == 0) {
//            lastZeroIndex = i;
//        }
//        result[i] = (lastZeroIndex == INT_MIN) ? INT_MIN : i - lastZeroIndex;
//    }
//
//    lastZeroIndex = INT_MAX;
//    for (int i = n - 1; i >= 0; i--) {
//        if (arr[i] == 0) {
//            lastZeroIndex = i;
//        }
//        // 取左右两侧最小距离
//        result[i] = (lastZeroIndex == INT_MAX) ? result[i] :
//            ((lastZeroIndex - i < result[i]) ? lastZeroIndex - i : result[i]);
//    }
//    //修正第一个0
//    int firstzero = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (arr[i] == 0)
//        {
//            firstzero = i;
//            break;
//        }
//    }
//    for (int i = 0; i < firstzero; i++)
//	{
//		result[i] = firstzero - i;
//	}
//
//    // 输出结果
//    for (int i = 0; i < n; i++) {
//        printf("%d ", result[i]);
//    }
//
//    // 释放动态分配的内存
//    free(arr);
//    free(result);
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//    int t;
//    scanf("%d", &t);
//    for (int i = 0; i < t; i++) {
//        int n;
//        scanf("%d", &n);
//        int max_sum = 0;
//        for (int k = 1; k <= n; k++) {
//            if (!(k & (1 << (n - 1)))) {
//                max_sum += k;
//            }
//        }
//        printf("%d\n", max_sum % 998244353);
//    }
//    return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	while (i++ < 4);
//	printf("%d", i);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main()
//{
//	char s[301] = { 0 };
//	int m;
//	char l[11] = { 0 };
//	char r[11] = { 0 };
//	//scanf("%s", s);
//	scanf("%d", &m);
//	scanf("%s", l);
//	scanf("%s", r);
//	char ans[100][100]= { 0 };
//	int i = 0, j = 0;
//	for (i = 0; i < m; i++)
//	{
//		for(j=0;j<m;j++)
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//void generate_strings(char* current, char* str2, int length, int position) {
//    if (position == length) {
//        printf("%s\n", current);
//        return;
//    }
//
//    int num2 = str2[position] - '0';
//    for (int j = current[position] - '0'; j <= num2; j++) {
//        current[position] = j + '0';
//        generate_strings(current, str2, length, position + 1);
//    }
//}
//
//int main() {
//    int length;
//    printf("请输入字符串的长度：");
//    scanf("%d", &length);
//
//    char str1[11];
//    char str2[11];
//
//    printf("请输入字符串1：");
//    scanf("%s", str1);
//    printf("请输入字符串2：");
//    scanf("%s", str2);
//
//    if (strlen(str1) != length || strlen(str2) != length) {
//        printf("输入的字符串长度与指定的长度不符合要求\n");
//        return 1;
//    }
//
//    printf("输出：\n");
//    generate_strings(str1, str2, length, 0);
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <string.h>
//char ans[100][100] = { 0 };
//int ans_index = 0;
//bool validate_input(char* str1, char* str2, int length) {
//    for (int i = 0; i < length; i++) {
//        if (str1[i] > str2[i]) {
//            return false;
//        }
//    }
//    return true;
//}
//
//void generate_strings(char* current, char* str2, int length, int position) {
//    if (position == length) {
//        //保存结果
//        strcpy(ans[ans_index], current);
//        ans_index++;
//        //printf("%s\n", current);
//        return;
//    }
//
//    int num2 = str2[position] - '0';
//    for (int j = current[position] - '0'; j <= num2; j++) {
//        current[position] = j + '0';
//        generate_strings(current, str2, length, position + 1);
//    }
//}
//
//int main() {
//    //printf("请输入字符串：");
//    char s[301] = { 0 };
//    scanf("%s", s);
//    int length;
//    //printf("请输入字符串的长度：");
//    scanf("%d", &length);
//
//    char str1[11];
//    char str2[11];
//
//    //printf("请输入字符串1：");
//    scanf("%s", str1);
//    //printf("请输入字符串2：");
//    scanf("%s", str2);
//
//    if (strlen(str1) != length || strlen(str2) != length || !validate_input(str1, str2, length)) {
//        printf("NO\n");
//        return 1;
//    }
//
//    //printf("输出：\n");
//    generate_strings(str1, str2, length, 0);
//    //输出结果//临时
// //   for (int i = 0; i < ans_index; i++)
// //   {
//	//	printf("%s\n", ans[i]);
//	//}
//    
//    int i = 0, j = 0, k = 0;
//    int flag = 0;
//    //判断ans[i]是否是s的子串，字符在s中的位置可以不连续，但必须从左到右出现
//    for (i = 0; i < ans_index; i++)
//    {
//        k = 0;
//        //如果不是子串，输出YES,提前结束
//        for (j = 0; j < strlen(s); j++)
//        {
//            if (ans[i][k] == s[j])
//            {
//				k++;
//			}
//            if (k == strlen(ans[i]))
//            {
//                flag++;
//                break;
//			}
//        }
//    }
//    //printf("%d\n", flag);
//    if (flag >= ans_index)
//    {
//        printf("NO\n");
//    }
//    else
//    {
//		printf("YES\n");
//	}
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//char ans[1000][11] = { 0 }; // 用于保存结果
//int ans_index = 0;
//
//void generate_strings(char* current, char* str1, char* str2, int length, int position) {
//    if (position == length) {
//        // 保存结果
//        strcpy(ans[ans_index], current);
//        ans_index++;
//        return;
//    }
//
//    int num1 = str1[position] - '0';
//    int num2 = str2[position] - '0';
//
//    for (int j = num1; j <= num2; j++) {
//        current[position] = j + '0';
//        generate_strings(current, str1, str2, strlen(str1), position + 1);
//    }
//}
//
//int main() {
//    char str1[11] = "001";
//    char str2[11] = "553";
//    int length = strlen(str1);
//
//    char current[11];
//    strcpy(current, str1);
//
//    generate_strings(current, str1, str2, strlen(str1), 0);
//
//    // 输出结果
//    for (int i = 0; i < ans_index; i++) {
//        printf("%s\n", ans[i]);
//    }
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//// 判断一个数是否为质数
//int isPrime(int num) {
//    if (num < 2) {
//        return 0;
//    }
//    for (int i = 2; i * i <= num; i++) {
//        if (num % i == 0) {
//            return 0;
//        }
//    }
//    return 1;
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);
//
//    int* crystals = (int*)malloc(n * sizeof(int));
//    int* used = (int*)calloc(n + 1, sizeof(int)); // 用于记录能量是否已经被使用
//    int* energy = (int*)malloc(n * sizeof(int)); // 用于存储每个水晶的能量
//
//    // 初始化能量数组
//    for (int i = 0; i < n; i++) {
//        energy[i] = n - i;
//    }
//
//    int idx = n - 1; // 当前处理的水晶索引
//
//    // 迭代方式生成满足条件的能量排列
//    while (idx >= 0) {
//        while (energy[idx] > 0 && (used[energy[idx]] || !isPrime(idx + 1 + energy[idx]))) {
//            energy[idx]--;
//        }
//
//        if (energy[idx] == 0) {
//            // 当前能量无法满足条件，回溯到上一个水晶
//            used[energy[idx + 1]] = 0;
//            energy[idx] = n - idx;
//            idx--;
//        }
//        else {
//            // 当前能量满足条件，继续处理下一个水晶
//            used[energy[idx]] = 1;
//            idx++;
//
//            if (idx == n) {
//                // 所有水晶处理完毕，输出结果
//                for (int i = 0; i < n; i++) {
//                    crystals[i] = energy[i];
//                }
//                break;
//            }
//        }
//    }
//
//    // 输出结果
//    if (idx == n) {
//        for (int i = 0; i < n; i++) {
//            printf("%d ", crystals[i]);
//        }
//    }
//    else {
//        printf("No solution exists for n = %d.", n);
//    }
//
//    free(crystals);
//    free(used);
//    free(energy);
//    return 0;
//}



