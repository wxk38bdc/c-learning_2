#define _CRT_SECURE_NO_WARNINGS

//int main()
//{
//	int row;
//	int col;
//	cin >> row;
//	cin >> col;
//	int i = 0, j = 0;
//	int** a = new int*[row];
//	for (i = 0; i < row; i++)
//	{
//		a[i] = new int[col];
//	}
//	int** b = new int* [row];
//	for (i = 0; i < row; i++)
//	{
//		b[i] = new int[col];
//	}
//	int** c = new int* [row];
//	for (i = 0; i < row; i++)
//	{
//		c[i] = new int[col];
//	}
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			cin >> a[i][j];
//		}
//	}
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			cin >> b[i][j];
//		}
//	}
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			c[i][j] = a[i][j] + b[i][j];
//			cout << c[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}

//using namespace std;
//
//void stringZip(const char* pInputStr, int lInputLen, char* pOutputStr);
//
//int main()
//{
//    char a[1000]; // ԭʼ�ַ���
//    cin >> a;
//    int len = strlen(a);
//    char b[1000]; // ѹ������ַ���
//    stringZip(a, len, b);
//    cout << b << endl;
//    return 0;
//}
//
//void stringZip(const char* pInputStr, int lInputLen, char* pOutputStr) {
//    string a(pInputStr);
//    string b;
//    char prev = '\0';
//    char cur = a[0];
//    int count = 0;
//    for (int i = 0; i < a.size(); i++)
//    {
//        if (a[i] == cur)
//        {
//            count++;
//        }
//        else
//        {
//            prev = cur;
//            cur = a[i];
//            if (count > 1)
//            {
//                char ch = '0' + count;
//                b += ch;
//            }
//            b += prev;
//            count = 1;
//        }
//    }
//    if (count > 1)
//    {
//        char ch = '0' + count;
//        b += ch;
//    }
//    b += cur;
//    // ��ѹ������ַ����������������ָ����ڴ���
//    strcpy(pOutputStr, b.c_str());
//}

//bool isPrime(int i)
//{
//	if (i < 2)
//	{
//		return false;
//	}
//	for (int j = 2; j * j <= i; j++)
//	{
//		if (i % j == 0)
//			return false;
//	}
//	return true;
//}
//int main()
//{
//	list<int>myList;
//	int i;
//	while (1)
//	{
//		cin >> i;
//		if (isPrime(i))
//		{
//			myList.push_back(i);
//		}
//		else
//		{
//			break;
//		}
//	}
//	myList.sort();
//	myList.unique();
//	for (auto&e : myList)
//	{
//		cout << e << " ";
//	}
//	return 0;
//}


//// ѧ����
//class Student {
//public:
//    int id;
//    int score;
//
//    // ���캯��
//    Student(int id, int score) : id(id), score(score) {}
//
//    // ����С�����������������
//    bool operator<(const Student& other) const {
//        return id < other.id; // ����ѧ�Ŵ�С��������
//    }
//};
//
//// �ҳ���߳ɼ���ѧ��
//void max(Student* students, int size) {
//    // �ҳ���߷�
//    int maxScore = INT_MIN;
//    for (int i = 0; i < size; ++i) {
//        maxScore = max(maxScore, students[i].score);
//    }
//
//    // �����߷ֶ�Ӧ��ѧ��
//    vector<Student> maxStudents; // �洢��߷ֶ�Ӧ��ѧ������
//    for (int i = 0; i < size; ++i) {
//        if (students[i].score == maxScore) {
//            maxStudents.push_back(students[i]);
//        }
//    }
//
//    // ����߷ֶ�Ӧ��ѧ�������������
//    sort(maxStudents.begin(), maxStudents.end());
//
//    // �����������߷ֶ�Ӧ��ѧ��
//    for (const auto& student : maxStudents) {
//        cout << student.id << " " << student.score << endl;
//    }
//}
//
//int main() {
//    // ��ȡ��������
//    vector<Student> students;
//    for (int i = 0; i < 4; ++i) {
//        int id, score;
//        cin >> id >> score;
//        students.push_back(Student(id, score));
//    }
//
//    // ���ú����ҳ���߳ɼ���ѧ��
//    max(&students[0], students.size());
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//// Matrix��
//class Matrix {
//private:
//    vector<vector<int>> data; // ���ڴ洢��������
//    int rows; // ��������
//    int cols; // ��������
//
//public:
//    // ���캯��
//    Matrix(int rows, int cols) : rows(rows), cols(cols) {
//        // ��ʼ����������Ϊ0
//        data.resize(rows, vector<int>(cols, 0));
//    }
//
//    // ���ض�Ԫ�����+
//    Matrix operator+(const Matrix& other) const {
//        Matrix result(rows, cols);
//        for (int i = 0; i < rows; ++i) {
//            for (int j = 0; j < cols; ++j) {
//                result.data[i][j] = data[i][j] + other.data[i][j];
//            }
//        }
//        return result;
//    }
//
//    // ���ض�Ԫ�����-
//    Matrix operator-(const Matrix& other) const {
//        Matrix result(rows, cols);
//        for (int i = 0; i < rows; ++i) {
//            for (int j = 0; j < cols; ++j) {
//                result.data[i][j] = data[i][j] - other.data[i][j];
//            }
//        }
//        return result;
//    }
//
//    // ���ض�Ԫ�����*
//    Matrix operator*(const Matrix& other) const {
//        Matrix result(rows, other.cols);
//        for (int i = 0; i < rows; ++i) {
//            for (int j = 0; j < other.cols; ++j) {
//                for (int k = 0; k < cols; ++k) {
//                    result.data[i][j] += data[i][k] * other.data[k][j];
//                }
//            }
//        }
//        return result;
//    }
//
//    // ������������<<
//    friend ostream& operator<<(ostream& os, const Matrix& matrix) {
//        for (int i = 0; i < matrix.rows; ++i) {
//            for (int j = 0; j < matrix.cols; ++j) {
//                os << matrix.data[i][j];
//                if (j < matrix.cols - 1) {
//                    os << " ";
//                }
//            }
//            if (i < matrix.rows - 1) {
//                os << endl;
//            }
//        }
//        return os;
//    }
//
//    // ���þ���Ԫ��
//    void setElement(int row, int col, int value) {
//        if (row >= 0 && row < rows && col >= 0 && col < cols) {
//            data[row][col] = value;
//        }
//    }
//};
//
//int main() {
//    // ��ȡ��������
//    Matrix A(3, 3), B(3, 3);
//    for (int i = 0; i < 3; ++i) {
//        for (int j = 0; j < 3; ++j) {
//            int value;
//            cin >> value;
//            A.setElement(i, j, value);
//        }
//    }
//    for (int i = 0; i < 3; ++i) {
//        for (int j = 0; j < 3; ++j) {
//            int value;
//            cin >> value;
//            B.setElement(i, j, value);
//        }
//    }
//
//    // ����Ӽ��˺�ľ���
//    cout << (A + B) << endl;
//    cout << (A - B) << endl;
//    cout << (A * B) << endl;
//
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<int> a(m);
//	for (int i = 0; i < m; ++i) {
//		cin >> a[i];
//	}
//	
//	int maxMeals = 0;
//	for (int i = 0; i < m; ++i) { // ������ÿ��ʳ��Ϊ��Ҫ�ɷ�
//		int meals = 0;
//		vector<int> b(a); // ����һ��ʳ������������в���
//		while (*min_element(b.begin(), b.end()) >= 0) { // ȷ������ʳ�������Ǹ�
//			int cnt = 0;
//			for (int j = 0; j < m && cnt < n; ++j) {
//				if (b[j] > 0) {
//					--b[j]; // ʹ��һ����λ��ʳ��j
//					++cnt; // �ײ��е�ʳ����������
//				}
//			}
//			if (cnt == n) ++meals; // ����ɹ����һ���ײͣ���������
//			else break; // �����������ײͣ�����ѭ��
//		}
//		maxMeals = max(maxMeals, meals); // ��������ײ�����
//	}
//	
//	cout << maxMeals << endl;
//	
//	return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//	long long n, k, l, sum = 0;
//	cin >> n >> k >> l;
//	long long m = n * k;
//	long long* a = new long long[m];
//	for (int i = 0; i < m; i++)
//		cin >> a[i];
//	sort(a, a + m);
//	for (int i = 0; i < n; i++)
//		sum += a[i];
//	if (a[n - 1] - a[0] > l)
//		cout << 0;
//	else
//		cout << sum;
//	return 0;
//}

