//#include<bits/stdc++.h>
//using namespace std;
////用指针初始化，再写一遍
//int main() {
//	// 初始化并输入
//	int n, m, k;
//	int i = 0, j = 0, h = 0;
//	cin >> n >> m >> k;
//
//	int**A=new int*[n];
//	for(i=0;i<n;i++)
//	{
//		A[i]=new int[m];
//	}
//
//	int **B=new int*[m];
//	for(i=0;i<m;i++)
//	{
//		B[i]=new int[k];
//	}
//	
//	for(i = 0; i < n; i++) {
//		for(j = 0; j < m; j++) {
//			cin >> A[i][j];
//		}
//	}
//	for(i = 0; i < m; i++) {
//		for(j = 0; j < k; j++) {
//			cin >> B[i][j];
//		}
//	}
//	// A的转置
//	for(i = 0; i < m; i++) {
//		for(j = 0; j < n; j++) {
//			cout << A[j][i] << " ";
//		}
//		cout << endl;
//	}
//	// A+B or A*B
//	if(n == m && m == k) {
//		for(i = 0; i < n; i++) {
//			for(j = 0; j < n; j++) {
//				cout << A[i][j] + B[i][j] << " ";
//			}
//			cout << endl;
//		}
//	} else {
//		int C[n][k] ; // 初始化结果矩阵C
//		for(i=0;i<n;i++)
//		{
//			for(j=0;j<k;j++)
//			{
//				C[i][j]=0;
//			}
//		}
//		for(i = 0; i < n; i++) {
//			for(j = 0; j < k; j++) {
//				for(h = 0; h < m; h++) {
//					C[i][j] += A[i][h] * B[h][j]; // 根据矩阵乘法的定义，计算C[i][j]
//				}
//			}
//		}
//		// 打印乘法结果矩阵C
//		for(i = 0; i < n; i++) {
//			for(j = 0; j < k; j++) {
//				cout << C[i][j] << " ";
//			}
//			cout << endl;
//		}
//	}
//	//释放内存
//	for(i=0;i<n;i++)
//	{
//		delete[]A[i];
//	}	
//    delete[]A;
//	for(i=0;i<m;i++)
//	{
//		delete[]B[i];
//	}	
//	delete[]B;
//
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//const int MAX_SIZE = 31; 
//
//int FindSubstr(char *srcStr, char *subStr) {
//	int count = 0;
//	char *pch = strstr(srcStr, subStr);
//	while (pch) {
//		cout << (pch - srcStr) << " ";
//		count++;
//		pch = strstr(pch + 1, subStr);
//	}
//	cout << endl;
//	return count;
//}
//
//int main() {
//	char srcStr[MAX_SIZE], subStr[MAX_SIZE];
//	cin>>srcStr;
//	cin>>subStr;
//	int times = FindSubstr(srcStr, subStr);
//	cout << times << endl;
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//void Swap(int *x,int *y)
//{
//	int tmp=*x;
//	*x=*y;
//	*y=tmp;
//}
//void Sort(int *A, int len) {
//	int i = 0, j = 0;
//	for (i = 0; i < len - 1; i++) {
//		for (j = 0; j < len - i - 1; j++) {
//			if (A[j] > A[j + 1]) {
//				Swap(&A[j], &A[j + 1]);
//			}
//		}
//	}
//}
//
//int main()
//{
//	int n;
//	cin>>n;
//	int*A=new int[n];
//	int i=0;
//	for(i=0;i<n;i++)
//	{
//		cin>>A[i];
//	}
//	Sort(A,n);
//	for(i=0;i<n;i++)
//	{
//		cout<<A[i]<<" ";
//	}
//	delete[]A;
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//struct student {
//	char name[11];
//	long long id;
//	int chi;
//	int mat;
//	int eng;
//	int csc; //理科综合
//	int all;
//};
//void SortID(student *arr, int n) {
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = 0; j < n - 1 - i; j++) {
//			if (arr[j].id > arr[j + 1].id) {
//				swap(arr[j], arr[j + 1]);
//			}
//		}
//	}
//}
//void Sort(student *arr, int n) {
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = 0; j < n - 1 - i; j++) {
//			if (arr[j].all > arr[j + 1].all) {
//				swap(arr[j], arr[j + 1]);
//			}
//		}
//	}
//}
//
//int main() {
//	int n;
//	cin >> n;
//	student *arr = new student[n];
//	int i = 0;
//	
//
//	
//	for (i = 0; i < n; i++) {
//		cin >> arr[i].name >> arr[i].id >> arr[i].chi >> arr[i].mat >> arr[i].eng >> arr[i].csc;
//		arr[i].all = arr[i].chi + arr[i].mat + arr[i].eng + arr[i].csc;
//	}
//	SortID(arr, n);
//	Sort(arr, n);
//	
//	for (i = 0; i < n; i++) {
//		cout << arr[i].name << endl;
//	}
//	SortID(arr, n);
//	int maxChi = 0, maxMat = 0, maxEng = 0, maxCsc = 0; // 索引
//	for (i = 0; i < n; i++) {
//		if (arr[i].chi > arr[maxChi].chi) maxChi = i;
//		if (arr[i].mat > arr[maxMat].mat) maxMat = i;
//		if (arr[i].eng > arr[maxEng].eng) maxEng = i;
//		if (arr[i].csc > arr[maxCsc].csc) maxCsc = i;
//	}
//	// 输出每科最高分的姓名、学号、成绩
//	cout << arr[maxChi].name<< " "<< arr[maxChi].id << " " << arr[maxChi].chi << endl;
//	cout << arr[maxMat].name << " "<< arr[maxMat].id << " " << arr[maxMat].mat << endl;
//	cout  << arr[maxEng].name << " " << arr[maxEng].id << " " << arr[maxEng].eng << endl;
//	cout  << arr[maxCsc].name << " " << arr[maxCsc].id << " " << arr[maxCsc].csc << endl;
//	
//	delete[] arr;
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//long long C(long long n, long long k) {
//	long long C[n + 1][k + 1];
//	long long i, j;
//	
//	// 初始化边界情况
//	for (i = 0; i <= n; i++) {
//		for (j = 0; j <= min(i, k); j++) {
//			if (j == 0 || j == i) {
//				C[i][j] = 1;
//			} else {
//				C[i][j] = C[i-1][j-1] + C[i-1][j];
//			}
//		}
//	}
//	
//	return C[n][k];
//}
//int main()
//{
//	int n,m;
//	cin>>n>>m;
//	long long all=C(n+1,2)*C(m+1,2);
//
//	long long square=0,rectangle=0;
//	if(n>m)swap(n,m);//确保n<=m
//	for(int i=0;i<n;i++)
//	{
//		square+=(n-i)*(m-i);
//	}
//	rectangle=all-square;
//	cout<<square<<" "<<rectangle;
//	return 0;
//}

//class Solution {
//public:
//    int subarraysDivByK(vector<int>& nums, int k) {
//        int n = nums.size();
//        int count = 0;//计算次数
//        unordered_map<int, int>remainder_times;
//        int sum = 0;//计算前缀和
//        remainder_times[0] = 1;
//        for (int i = 0; i < n; i++)
//        {
//            sum += nums[i];
//            int rem = (sum % k + k) % k;
//            if (remainder_times.count(rem))count += remainder_times[rem];
//            remainder_times[rem]++;
//        }
//        return count;
//    }
//};

//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//
//bool isOK(ll H[], ll W[], ll N, ll K, ll len) {
//	ll count = 0; // 计算能分出边长为len巧克力总数
//	for (ll i = 0; i < N; i++) {
//		count += (H[i] / len) * (W[i] / len);
//	}
//	return count >= K;
//}
//
//int main() {
//	ll N, K;
//	cin >> N >> K;
//	ll H[N], W[N]; // 长*宽
//	ll maxLen = 0; // 存储所有巧克力中最小尺寸的最大值
//
//	for (ll i = 0; i < N; i++) {
//		cin >> H[i] >> W[i];
//		if (H[i] < W[i]) swap(H[i], W[i]); // 保证长>=宽
//		maxLen = max(maxLen, min(H[i], W[i])); // 更新最大可能的len
//	}
//
//	ll low = 1, high = maxLen, ans = 0;
//	while (low <= high) {
//		ll mid = low + (high - low) / 2;
//		if (isOK(H, W, N, K, mid)) {
//			ans = mid; // 更新答案
//			low = mid + 1; // 尝试寻找更大的len
//		}
//		else {
//			high = mid - 1;
//		}
//	}
//
//	cout << ans << endl;
//	return 0;
//}

//class Solution {
//public:
//    int missingNumber(vector<int>& nums) {
//        int n = nums.size(), ret = 0;
//        for (int i = 0; i <= n; i++)ret ^= i;
//        for (int i = 0; i < n; i++)ret ^= nums[i];
//        return ret;
//    }
//};

//class Solution {
//public:
//    int getSum(int a, int b) {
//        int sum;
//        int carry;//计算进位
//        sum = a ^ b;//无进位和
//        carry = (a & b) << 1;//
//        if (carry)return getSum(sum, carry);
//        return sum;
//
//    }
//};

//38. 外观数列
//class Solution {
//public:
//    string countAndSay(int n) {
//        string prev = "";
//        string cur = "1";
//        for (int i = 1; i < n; i++)
//        {
//            prev = cur;
//            cur = "";
//            int left = 0, right = 0;
//            while (right <= prev.size())
//            {
//                //考虑最右边情况
//                if (right == prev.size())
//                {
//                    int count = right - left; // 数量
//                    cur += std::to_string(count) + prev[left];
//                    break;
//                }
//                //一般情况
//                if (prev[right] == prev[left])
//                {
//                    right++;
//                }
//                else
//                {
//                    int count = right - left; // 数量
//                    cur += std::to_string(count) + prev[left];
//                    left = right;
//                }
//            }
//
//        }
//        return cur;
//    }
//};

//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int n = prices.size();
//        int dp_i_0 = 0, dp_i_1 = INT_MIN;
//        for (int i = 0; i < n; i++)
//        {
//            int temp = dp_i_0;
//            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
//            dp_i_1 = max(dp_i_1, temp - prices[i]);
//        }
//        return dp_i_0;
//    }
//};

//leetcode 493. 翻转对
//class Solution {
//public:
//	long long tmp[50001];
//	long long ret;
//	void MergeSort(vector<long long>& a, long long left, long long right)
//	{
//		if (left < right)
//		{
//			//[left,mid][mid+1,right]
//			long long mid = left + (right - left) / 2; // 避免溢出
//			MergeSort(a, left, mid); // 排序左半部分
//			MergeSort(a, mid + 1, right); // 排序右半部分
//
//			long long i = left;
//			long long j = mid + 1;
//			long long k = left;
//
//			long long tmpi = i, tmpj = j, tmpk = k;
//			while (tmpi <= mid && tmpj <= right)
//			{
//				while (tmpj <= right && a[tmpi] <= a[tmpj] * 2)tmpj++;
//				//此时 a[tmpi]>2*a[tmpj]
//				ret += right - tmpj + 1;
//				tmpi++;
//			}
//
//			// 合并两个有序区间
//			while (i <= mid && j <= right) {
//				if (a[i] <= a[j]) {
//					tmp[k++] = a[j++];
//				}
//				else {
//					tmp[k++] = a[i++];
//				}
//			}
//
//			// 处理剩余的元素
//			while (i <= mid) {
//				tmp[k++] = a[i++];
//			}
//			while (j <= right) {
//				tmp[k++] = a[j++];
//			}
//
//			// 将合并后的数组复制回原数组
//			for (i = left; i <= right; i++) {
//				a[i] = tmp[i];
//			}
//		}
//	}
//	int reversePairs(vector<int>& nums) {
//		ret = 0;
//		vector<long long>numbers(nums.size());
//		for (int i = 0; i < nums.size(); i++)
//		{
//			numbers[i] = nums[i];
//		}
//		MergeSort(numbers, 0, nums.size() - 1);
//		return ret;
//	}
//};

//leetcode 315. 计算右侧小于当前元素的个数
//class Solution {
//public:
//    void MergeSort(int left, int right, vector<int>& nums, vector<int>& count, vector<int>& temp, vector<int>& index, vector<int>& tempIndex) {
//        if (left >= right) return;
//
//        int mid = left + (right - left) / 2;
//        MergeSort(left, mid, nums, count, temp, index, tempIndex);
//        MergeSort(mid + 1, right, nums, count, temp, index, tempIndex);
//
//        // Merge two sorted halves
//        int i = left, j = mid + 1, k = left;
//        while (i <= mid && j <= right) {
//            if (nums[index[i]] <= nums[index[j]]) {
//                temp[k] = index[i];
//                count[index[i]] += j - mid - 1;
//                i++;
//            }
//            else {
//                temp[k] = index[j];
//                j++;
//            }
//            k++;
//        }
//
//        while (i <= mid) {
//            temp[k] = index[i];
//            count[index[i]] += j - mid - 1;
//            i++;
//            k++;
//        }
//
//        while (j <= right) {
//            temp[k] = index[j];
//            j++;
//            k++;
//        }
//
//        // Copy back to the original index array for the next iteration
//        for (int i = left; i <= right; i++) {
//            index[i] = temp[i];
//        }
//    }
//
//    vector<int> countSmaller(vector<int>& nums) {
//        int n = nums.size();
//        vector<int> count(n, 0), temp(n), index(n), tempIndex(n);
//        for (int i = 0; i < n; i++) {
//            index[i] = i;
//        }
//
//        MergeSort(0, n - 1, nums, count, temp, index, tempIndex);
//
//        return count;
//    }
//};