#define _CRT_SECURE_NO_WARNINGS 1

//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	int& p = a;
//	a++;
//	p++;
//	printf("%d %d\n", a, p);
//	return 0;
//}

//#include<iostream>
//using namespace std;
////用引用实现两个数的交换
//void Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	cout << "交换前：a=" << a << " " << "b=" << b << endl;
//	Swap(a, b);
//	cout << "交换后：a=" << a << " " << "b=" << b << endl;
//	return 0;
//}

//#include<iostream>
//#include<cstdlib>
//#include<ctime>
//#include<iomanip>
//using namespace std;
//const int n = 10;
//void swap(int&, int&);
//int findpivot(int[], int, int);
//int partition(int[], int, int, int);
//void quicksort(int[], int, int);
////快速排序
//int main()
//{
//	int a[n];
//	srand((unsigned int)time(NULL));
//	for (int i = 0; i < n; i++)
//		a[i] = rand() % 100;
//	cout << "排序前的数组为：" << endl;
//	for (int i = 0; i < n; i++)
//		cout << setw(4) << a[i];
//	cout << endl;
//	quicksort(a, 0, n - 1);
//	cout << "排序后的数组为：" << endl;
//	for (int i = 0; i < n; i++)
//	{
//		cout << setw(4) << a[i];
//		if ((i + 1) % 10 == 0)
//		{
//			cout << endl;
//		}
//	}
//	return 0;
//}
//void swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//int findpivot(int a[], int i, int j)
//{
//	return (i + j) / 2;
//}
//int partition(int a[], int l, int r, int pivot)
//{
//	do
//	{
//		while (a[++l] < pivot);
//		while ((r != 0) && (a[--r] > pivot));
//		swap(a[l], a[r]);
//	} while (l < r);
//	swap(a[l], a[r]);
//	return l;
//}
//void quicksort(int a[], int i, int j)
//{
//	if (j <= i)
//		return;
//	int pivotindex = findpivot(a, i, j);
//	swap(a[pivotindex], a[j]);
//	int k = partition(a, i - 1, j, a[j]);
//	swap(a[k], a[j]);
//	if((k-i)>1)
//	{
//		quicksort(a, i, k - 1);
//	}
//	if ((j - k) > 1)
//	{
//		quicksort(a, k + 1, j);
//	}
//}


//#include<iostream>
//#include<cstdlib>
//#include<ctime>
//#include<iomanip>
//using namespace std;
//
//const int n = 100;
//
//// 交换数组中两个元素的值
//void swap(int& a, int& b)
//{
//    int temp = a;
//    a = b;
//    b = temp;
//}
//
//// 找到数组的中间元素索引
//int findpivot(int a[], int i, int j)
//{
//    return (i + j) / 2;
//}
//
//// 对数组进行分区操作，返回中轴（pivot）的索引
//int partition(int a[], int l, int r, int pivot)
//{
//    do
//    {
//        while (a[++l] < pivot);//不用判断l是否越界，因为pivot是最后一个元素，所以l不可能越界
//        while ((r != 0) && (a[--r] > pivot));//r!=0是为了防止r为负数
//        swap(a[l], a[r]);
//    } while (l < r);
//    swap(a[l], a[r]);
//    return l;
//}
//
//// 递归实现快速排序
//void quicksort(int a[], int i, int j)
//{
//    if (j <= i)
//        return;
//
//    // 找到中轴的索引并将中轴放到数组末尾
//    int pivotindex = findpivot(a, i, j);
//    swap(a[pivotindex], a[j]);
//
//    // 进行分区操作，获取中轴的最终位置
//    int k = partition(a, i - 1, j, a[j]);//传i-1是partition中的++l，所以要先减一
//    swap(a[k], a[j]);
//
//    // 递归对中轴左右两部分进行排序
//    if ((k - i) > 1)
//    {
//        quicksort(a, i, k - 1);
//    }
//    if ((j - k) > 1)
//    {
//        quicksort(a, k + 1, j);
//    }
//}
//
//int main()
//{
//    int a[n];
//
//    // 生成随机数组
//    srand((unsigned int)time(NULL));
//    for (int i = 0; i < n; i++)
//        a[i] = rand() % 1000;
//
//    // 输出排序前的数组
//    cout << "排序前的数组为：" << endl;
//    for (int i = 0; i < n; i++)
//        cout << setw(4) << a[i];
//    cout << endl;
//
//    // 调用快速排序算法
//    quicksort(a, 0, n - 1);
//
//    // 输出排序后的数组
//    cout << "排序后的数组为：" << endl;
//    for (int i = 0; i < n; i++)
//    {
//        cout << setw(4) << a[i];
//        if ((i + 1) % 10 == 0)
//        {
//            cout << endl;
//        }
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void shunshizhen(vector<vector<int>>& matrix, int x, int y, int r) {
//    int n = matrix.size();
//    vector<int> temp;
//    for (int i = x - 1; i < x + r - 1; i++) {
//        for (int j = y - 1; j < y + r - 1; j++) {
//            temp.push_back(matrix[i][j]);
//        }
//    }
//    for (int i = 0; i < r; i++) {
//        for (int j = 0; j < r; j++) {
//            matrix[x - 1 + j][y - 1 + r - 1 - i] = temp[i * r + j];
//        }
//    }
//}
//
//void nishizhen(vector<vector<int>>& matrix, int x, int y, int r) {
//    int n = matrix.size();
//    vector<int> temp;
//    for (int i = x - 1; i < x + r - 1; i++) {
//        for (int j = y - 1; j < y + r - 1; j++) {
//            temp.push_back(matrix[i][j]);
//        }
//    }
//    for (int i = 0; i < r; i++) {
//        for (int j = 0; j < r; j++) {
//            matrix[x - 1 + r - 1 - j][y - 1 + i] = temp[i * r + j];
//        }
//    }
//}
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//    vector<vector<int>> matrix(n, vector<int>(n));
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            matrix[i][j] = i * n + j + 1;
//        }
//    }
//    for (int i = 0; i < m; i++) {
//        int x, y, r, z;
//        cin >> x >> y >> r >> z;
//        if (z == 0) {
//            shunshizhen(matrix, x, y, r);
//        }
//        else {
//            nishizhen(matrix, x, y, r);
//        }
//    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << matrix[i][j] << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}

