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
////������ʵ���������Ľ���
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
//	cout << "����ǰ��a=" << a << " " << "b=" << b << endl;
//	Swap(a, b);
//	cout << "������a=" << a << " " << "b=" << b << endl;
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
////��������
//int main()
//{
//	int a[n];
//	srand((unsigned int)time(NULL));
//	for (int i = 0; i < n; i++)
//		a[i] = rand() % 100;
//	cout << "����ǰ������Ϊ��" << endl;
//	for (int i = 0; i < n; i++)
//		cout << setw(4) << a[i];
//	cout << endl;
//	quicksort(a, 0, n - 1);
//	cout << "����������Ϊ��" << endl;
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
//// ��������������Ԫ�ص�ֵ
//void swap(int& a, int& b)
//{
//    int temp = a;
//    a = b;
//    b = temp;
//}
//
//// �ҵ�������м�Ԫ������
//int findpivot(int a[], int i, int j)
//{
//    return (i + j) / 2;
//}
//
//// ��������з����������������ᣨpivot��������
//int partition(int a[], int l, int r, int pivot)
//{
//    do
//    {
//        while (a[++l] < pivot);//�����ж�l�Ƿ�Խ�磬��Ϊpivot�����һ��Ԫ�أ�����l������Խ��
//        while ((r != 0) && (a[--r] > pivot));//r!=0��Ϊ�˷�ֹrΪ����
//        swap(a[l], a[r]);
//    } while (l < r);
//    swap(a[l], a[r]);
//    return l;
//}
//
//// �ݹ�ʵ�ֿ�������
//void quicksort(int a[], int i, int j)
//{
//    if (j <= i)
//        return;
//
//    // �ҵ������������������ŵ�����ĩβ
//    int pivotindex = findpivot(a, i, j);
//    swap(a[pivotindex], a[j]);
//
//    // ���з�����������ȡ���������λ��
//    int k = partition(a, i - 1, j, a[j]);//��i-1��partition�е�++l������Ҫ�ȼ�һ
//    swap(a[k], a[j]);
//
//    // �ݹ���������������ֽ�������
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
//    // �����������
//    srand((unsigned int)time(NULL));
//    for (int i = 0; i < n; i++)
//        a[i] = rand() % 1000;
//
//    // �������ǰ������
//    cout << "����ǰ������Ϊ��" << endl;
//    for (int i = 0; i < n; i++)
//        cout << setw(4) << a[i];
//    cout << endl;
//
//    // ���ÿ��������㷨
//    quicksort(a, 0, n - 1);
//
//    // �������������
//    cout << "����������Ϊ��" << endl;
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

