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
