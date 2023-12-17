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

//#include<iostream>
//using namespace std;
//#include <cstdio>
//#include <cstdlib>
//#include <climits>
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
//    {
//        result[i] = firstzero - i;
//    }
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
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    if (isPrime(n + 1))
//    {
//        for(int i=n;i>=1;i--)
//		{
//			printf("%d ", i);
//		}
//    }
//    return 0;
//}
/*
int main() {
    int n;
    scanf("%d", &n);

    int* crystals = (int*)malloc(n * sizeof(int));
    int* used = (int*)calloc(n + 1, sizeof(int)); // 用于记录能量是否已经被使用
    int* energy = (int*)malloc(n * sizeof(int)); // 用于存储每个水晶的能量

    // 初始化能量数组
    for (int i = 0; i < n; i++) {
        energy[i] = n - i;
    }

    int idx = n - 1; // 当前处理的水晶索引

    // 迭代方式生成满足条件的能量排列
    while (idx >= 0) {
        while (energy[idx] > 0 && (used[energy[idx]] || !isPrime(idx + 1 + energy[idx]))) {
            energy[idx]--;
        }

        if (energy[idx] == 0) {
            // 当前能量无法满足条件，回溯到上一个水晶
            used[energy[idx + 1]] = 0;
            energy[idx] = n - idx;
            idx--;
        }
        else {
            // 当前能量满足条件，继续处理下一个水晶
            used[energy[idx]] = 1;
            idx++;

            if (idx == n) {
                // 所有水晶处理完毕，输出结果
                for (int i = 0; i < n; i++) {
                    crystals[i] = energy[i];
                }
                break;
            }
        }
    }

    // 输出结果
    if (idx == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", crystals[i]);
        }
    }
    else {
        printf("No solution exists for n = %d.", n);
    }

    free(crystals);
    free(used);
    free(energy);
    return 0;
}*/

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

//#include <iostream>
//#include <unordered_map>
//using namespace std;
//
//int main() {
//    ios_base::sync_with_stdio(false);
//
//    int n;
//    scanf("%d", &n);
//
//    unordered_map<long long, int> frequency;
//
//    long long xor_result = 0;
//
//    for (int i = 0; i < 2 * n; i++) {
//        long long num;
//        scanf("%lld", &num);
//        xor_result ^= num;
//        frequency[num]++;
//    }
//
//    long long mask = 1;
//    while ((xor_result & mask) == 0) {
//        mask <<= 1;
//    }
//
//    long long result = 0;
//
//    for (const auto& entry : frequency) {
//        long long num = entry.first;
//        int count = entry.second;
//        if ((num & mask) != 0 && count % 2 != 0) {
//            result ^= num;
//        }
//    }
//    if(result<(result ^ xor_result))
//        printf("%lld %lld\n", result, result ^ xor_result);
//    else
//	    printf("%lld %lld\n", result ^ xor_result,result);
//
//    return 0;
//}

//#include<iostream>
//using namespace std;
//#include<cstdio>
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    int b[50001] = { 0 };
//    int i = 0, j = 0, k = 0;
//    for (i = 1; i <= n; i++)//下标从1开始，方便计算
//    {
//        scanf("%d", &b[i]);
//    }
//    for (i = 1; i <= 2 * n; i++)
//    {
//        int tmp = 0;
//        for (k = 1; k <= n; k++)
//        {
//            for (j = 1; j <= n; j++)
//            {
//                tmp += (k + j == i) * (b[k] != b[j]);
//            }
//        }
//        printf("%d ", tmp);
//    }
//    return 0;
//}

//#include<iostream>
//using namespace std;
//#include<cstdio>
//
//int main() {
//    int n;
//    scanf("%d", &n);
//
//    int b[50001] = { 0 };
//    int c[20002] = { 0 };
//
//    for (int i = 1; i <= n; i++) {
//        scanf("%d", &b[i]);
//    }
//
//    for (int k = 1; k <= n; k++) {
//        for (int j = 1; j <= n; j++) {
//            int sum = k + j;
//            c[sum] += (b[k] != b[j]);
//        }
//    }
//
//    for (int i = 1; i <= 2 * n; i++) {
//        printf("%d ", c[i]);
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//bool canRepresent(vector<int>& numbers, int target) {
//    vector<bool> canRepresent(target + 1, false);
//    canRepresent[0] = true;  // 0 可以被表示
//
//    for (int i = 0; i < numbers.size(); ++i) {
//        for (int j = numbers[i]; j <= target; ++j) {
//            if (canRepresent[j - numbers[i]]) {
//                canRepresent[j] = true;
//            }
//        }
//    }
//
//    return canRepresent[target];
//}
//
//int main() {
//    int n;
//    cout << "请输入正整数的个数 n: ";
//    cin >> n;
//
//    vector<int> numbers(n);
//
//    cout << "请输入 " << n << " 个正整数：" << endl;
//    for (int i = 0; i < n; ++i) {
//        cin >> numbers[i];
//    }
//
//    int target;
//    cout << "请输入要判断的正整数：" << endl;
//    cin >> target;
//
//    if (canRepresent(numbers, target)) {
//        cout << target << " 可以被给定的 " << n << " 个正整数表示。" << endl;
//    }
//    else {
//        cout << target << " 不能被给定的 " << n << " 个正整数表示。" << endl;
//    }
//
//    return 0;
//}


//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int findFirstUnrepresentable(vector<int>& numbers) {
//    int maxNumber = *max_element(numbers.begin(), numbers.end());
//    int target = maxNumber * 100;  // 从输入的最大数的10倍开始向下遍历
//
//    vector<bool> canRepresent(target + 1, false);
//    canRepresent[0] = true;  // 0 可以被表示
//
//    for (int i = 0; i < numbers.size(); ++i) {
//        for (int j = numbers[i]; j <= target; ++j) {
//            if (canRepresent[j - numbers[i]]) {
//                canRepresent[j] = true;
//            }
//        }
//    }
//
//    for (int i = maxNumber + 1; i <= target; ++i) {
//        if (!canRepresent[i]) {
//            return i;
//        }
//    }
//
//    return 1;  // 所有数都能被表示，理论上不会执行到这一步
//}
//
//int main() {
//    int n;
//    cout << "请输入正整数的个数 n: ";
//    cin >> n;
//
//    vector<int> numbers(n);
//
//    cout << "请输入 " << n << " 个正整数：" << endl;
//    for (int i = 0; i < n; ++i) {
//        cin >> numbers[i];
//    }
//
//    int result = findFirstUnrepresentable(numbers);
//
//    cout << "第一个不能被给定的 " << n << " 个正整数表示的正整数是：" << result << endl;
//
//    return 0;
//}


//#include <iostream>
//#include<cstdio>
//using namespace std;
//#include<cstring>
//int main()
//{
//    char s[301] = { 0 };
//    scanf("%s", s);
//    int m;
//    scanf("%d", &m);
//    char L[11] = { 0 };
//    char R[11] = { 0 };
//    scanf("%s", L);
//    scanf("%s", R);
//    return 0;
//}

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//bool isValidPassword(const string& s, int m, const string& l, const string& r) {
//    for (string::size_type i = 0; i <= s.length() - static_cast<string::size_type>(m); ++i) {
//        string candidate = s.substr(i, m);
//        bool valid = true;
//
//        for (int j = 0; j < m; ++j) {
//            int digit = candidate[j] - '0';
//            int lower_bound = l[j] - '0';
//            int upper_bound = r[j] - '0';
//
//            if (digit < lower_bound || digit > upper_bound) {
//                valid = false;
//                break;
//            }
//        }
//
//        if (valid) {
//            return true; // Found a valid password
//        }
//    }
//
//    return false; // No valid password found
//}
//
//int main() {
//    string s, l, r;
//    int m;
//
//    // Input
//    cin >> s >> m >> l >> r;
//
//    // Output
//    if (isValidPassword(s, m, l, r)) {
//        cout << "YES";
//    }
//    else {
//        cout << "NO";
//    }
//
//    return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//int main() {
//
//    string str1, str2;
//    cin >> str1;
//    int i = 0, j = 0;
//    //枚举，n个元素，所有子集个数=2的n次方，时间复杂度2的n次方，指数级
//    int itotal = 1 << str1.length();
//    for (i = 0; i < itotal; i++) {
//        for (j = 0; j < str1.length(); j++) { //遍历二进制的每一位，看那一位是不是1.
//            if (((1 << j) & i) != 0)//  当前j这一位取1，与i做与运算，如果运算结果为1说明这一位要取。
//            {
//                cout << str1[j];
//            }
//        }
//        cout << endl;
//    }
//    return 0;
//}

/*
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void generateSubstrings(const string& s, int m, int index, string current, vector<string>& substrings) {
    if (current.length() == m) {
        substrings.push_back(current);
        return;
    }

    if (index == s.length()) {
        return;
    }

    // Include the current character and move to the next index
    generateSubstrings(s, m, index + 1, current + s[index], substrings);

    // Exclude the current character and move to the next index
    generateSubstrings(s, m, index + 1, current, substrings);
}

void printSubstrings(const string& s, int m) {
    vector<string> substrings;
    generateSubstrings(s, m, 0, "", substrings);

    // Output
    cout << "Substrings of length " << m << ":" << endl;
    for (const string& substring : substrings) {
        cout << substring << endl;
    }
}

int main() {
    string s;
    int m;

    // Input
    cout << "Enter a string: ";
    cin >> s;

    cout << "Enter the length of substrings to extract: ";
    cin >> m;

    // Output
    printSubstrings(s, m);

    return 0;
}
*/


/*
* 第一版
 #include <cstdio>
#include <cstdlib>
#include <cstring>
#include<iostream>
using namespace std;
char ans[1500][11] = { 0 }; // 用于保存结果
int ans_index = 0; // 用于记录结果的个数
int validate_input(char* str1, char* str2, int length) {
    for (int i = 0; i < length; i++) {
        if (str1[i] > str2[i]) {
            return 0;
        }
    }
    return 1;
}
void generate_strings(char* current, char* str1, char* str2, int length, int position) {
    if (position == length) {
        // 保存结果
        strcpy(ans[ans_index], current);
        ans_index++;
        return;
    }

    int num1 = str1[position] - '0';
    int num2 = str2[position] - '0';

    for (int j = num1; j <= num2; j++) {
        current[position] = j + '0';
        generate_strings(current, str1, str2, strlen(str1), position + 1);
    }
}
int main() {
    char s[301] = { 0 };
    scanf("%s", s);
    int length;
    scanf("%d", &length);
    char str1[11];
    char str2[11];
    scanf("%s", str1);
    scanf("%s", str2);
    if (validate_input(str1, str2, length)==0) 
    {
		printf("NO");
		return 0;
	}
    char current[11];
    strcpy(current, str1);
    generate_strings(current, str1, str2, length, 0);
    int i = 0, j = 0, k = 0;
    int flag = 0;
    //判断ans[i]是否是s的子串，字符在s中的位置可以不连续，但必须从左到右出现
    for (i = 0; i < ans_index; i++)
    {
        k = 0;
        for (j = 0; j < (int)strlen(s); j++)
        {
            if (ans[i][k] == s[j])
            {
                k++;
            }
            if (k == length)
            {
                flag++;
                break;
            }
        }
    }
    if (flag >= ans_index)
    {
        printf("NO");
    }
    else
    {
        printf("YES");
    }
    return 0;
}
*/


////啊啊啊啊啊啊终于通过了！！！！
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include<iostream>
//using namespace std;
//char s[301] = { 0 };
//int ans_index = 0; // 用于记录结果的个数
//int flag = 0;
//int validate_input(char* str1, char* str2, int length) {
//    for (int i = 0; i < length; i++) {
//        if (str1[i] > str2[i]) {
//            return 0;
//        }
//    }
//    return 1;
//}
//void judge(char* s, char* ans, int length)
//{
//    int j = 0, k = 0;
//    for (j = 0; j < (int)strlen(s); j++)
//    {
//        if (ans[k] == s[j])
//        {
//            k++;
//        }
//        if (k == length)
//        {
//            flag++;
//            k = 0;
//            break;
//        }
//    }
//}
//void generate_strings(char* current, char* str1, char* str2, int length, int position) {
//    if (position == length) {
//        char ans[12] = { 0 };
//        strcpy(ans, current);
//        judge(s, ans, length);
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
//int main() {
//    scanf("%s", s);
//    int length;
//    scanf("%d", &length);
//    char str1[12];
//    char str2[12];
//    scanf("%s", str1);
//    scanf("%s", str2);
//    if (validate_input(str1, str2, length) == 0)
//    {
//        printf("NO");
//        return 0;
//    }
//    char current[12];
//    strcpy(current, str1);
//    generate_strings(current, str1, str2, length, 0);
//    if (flag >= ans_index)
//    {
//        printf("NO");
//    }
//    else
//    {
//        printf("YES");
//    }
//    return 0;
//}


//#include <iostream>
//#include <cstdio>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main() {
//    int n;
//    scanf("%d", &n);
//
//    vector<int> b(n + 1);
//    vector<int> c(2 * n + 1, 0);
//
//    for (int i = 1; i <= n; i++) {
//        scanf("%d", &b[i]);
//    }
//
//    // Sort array b
//    sort(b.begin() + 1, b.end());
//
//    // Count occurrences of each element in b
//    vector<int> count(n + 1, 0);
//    for (int i = 1; i <= n; i++) {
//        count[b[i]]++;
//    }
//
//    // Calculate the prefix sum of count array
//    for (int i = 1; i <= n; i++) {
//        count[i] += count[i - 1];
//    }
//
//    // Calculate the contribution of each element to the answer
//    for (int i = 1; i <= n; i++) {
//        int numPairs = count[n] - count[b[i]];
//        c[2 * b[i]] += numPairs;
//    }
//
//    for (int i = 1; i <= 2 * n; i++) {
//        printf("%d ", c[i]);
//    }
//
//    return 0;
//}


//#include<iostream>
//using namespace std;
//#include<cstdio>
//
//int main() {
//    int n;
//    scanf("%d", &n);
//
//    int b[50001] = { 0 };
//    int c[100002] = { 0 };
//
//    for (int i = 1; i <= n; i++) 
//    {
//        scanf("%d", &b[i]);
//    }
//
//    for (int k = 1; k <= n; k++) {
//        for (int j = 1; j <= n; j++) {
//            c[k + j] += (b[k] != b[j]);
//        }
//    }
//    for (int i = 1; i <= 2 * n; i++) {
//        printf("%d ", c[i]);
//    }
//
//    return 0;
//}



//#include <iostream>
//#include <cstdio>
//#include <vector>
//using namespace std;
//
//int main() {
//    int n;
//    scanf("%d", &n);
//
//    vector<int> b(n + 1);
//    vector<int> count(100002, 0);
//    vector<int> c(100002, 0);
//
//    for (int i = 1; i <= n; i++) {
//        scanf("%d", &b[i]);
//        count[b[i]]++;
//    }
//
//     Calculate the contribution of each element to the answer
//    for (int i = 1; i <= n; i++) {
//        c[2 * b[i]] += i - 1;
//        c[2 * b[i]] -= (count[b[i]] - i);
//    }
//
//    for (int i = 1; i <= 2 * n; i++) {
//        printf("%d ", c[i]);
//    }
//
//    return 0;
//}
// 

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<cctype>
//#include<cstdlib>
//using namespace std;
//struct stu {
//    char name[15];
//    char id[11];
//    int cn;
//    int math;
//    int eng;
//    int lz;
//    int total;
//}s[20];
//int compareid(const void* e1, const void* e2)
//{
//    return strcmp(((stu*)e1)->id, ((stu*)e2)->id);
//}
//int compareid2(const void* e1, const void* e2)
//{
//    return -strcmp(((stu*)e1)->id, ((stu*)e2)->id);
//}
//int comparetotal(const void* e1, const void* e2)
//{
//	return -((stu*)e2)->total + ((stu*)e1)->total;
//}
//int compareid1(const void* e1, const void* e2)
//{
//    if (((stu*)e1)->total != ((stu*)e2)->total)
//    {
//        return 0;
//    }
//    else if((((stu*)e1)->total == ((stu*)e2)->total))
//    {
//		return strcmp(((stu*)e1)->id, ((stu*)e2)->id);
//	}
//}
//int n = 0;
//void change()
//{
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = i + 1; j < n; j++)
//        {
//            if (s[i].total == s[j].total)
//            {
//                if (strcmp(s[i].id, s[j].id) > 0)
//                {
//                    stu temp;
//                    temp = s[i];
//                    s[i] = s[j];
//                    s[j] = temp;
//                }
//            }
//        }
//    }
//
//}
//
//int main()
//{
//    //int n;
//    scanf("%d", &n);
//    int i = 0, j = 0, k = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%s %s %d %d %d %d", s[i].name, s[i].id, &s[i].cn, &s[i].math, &s[i].eng, &s[i].lz);
//        s[i].total = s[i].cn + s[i].math + s[i].eng + s[i].lz;
//    }
//    qsort(s, n, sizeof(s[0]), compareid2);
//    qsort(s, n, sizeof(s[0]), comparetotal);
//    //保证总分相同的情况下，按照学号从小到大排序,考虑有多个总分相同的情况
//    //封装成函数
//    //change();
//    //考虑有多个总分相同的情况，按照学号从小到大排序
//    //qsort(s, n, sizeof(s[0]), compareid1);
//    qsort(s, n, sizeof(s[0]), comparetotal);
//    change();
//    for (i = 0; i < n; i++)
//    {
//        printf("%s %s %d %d %d %d %d\n", s[i].name, s[i].id, s[i].cn, s[i].math, s[i].eng, s[i].lz, s[i].total);
//        //printf("%s\n", s[i].name);
//    }
//    int cn_max = s[0].cn;
//    int cn_max_index = 0;
//    int math_max = s[0].math;
//    int math_max_index = 0;
//    int eng_max = s[0].eng;
//    int eng_max_index = 0;
//    int lz_max = s[0].lz;
//    int lz_max_index = 0;
//    for (i = 0; i < n; i++)
//    {
//        if (s[i].cn > cn_max)
//        {
//            cn_max = s[i].cn;
//            cn_max_index = i;
//        }
//        if (s[i].math > math_max)
//        {
//			math_max = s[i].math;
//			math_max_index = i;
//		}
//        if (s[i].eng > eng_max)
//        {
//            eng_max = s[i].eng;
//            eng_max_index = i;
//        }
//        if (s[i].lz > lz_max)
//        {
//            lz_max = s[i].lz;
//            lz_max_index = i;
//        }
//    }
//    printf("%s %s %d\n", s[cn_max_index].name, s[cn_max_index].id, s[cn_max_index].cn);
//    printf("%s %s %d\n", s[math_max_index].name, s[math_max_index].id, s[math_max_index].math);
//    printf("%s %s %d\n", s[eng_max_index].name, s[eng_max_index].id, s[eng_max_index].eng);
//    printf("%s %s %d\n", s[lz_max_index].name, s[lz_max_index].id, s[lz_max_index].lz);
//    return 0;
//}

//for (i = 0; i < n; i++)
//{
//    for (j = i + 1; j < n; j++)
//    {
//        if (s[i].total == s[j].total)
//        {
//            if (strcmp(s[i].id, s[j].id) > 0)
//            {
//                stu temp;
//                temp = s[i];
//                s[i] = s[j];
//                s[j] = temp;
//            }
//        }
//    }
//}

   /*for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (s[i].total == s[j].total)
            {
                if (strcmp(s[i].id, s[j].id) > 0)
                {
                    stu temp;
                    temp=s[i];
                    s[i]=s[j];
                    s[j]=temp;
                }
            }
        }
    }*/

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<cctype>
//#include<cstdlib>
//using namespace std;
//int main()
//{
//    int n, m;
//    scanf("%d %d", &n, &m);
//    double arr[100][100] = { 0 };
//    double arr_new[100][100] = { 0 };
//
//    int i = 0, j = 0;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < m; j++)
//        {
//            scanf("%lf", &arr[i][j]);
//            arr_new[i][j] = arr[i][j];
//        }
//    }
//    for (i = 1; i < n - 1; i++)
//    {
//        for (j = 1; j < m - 1; j++)
//        {
//            arr_new[i][j] = (arr[i][j] + arr[i - 1][j] + arr[i + 1][j] + arr[i][j - 1] + arr[i][j + 1]) / 5.0;
//        }
//    }
//
//
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < m; j++)
//        {
//            printf("%.0lf ", arr_new[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}



//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//using namespace std;
//
//struct stu {
//    char name[15];
//    char id[11];
//    int cn;
//    int math;
//    int eng;
//    int lz;
//    int total;
//}s[20];
//
//int compareid(const void* e1, const void* e2) {
//    return strcmp(((stu*)e1)->id, ((stu*)e2)->id);
//}
//
//int comparetotal(const void* e1, const void* e2) {
//    // 按总成绩升序排列
//    return (((stu*)e1)->total - ((stu*)e2)->total);
//}
//
//// 冒泡排序实现
//void bubbleSort(stu arr[], int order[], int n) {
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = 0; j < n - i - 1; j++) {
//            // 如果总成绩相同，则按学号升序排列
//            if (arr[order[j]].total == arr[order[j + 1]].total && strcmp(arr[order[j]].id, arr[order[j + 1]].id) > 0) {
//                int temp = order[j];
//                order[j] = order[j + 1];
//                order[j + 1] = temp;
//            }
//        }
//    }
//}
//
//int main() {
//    int n = 0;
//    scanf("%d", &n);
//
//    for (int i = 0; i < n; i++) {
//        scanf("%s %s %d %d %d %d", s[i].name, s[i].id, &s[i].cn, &s[i].math, &s[i].eng, &s[i].lz);
//        s[i].total = s[i].cn + s[i].math + s[i].eng + s[i].lz;
//    }
//
//    // 初始化次序数组
//    int order[20];
//    for (int i = 0; i < n; i++) {
//        order[i] = i;
//    }
//
//    // 使用冒泡排序，处理总成绩升序排列，成绩相同的情况下按学号升序排列
//    bubbleSort(s, order, n);
//
//    // 输出结果
//    for (int i = 0; i < n; i++) 
//    {
//        int idx = order[i];
//        printf("%s %s %d %d %d %d %d\n", s[idx].name, s[idx].id, s[idx].cn, s[idx].math, s[idx].eng, s[idx].lz, s[idx].total);
//    }
//
//    // 找到并打印每个科目得分最高的学生
//    int cn_max_index = 0;
//    int math_max_index = 0;
//    int eng_max_index = 0;
//    int lz_max_index = 0;
//
//    for (int i = 0; i < n; i++) {
//        if (s[i].cn > s[cn_max_index].cn) {
//            cn_max_index = i;
//        }
//        if (s[i].math > s[math_max_index].math) {
//            math_max_index = i;
//        }
//        if (s[i].eng > s[eng_max_index].eng) {
//            eng_max_index = i;
//        }
//        if (s[i].lz > s[lz_max_index].lz) {
//            lz_max_index = i;
//        }
//    }
//
//    printf("%s %s %d\n", s[cn_max_index].name, s[cn_max_index].id, s[cn_max_index].cn);
//    printf("%s %s %d\n", s[math_max_index].name, s[math_max_index].id, s[math_max_index].math);
//    printf("%s %s %d\n", s[eng_max_index].name, s[eng_max_index].id, s[eng_max_index].eng);
//    printf("%s %s %d\n", s[lz_max_index].name, s[lz_max_index].id, s[lz_max_index].lz);
//
//    return 0;
//}

//#include<iostream>
//using namespace std;
//struct student {
//    string name;
//    string xuehao;
//    int yuwen;
//    int shuxue;
//    int english;
//    int lizong;
//    int z;
//} a[100];
//int main() {
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        cin >> a[i].name >> a[i].xuehao >> a[i].yuwen >> a[i].shuxue >> a[i].english >> a[i].lizong;
//        a[i].z = a[i].yuwen + a[i].shuxue + a[i].english + a[i].lizong;
//    }
//    int xx, yy, zz, tt;
//    int max1 = 0, max2 = 0, max3 = 0, max4 = 0;
//
//    for (int i = 0; i < n; i++) {
//        for (int j = i + 1; j < n; j++) {
//            if (a[i].z <= a[j].z)swap(a[i], a[j]);
//        }
//    }
//
//    for (int i = n - 1; i >= 0; i--) {
//        cout << a[i].name <<" "<<a[i].xuehao<<" "<<a[i].z << endl;
//
//    }
//    string k1 = "999999999", k2 = "9999999999", k3 = "999999999", k4 = "99999999";
//    for (int i = 0; i < n; i++) {
//        if (a[i].yuwen > max1 || (a[i].yuwen == max1 && a[i].xuehao < k1)) { xx = i; max1 = a[i].yuwen; k1 = a[i].xuehao; }
//        if (a[i].shuxue > max2 || (a[i].shuxue == max2 && a[i].xuehao < k2)) { yy = i; max2 = a[i].shuxue; k2 = a[i].xuehao; }
//        if (a[i].english > max3 || (a[i].english == max3 && a[i].xuehao < k3)) { zz = i; max3 = a[i].english; k3 = a[i].xuehao; }
//        if (a[i].lizong > max4 || (a[i].lizong == max4 && a[i].xuehao < k4)) { tt = i; max4 = a[i].lizong; k4 = a[i].xuehao; }
//
//    }
//    cout << a[xx].name << ' ' << a[xx].xuehao << ' ' << max1 << endl;
//    cout << a[yy].name << ' ' << a[yy].xuehao << ' ' << max2 << endl;
//    cout << a[zz].name << ' ' << a[zz].xuehao << ' ' << max3 << endl;
//    cout << a[tt].name << ' ' << a[tt].xuehao << ' ' << max4 << endl;
//
//}


//最终版本
//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//using namespace std;
//
//struct stu {
//    char name[15];
//    char id[11];
//    int cn;
//    int math;
//    int eng;
//    int lz;
//    int total;
//}s[20];
//
//int compareid(const void* e1, const void* e2) {
//    return strcmp(((stu*)e1)->id, ((stu*)e2)->id);
//}
//
//int comparetotal(const void* e1, const void* e2) {
//    // 按总成绩升序排列
//    return (((stu*)e1)->total - ((stu*)e2)->total);
//}
//
//int main() {
//    int n = 0;
//    scanf("%d", &n);
//
//    for (int i = 0; i < n; i++) {
//        scanf("%s %s %d %d %d %d", s[i].name, s[i].id, &s[i].cn, &s[i].math, &s[i].eng, &s[i].lz);
//        s[i].total = s[i].cn + s[i].math + s[i].eng + s[i].lz;
//    }
//
//    // 按照总成绩升序排列，成绩相同的情况下按学号升序排列
//    qsort(s, n, sizeof(s[0]), comparetotal);
//
//    // 用数组记录排好序后的次序
//    int order[20];
//    for (int i = 0; i < n; i++) {
//        order[i] = i;
//    }
//
//    // 冒泡排序实现排好序后的次序
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = 0; j < n - i - 1; j++) {
//            if (s[order[j]].total == s[order[j + 1]].total && strcmp(s[order[j]].id, s[order[j + 1]].id) > 0) {
//                int temp = order[j];
//                order[j] = order[j + 1];
//                order[j + 1] = temp;
//            }
//        }
//    }
//
//    // 输出结果
//    for (int i = 0; i < n; i++) {
//        int idx = order[i];
//        printf("%s\n", s[idx].name);
//
//        //printf("%s %s %d %d %d %d %d\n", s[idx].name, s[idx].id, s[idx].cn, s[idx].math, s[idx].eng, s[idx].lz, s[idx].total);
//    }
//
//    // 找到并打印每个科目得分最高的学生
//    int cn_max_index = 0;
//    int math_max_index = 0;
//    int eng_max_index = 0;
//    int lz_max_index = 0;
//    //还要重新按照学号从小到大排序
//    qsort(s, n, sizeof(s[0]), compareid);
//    for (int i = 0; i < n; i++) {
//        if (s[i].cn > s[cn_max_index].cn) {
//            cn_max_index = i;
//        }
//        if (s[i].math > s[math_max_index].math) {
//            math_max_index = i;
//        }
//        if (s[i].eng > s[eng_max_index].eng) {
//            eng_max_index = i;
//        }
//        if (s[i].lz > s[lz_max_index].lz) {
//            lz_max_index = i;
//        }
//    }
//
//    printf("%s %s %d\n", s[cn_max_index].name, s[cn_max_index].id, s[cn_max_index].cn);
//    printf("%s %s %d\n", s[math_max_index].name, s[math_max_index].id, s[math_max_index].math);
//    printf("%s %s %d\n", s[eng_max_index].name, s[eng_max_index].id, s[eng_max_index].eng);
//    printf("%s %s %d\n", s[lz_max_index].name, s[lz_max_index].id, s[lz_max_index].lz);
//
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<cstring>
//using namespace std;
//int main(){
//	int n;
//	cin>>n;
//	for(int i=0;i<n;i++)
//	{
//		char a[1001];
//		int b[1001];
//		int y=0;
//		cin>>a;
//		int l=strlen(a);
//		for(int j=0;j<l;j++)
//		{
//			if(a[j]>='0'&&a[j]<='4'||a[j]>='6'&&a[j]<='9')
//			{
//				int k=j;
//				while(a[k]>='0'&&a[k]<='4'||a[k]>='6'&&a[k]<='9'){k++;}
//				int sum=0;
//				int x=1;
//				for(int p=k-1;p>=j;p--)
//				{
//					sum*=10;
//				}
//				b[y++]=sum;
//				j=k-1;
//			}
//			
//		}
//		for(int j=0;j<y;j++)
//		{
//			for(int k=j+1;k<y;k++)
//			{
//				if(b[j]>b[k])swap(b[j],b[k]);
//			}
//		}
//		for(int j=0;j<y;j++)
//		{
//			bool flag=0;
//			for(int k=0;k<j;k++)
//			{
//				if(b[j]==b[k])flag=1;
//			}
//			if(flag)
//			{
//				continue;
//			}
//			else 
//			{
//				cout<<b[j]<<" ";
//			}
//		cout<<endl;
//	}
//	return 0;
//}
//}