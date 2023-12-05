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

