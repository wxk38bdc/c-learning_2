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
////��Ŀ1 easy matrix δͨ��
//int check_0(int arr[])//4�������м���0
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
//	//���ַ�����ת��Ϊ��������
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
//	//�ж�
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



//��Ŀ ����
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

//��Ŀ ����
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
//    // �������ֲ����������ֽ���������
//    for (int i = 0; i < 2 * n; i++) {
//        scanf("%lld", &nums[i]);
//        xor_result ^= nums[i];
//    }
//
//    // �ҵ�������е�һ��Ϊ1��λ
//    long long mask = 1;
//    while ((xor_result & mask) == 0) {
//        mask <<= 1;
//    }
//
//    // ���鲢�ٴ����õ��������������ε�����
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
//    // �����С��������ǰ
//    if (result1 < result2) {
//        printf("%lld %lld\n", result1, result2);
//    }
//    else {
//        printf("%lld %lld\n", result2, result1);
//    }
//
//    free(nums); // �ͷŶ�̬������ڴ�
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
//// ���������������
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
//// �����������������ִ�����
//long long countValidStrings(int n) {
//    count = 0;
//    // ������1��ʼ����
//    dfs(n, 0, 0);
//    return count;
//}
//
//int main() {
//    int n;
//
//    // ��ȡ���������
//    while (scanf("%d", &n) == 1) {
//        // ���ú��������������������ִ�����
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
//        // ȡ����������С����
//        result[i] = (lastZeroIndex == INT_MAX) ? result[i] :
//            ((lastZeroIndex - i < result[i]) ? lastZeroIndex - i : result[i]);
//    }
//    //������һ��0
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
//    // ������
//    for (int i = 0; i < n; i++) {
//        printf("%d ", result[i]);
//    }
//
//    // �ͷŶ�̬������ڴ�
//    free(arr);
//    free(result);
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//// �ж�һ�����Ƿ�Ϊ����
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
    int* used = (int*)calloc(n + 1, sizeof(int)); // ���ڼ�¼�����Ƿ��Ѿ���ʹ��
    int* energy = (int*)malloc(n * sizeof(int)); // ���ڴ洢ÿ��ˮ��������

    // ��ʼ����������
    for (int i = 0; i < n; i++) {
        energy[i] = n - i;
    }

    int idx = n - 1; // ��ǰ�����ˮ������

    // ������ʽ����������������������
    while (idx >= 0) {
        while (energy[idx] > 0 && (used[energy[idx]] || !isPrime(idx + 1 + energy[idx]))) {
            energy[idx]--;
        }

        if (energy[idx] == 0) {
            // ��ǰ�����޷��������������ݵ���һ��ˮ��
            used[energy[idx + 1]] = 0;
            energy[idx] = n - idx;
            idx--;
        }
        else {
            // ��ǰ������������������������һ��ˮ��
            used[energy[idx]] = 1;
            idx++;

            if (idx == n) {
                // ����ˮ��������ϣ�������
                for (int i = 0; i < n; i++) {
                    crystals[i] = energy[i];
                }
                break;
            }
        }
    }

    // ������
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
//    // �������ֲ����������ֽ���������
//    for (int i = 0; i < 2 * n; i++) {
//        scanf("%lld", &nums[i]);
//        xor_result ^= nums[i];
//    }
//
//    // �ҵ�������е�һ��Ϊ1��λ
//    long long mask = 1;
//    while ((xor_result & mask) == 0) {
//        mask <<= 1;
//    }
//
//    // ���鲢�ٴ����õ��������������ε�����
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
//    // �����С��������ǰ
//    if (result1 < result2) {
//        printf("%lld %lld\n", result1, result2);
//    }
//    else {
//        printf("%lld %lld\n", result2, result1);
//    }
//
//    free(nums); // �ͷŶ�̬������ڴ�
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
//    for (i = 1; i <= n; i++)//�±��1��ʼ���������
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
//    canRepresent[0] = true;  // 0 ���Ա���ʾ
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
//    cout << "�������������ĸ��� n: ";
//    cin >> n;
//
//    vector<int> numbers(n);
//
//    cout << "������ " << n << " ����������" << endl;
//    for (int i = 0; i < n; ++i) {
//        cin >> numbers[i];
//    }
//
//    int target;
//    cout << "������Ҫ�жϵ���������" << endl;
//    cin >> target;
//
//    if (canRepresent(numbers, target)) {
//        cout << target << " ���Ա������� " << n << " ����������ʾ��" << endl;
//    }
//    else {
//        cout << target << " ���ܱ������� " << n << " ����������ʾ��" << endl;
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
//    int target = maxNumber * 100;  // ��������������10����ʼ���±���
//
//    vector<bool> canRepresent(target + 1, false);
//    canRepresent[0] = true;  // 0 ���Ա���ʾ
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
//    return 1;  // ���������ܱ���ʾ�������ϲ���ִ�е���һ��
//}
//
//int main() {
//    int n;
//    cout << "�������������ĸ��� n: ";
//    cin >> n;
//
//    vector<int> numbers(n);
//
//    cout << "������ " << n << " ����������" << endl;
//    for (int i = 0; i < n; ++i) {
//        cin >> numbers[i];
//    }
//
//    int result = findFirstUnrepresentable(numbers);
//
//    cout << "��һ�����ܱ������� " << n << " ����������ʾ���������ǣ�" << result << endl;
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
//    //ö�٣�n��Ԫ�أ������Ӽ�����=2��n�η���ʱ�临�Ӷ�2��n�η���ָ����
//    int itotal = 1 << str1.length();
//    for (i = 0; i < itotal; i++) {
//        for (j = 0; j < str1.length(); j++) { //���������Ƶ�ÿһλ������һλ�ǲ���1.
//            if (((1 << j) & i) != 0)//  ��ǰj��һλȡ1����i�������㣬���������Ϊ1˵����һλҪȡ��
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
* ��һ��
 #include <cstdio>
#include <cstdlib>
#include <cstring>
#include<iostream>
using namespace std;
char ans[1500][11] = { 0 }; // ���ڱ�����
int ans_index = 0; // ���ڼ�¼����ĸ���
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
        // ������
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
    //�ж�ans[i]�Ƿ���s���Ӵ����ַ���s�е�λ�ÿ��Բ�����������������ҳ���
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


////����������������ͨ���ˣ�������
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include<iostream>
//using namespace std;
//char s[301] = { 0 };
//int ans_index = 0; // ���ڼ�¼����ĸ���
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
//    //��֤�ܷ���ͬ������£�����ѧ�Ŵ�С��������,�����ж���ܷ���ͬ�����
//    //��װ�ɺ���
//    //change();
//    //�����ж���ܷ���ͬ�����������ѧ�Ŵ�С��������
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
//    // ���ܳɼ���������
//    return (((stu*)e1)->total - ((stu*)e2)->total);
//}
//
//// ð������ʵ��
//void bubbleSort(stu arr[], int order[], int n) {
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = 0; j < n - i - 1; j++) {
//            // ����ܳɼ���ͬ����ѧ����������
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
//    // ��ʼ����������
//    int order[20];
//    for (int i = 0; i < n; i++) {
//        order[i] = i;
//    }
//
//    // ʹ��ð�����򣬴����ܳɼ��������У��ɼ���ͬ������°�ѧ����������
//    bubbleSort(s, order, n);
//
//    // ������
//    for (int i = 0; i < n; i++) 
//    {
//        int idx = order[i];
//        printf("%s %s %d %d %d %d %d\n", s[idx].name, s[idx].id, s[idx].cn, s[idx].math, s[idx].eng, s[idx].lz, s[idx].total);
//    }
//
//    // �ҵ�����ӡÿ����Ŀ�÷���ߵ�ѧ��
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


//���հ汾
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
//    // ���ܳɼ���������
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
//    // �����ܳɼ��������У��ɼ���ͬ������°�ѧ����������
//    qsort(s, n, sizeof(s[0]), comparetotal);
//
//    // �������¼�ź����Ĵ���
//    int order[20];
//    for (int i = 0; i < n; i++) {
//        order[i] = i;
//    }
//
//    // ð������ʵ���ź����Ĵ���
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
//    // ������
//    for (int i = 0; i < n; i++) {
//        int idx = order[i];
//        printf("%s\n", s[idx].name);
//
//        //printf("%s %s %d %d %d %d %d\n", s[idx].name, s[idx].id, s[idx].cn, s[idx].math, s[idx].eng, s[idx].lz, s[idx].total);
//    }
//
//    // �ҵ�����ӡÿ����Ŀ�÷���ߵ�ѧ��
//    int cn_max_index = 0;
//    int math_max_index = 0;
//    int eng_max_index = 0;
//    int lz_max_index = 0;
//    //��Ҫ���°���ѧ�Ŵ�С��������
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