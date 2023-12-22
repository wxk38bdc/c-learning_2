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

//#include <stdio.h>
//#include <stdlib.h>
//#include<string.h>
//#include<ctype.h>
//int main()
//{
//	char tofind[11] = { 0 };
//	char str[1000001] = { 0 };
//	fgets(tofind, 11, stdin);
//	fgets(str, 1000001, stdin);
//	int lent=strlen(tofind);
//	int lens = strlen(str);
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < lent; i++)
//	{
//		tofind[i]=tolower(tofind[i]);
//	}
//	for (i = 0; i < lens; i++)
//	{
//		str[i] = tolower(str[i]);
//	}
//	tofind[lent - 1] = '\0';
//	lent--;
//	str[lens - 1] = '\0';
//	lens--;
//	//   ii ii  iiii  oiii    i 3 1 2 2 4
//	int space[100000] = { 0 };//存储每个单词前的空格数
//    int inWord = 0; // 标记是否在单词内部
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
//	char words[20000][70] = { 0 };
//	int wordsnum = 0;
//	
//	char* p = strtok(str, " ");
//	while (p != NULL)
//	{
//		strcpy(words[wordsnum++], p);
//		p = strtok(NULL, " ");
//	}
//	//统计单词出现的次数
//	int flag = 0;
//	int first_index= 0;
//	int count = 0;
//	for (i = 0; i < wordsnum; i++)
//	{
//		if (strcmp(words[i], tofind) == 0)
//		{
//			count++;
//		}
//		if (count == 1&&flag==0)
//		{
//			flag = 1;
//			first_index = i;
//		}
//	}
//	if(count==0)
//	{
//		printf("-1\n");
//		return 0;
//	}
//	printf("%d ", count);
//	//printf("第一个出现于%d\n", first_index);
//	int sum = 0;
//	for (i = 0; i <= first_index; i++)
//	{
//		sum=sum+space[i] + strlen(words[i]);
//		//if (i != first_index)
//		//{
//		//	sum=sum+strlen(words[i-1]);
//		//}
//	}
//	sum=sum-strlen(words[first_index]);
//	//printf("first index=%d\n", first_index);
//	printf("%d\n", sum);
//	//printf("********************\n");
//	//for (i = 0; i < wordsnum; i++)
//	//{
//	//	printf("%d\n", space[i]);
//	//	printf("%s\n", words[i]);
//	//	printf("%d\n", strlen(words[i]));
//	//}
//	return 0;
//}

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

//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int compareint(const void* a, const void* b)
//{
//	return *(int*)a - *(int*)b;
//}
//int main()
//{
//
//	int m = 0;
//	scanf("%d",  &m);
//	int k = 0;
//	scanf("%d", &k);
//	int* arr = (int*)malloc(sizeof(int) * m);
//	int i = 0;
//	for (i = 0; i < m; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	qsort(arr, m, sizeof(int), compareint);
//	printf("%d ", arr[k]);
//	free(arr);
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//int compareint(const void* a, const void* b)
//{
//	return *(int*)a - *(int*)b;
//}
//int main()
//{
//	int m = 0, n = 0;
//	scanf("%d %d", &m, &n);
//	int* arr = (int*)malloc(sizeof(int) * (m + n));
//	int i = 0;
//	for (i = 0; i < m+n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	qsort(arr, m + n, sizeof(int), compareint);
//	for (i = 0; i < m + n; i++)
//	{
//		if(i==0||arr[i]!=arr[i-1])
//			printf("%d ", arr[i]);
//	}
//	return 0;
//}

//#include<stdio.h>
////矩阵蛇形输出和回转输出
//int main()
//{
//	int arr[11][11] = { 0 };
//	int row = 0, col = 0, i = 0, j = 0;
//	scanf("%d%d", &row, &col);
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	//蛇形输出
//	for (i = 0; i < row; i++)
//	{
//		if (i % 2 == 0)
//		{
//			for (j = 0; j < col; j++)
//			{
//				printf("%d ", arr[i][j]);
//			}
//		}
//		else
//		{
//			for (j = col - 1; j >= 0; j--)
//			{
//				printf("%d ", arr[i][j]);
//			}
//		}
//	}
//	printf("\n");
//	//回形输出:先输出最外层，再输出内层，直到输出最中心的一个元素
//	int left = 0, right = col - 1, up = 0, down = row - 1;
//	while (left <= right && up <= down)
//	{
//		for (i = left; i <= right; i++)
//		{
//			printf("%d ", arr[up][i]);
//		}
//		for (i = up + 1; i <= down; i++)
//		{
//			printf("%d ", arr[i][right]);
//		}
//		if (up != down)
//		{
//			for (i = right - 1; i >= left; i--)
//			{
//				printf("%d ", arr[down][i]);
//			}
//		}
//		if (left != right)
//		{
//			for (i = down - 1; i > up; i--)
//			{
//				printf("%d ", arr[i][left]);
//			}
//		}
//		left++;
//		right--;
//		up++;
//		down--;
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int compareint(const void* a, const void* b)
//{
//	return *(int*)a - *(int*)b;
//}
//int main()
//{
//	int n;
//	int m = 0;
//	scanf("%d",&m);
//
//	int* arr = (int*)malloc(sizeof(int) * m);
//	int i = 0;
//	for (i = 0; i < m; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	qsort(arr, m, sizeof(int), compareint);
//	int num = 0;
//	for (i = 0; i < m; i++)
//	{
//		if (i == 0 || arr[i] != arr[i - 1])
//		{
//			num++;
//		}
//	}	
//	printf("%d\n", num);
//	for (i = 0; i < m; i++)
//	{
//		if (i == 0 || arr[i] != arr[i - 1])
//		{
//			printf("%d ", arr[i]);
//		}
//	}
//	free(arr);
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//typedef struct stu {
//	int id;
//	int cn;
//	int ma;
//	int en;
//	int sum;
//}stu;
//int compare(const void* e1, const void* e2)
//{
//	stu* s1 = (stu*)e1;
//	stu* s2 = (stu*)e2;
//	if (s1->sum != s2->sum)
//	{
//		return s2->sum - s1->sum;
//	}
//	else if (s1->cn != s2->cn)
//	{
//		return s2->cn - s1->cn;
//	}
//	else if (s1->id != s2->id)
//	{
//		return s1->id - s2->id;
//	}
//	else {
//		return 0;
//	}
//}
//int main()
//{
//	int n = 0;
//	int i = 0;
//	scanf("%d", &n);
//	stu* arr = (stu*)malloc(sizeof(stu) * n);
//	for(i=0;i<n;i++)
//	{
//		arr[i].id = i + 1;
//		scanf("%d %d %d",&arr[i].cn, &arr[i].ma, &arr[i].en);
//		arr[i].sum = arr[i].cn + arr[i].ma + arr[i].en;
//	}
//	qsort(arr, n, sizeof(stu), compare);
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d %d\n", arr[i].id, arr[i].sum);
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int compare(const void* e1, const void* e2)
//{
//	char*s1 = (char*)e1;
//	char*s2 = (char*)e2;
//	if(strlen(s1)!=strlen(s2))
//	{
//		return strlen(s1) - strlen(s2);
//	}
//	else 
//	{
//		return strcmp(s1, s2);
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	char arr[20][150] = { 0 };
//	char arr_copy[20][150] = { 0 };
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%s", arr[i]);
//		strcpy(arr_copy[i], arr[i]);
//	}
//	qsort(arr,n,150,compare);
//	
//	for(i=0; i < n; i++)
//	{
//		if (strcmp(arr_copy[i], arr[n - 1]) == 0)
//		{
//			printf("%d\n", i+1);
//		}
//	}
//	printf("%s\n", arr[n - 1]);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//#define MAX_DIGITS 200  // 定义最大位数
//
//// 函数：反转字符串
//void reverseString(char* str) {
//    int length = strlen(str);
//    for (int i = 0; i < length / 2; i++) {
//        char temp = str[i];
//        str[i] = str[length - 1 - i];
//        str[length - 1 - i] = temp;
//    }
//}
//
//// 函数：高精度加法
//void addLargeNumbers(char* num1, char* num2, char* result) {
//    int length1 = strlen(num1);
//    int length2 = strlen(num2);
//    int carry = 0;
//    int i = 0;
//
//    // 反转字符串以便从最低位开始相加
//    reverseString(num1);
//    reverseString(num2);
//    
//
//    // 执行加法操作
//    for (; i < length1 || i < length2 || carry; i++) {
//        int digit1 = i < length1 ? num1[i] - '0' : 0;
//        int digit2 = i < length2 ? num2[i] - '0' : 0;
//        int sum = digit1 + digit2 + carry;
//        result[i] = (sum % 10) + '0';  // 存储当前位的结果
//        carry = sum / 10;              // 计算进位
//    }
//    result[i] = '\0';  // 添加字符串结束符
//
//    // 再次反转得到最终结果
//    reverseString(result);
//}
//
//int main() {
//    char num1[MAX_DIGITS];
//    char num2[MAX_DIGITS];
//    char result[MAX_DIGITS + 1];  // 存储结果，可能需要额外的一位用于进位
//
//    printf("Enter first number: ");
//    scanf("%s", num1);
//    printf("Enter second number: ");
//    scanf("%s", num2);
//
//    addLargeNumbers(num1, num2, result);
//    printf("Sum: %s\n", result);
//
//    return 0;
//}


//高精度加减法
//#include <stdio.h>
//#include <string.h>
//
//#define MAX_DIGITS 200  // 定义最大位数
//
//// 函数：反转字符串
//void reverseString(char* str) {
//    int length = strlen(str);
//    for (int i = 0; i < length / 2; i++) {
//        char temp = str[i];
//        str[i] = str[length - 1 - i];
//        str[length - 1 - i] = temp;
//    }
//}
//
//// 函数：比较两个数的大小
//int compareNumbers(char* num1, char* num2) {
//    int length1 = strlen(num1);
//    int length2 = strlen(num2);
//
//    if (length1 != length2) {
//        return length1 > length2 ? 1 : -1;
//    }
//
//    for (int i = 0; i < length1; i++) {
//        if (num1[i] != num2[i]) {
//            return num1[i] > num2[i] ? 1 : -1;
//        }
//    }
//
//    return 0;  // 两数相等
//}
//
//// 函数：高精度加法
//void addLargeNumbers(char* num1, char* num2, char* result) {
//    int length1 = strlen(num1);
//    int length2 = strlen(num2);
//    int carry = 0;
//    int i = 0;
//
//    reverseString(num1);
//    reverseString(num2);
//
//    for (; i < length1 || i < length2 || carry; i++) {
//        int digit1 = i < length1 ? num1[i] - '0' : 0;
//        int digit2 = i < length2 ? num2[i] - '0' : 0;
//        int sum = digit1 + digit2 + carry;
//        result[i] = (sum % 10) + '0';
//        carry = sum / 10;
//    }
//    result[i] = '\0';
//
//    reverseString(result);
//}
//
//// 函数：高精度减法
//void subtractLargeNumbers(char* num1, char* num2, char* result) {
//    int length1 = strlen(num1);
//    int length2 = strlen(num2);
//    int borrow = 0;
//    int i = 0;
//    // 如果 num1 < num2，则交换两个数
//    if (compareNumbers(num1, num2) < 0) {
//        char* temp = num1;
//        num1 = num2;
//        num2 = temp;
//
//        int tempLength = length1;
//        length1 = length2;
//        length2 = tempLength;
//    }
//
//    reverseString(num1);
//    reverseString(num2);
//
//    for (; i < length1; i++) {
//        int digit1 = i < length1 ? num1[i] - '0' : 0;
//        int digit2 = i < length2 ? num2[i] - '0' : 0;
//        int diff = digit1 - digit2 - borrow;
//
//        if (diff < 0) {
//            diff += 10;
//            borrow = 1;
//        }
//        else {
//            borrow = 0;
//        }
//
//        result[i] = diff + '0';
//    }
//
//    while (i > 1 && result[i - 1] == '0') {
//        i--;
//    }
//    result[i] = '\0';
//
//    reverseString(result);
//}
//
//int main() {
//    char num1[MAX_DIGITS];
//    char num2[MAX_DIGITS];
//    char result[MAX_DIGITS + 1];
//    int operation;
//
//    printf("Enter first number: ");
//    scanf("%s", num1);
//    printf("Enter second number: ");
//    scanf("%s", num2);
//    printf("Choose operation (1 for addition, 2 for subtraction): ");
//    scanf("%d", &operation);
//
//    if (operation == 1) {
//        addLargeNumbers(num1, num2, result);
//        printf("Sum: %s\n", result);
//    }
//    else if (operation == 2) {
//        subtractLargeNumbers(num1, num2, result);
//        printf("Difference: %s\n", result);
//    }
//    else {
//        printf("Invalid operation.\n");
//    }
//
//    return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//int bubblesort(int* arr, int n)
//{
//	int i = 0;
//	int j = 0;
//	int flag = 0;
//	int sortnum = 0;
//	for (i = 0; i < n - 1; i++)
//	{
//		flag = 0;
//		for (j = 0; j < n - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 1;
//				sortnum++;
//			}
//		}
//		if (flag == 0)
//		{
//			break;
//		}
//	}
//	return sortnum;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int* arr = (int*)malloc(sizeof(int) * n);
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int sortnum = bubblesort(arr, n);
//	printf("%d\n", sortnum);
//	free(arr);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//    int n;
//    scanf("%d", &n);
//
//    int* arr = (int*)malloc(n * sizeof(int));
//    int* diffs = (int*)calloc(n, sizeof(int));  // 初始化为0
//
//    // 读取数组
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &arr[i]);
//    }
//
//    // 计算差的绝对值并标记
//    for (int i = 0; i < n - 1; i++) {
//        int diff = abs(arr[i] - arr[i + 1]);
//        if (diff < n) {
//            diffs[diff] = 1;  // 标记差值
//        }
//    }
//
//    // 检查是否所有差值都被标记
//    int jolly = 1;  // 假设是Jolly
//    for (int i = 1; i < n; i++) {
//        if (diffs[i] == 0) {
//            jolly = 0;  // 发现未标记的差值
//            break;
//        }
//    }
//
//    if (jolly) {
//        printf("Jolly\n");
//    }
//    else {
//        printf("Not jolly\n");
//    }
//
//    // 释放内存
//    free(arr);
//    free(diffs);
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//struct ListNode {
//    int val;
//    struct ListNode* next;
//};
//
//struct ListNode* insertionSortList(struct ListNode* head) {
//    if (head == NULL || head->next == NULL) {
//        return head;
//    }
//
//    struct ListNode* sorted = NULL; // 新的排序链表的头节点
//    struct ListNode* current = head; // 当前要插入的节点
//
//    while (current != NULL) {
//        struct ListNode* next = current->next; // 保存下一个节点
//
//        // 寻找插入位置
//        if (sorted == NULL || sorted->val >= current->val) {
//            // 插入到头部
//            current->next = sorted;
//            sorted = current;
//        }
//        else {
//            // 遍历已排序的链表找到插入点
//            struct ListNode* tmp = sorted;
//            while (tmp->next != NULL && tmp->next->val < current->val) {
//                tmp = tmp->next;
//            }
//            // 插入到tmp节点之后
//            current->next = tmp->next;
//            tmp->next = current;
//        }
//
//        current = next; // 移动到下一个要插入的节点
//    }
//
//    return sorted;
//}
//
//// 辅助函数：打印链表
//void printList(struct ListNode* head) {
//    struct ListNode* temp = head;
//    while (temp != NULL) {
//        printf("%d ", temp->val);
//        temp = temp->next;
//    }
//    printf("\n");
//}
//
//// 主函数：演示排序
//int main() {
//    // 创建链表并添加一些节点
//    // 示例：1 -> 4 -> 3 -> 2 -> NULL
//    struct ListNode* head = malloc(sizeof(struct ListNode));
//    head->val = 1;
//    head->next = malloc(sizeof(struct ListNode));
//    head->next->val = 4;
//    head->next->next = malloc(sizeof(struct ListNode));
//    head->next->next->val = 3;
//    head->next->next->next = malloc(sizeof(struct ListNode));
//    head->next->next->next->val = 2;
//    head->next->next->next->next = NULL;
//
//    printf("Original List: ");
//    printList(head);
//
//    struct ListNode* sorted = insertionSortList(head);
//
//    printf("Sorted List: ");
//    printList(sorted);
//
//    // 释放内存
//    // 在实际应用中，确保适当释放所有已分配的内存
//    // ...
//
//    return 0;
//}


//#include<stdio.h>
////去重，预期修改为2,4,6,9，即将重复元素全部移到数组末尾
//int quchong(int arr[], int n)
//{
//	int i = 0, j = 0;
//	int ret = 0;
//	
//	return ret;
//}
//int main()
//{
//	int arr[] = { 1,1,2,3,3,4,5,5,6,7,7,7,8,8,9,0,0 };
//	int ret=quchong(arr,17);//返回去重后数组的元素个数
//	printf("ret=%d\n", ret);
//	for (int i = 0; i < ret; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}