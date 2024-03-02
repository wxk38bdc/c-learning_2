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
//    char a[1000]; // 原始字符串
//    cin >> a;
//    int len = strlen(a);
//    char b[1000]; // 压缩后的字符串
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
//    // 将压缩后的字符串拷贝到输出参数指向的内存中
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


//// 学生类
//class Student {
//public:
//    int id;
//    int score;
//
//    // 构造函数
//    Student(int id, int score) : id(id), score(score) {}
//
//    // 重载小于运算符，用于排序
//    bool operator<(const Student& other) const {
//        return id < other.id; // 按照学号从小到大排序
//    }
//};
//
//// 找出最高成绩的学生
//void max(Student* students, int size) {
//    // 找出最高分
//    int maxScore = INT_MIN;
//    for (int i = 0; i < size; ++i) {
//        maxScore = max(maxScore, students[i].score);
//    }
//
//    // 输出最高分对应的学生
//    vector<Student> maxStudents; // 存储最高分对应的学生对象
//    for (int i = 0; i < size; ++i) {
//        if (students[i].score == maxScore) {
//            maxStudents.push_back(students[i]);
//        }
//    }
//
//    // 对最高分对应的学生对象进行排序
//    sort(maxStudents.begin(), maxStudents.end());
//
//    // 输出排序后的最高分对应的学生
//    for (const auto& student : maxStudents) {
//        cout << student.id << " " << student.score << endl;
//    }
//}
//
//int main() {
//    // 读取输入数据
//    vector<Student> students;
//    for (int i = 0; i < 4; ++i) {
//        int id, score;
//        cin >> id >> score;
//        students.push_back(Student(id, score));
//    }
//
//    // 调用函数找出最高成绩的学生
//    max(&students[0], students.size());
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//// Matrix类
//class Matrix {
//private:
//    vector<vector<int>> data; // 用于存储矩阵数据
//    int rows; // 矩阵行数
//    int cols; // 矩阵列数
//
//public:
//    // 构造函数
//    Matrix(int rows, int cols) : rows(rows), cols(cols) {
//        // 初始化矩阵数据为0
//        data.resize(rows, vector<int>(cols, 0));
//    }
//
//    // 重载二元运算符+
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
//    // 重载二元运算符-
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
//    // 重载二元运算符*
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
//    // 重载输出运算符<<
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
//    // 设置矩阵元素
//    void setElement(int row, int col, int value) {
//        if (row >= 0 && row < rows && col >= 0 && col < cols) {
//            data[row][col] = value;
//        }
//    }
//};
//
//int main() {
//    // 读取输入数据
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
//    // 输出加减乘后的矩阵
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
//	for (int i = 0; i < m; ++i) { // 尝试以每种食物为主要成分
//		int meals = 0;
//		vector<int> b(a); // 复制一份食物数量数组进行操作
//		while (*min_element(b.begin(), b.end()) >= 0) { // 确保所有食物数量非负
//			int cnt = 0;
//			for (int j = 0; j < m && cnt < n; ++j) {
//				if (b[j] > 0) {
//					--b[j]; // 使用一个单位的食物j
//					++cnt; // 套餐中的食物数量增加
//				}
//			}
//			if (cnt == n) ++meals; // 如果成功组成一个套餐，计数增加
//			else break; // 如果不能组成套餐，结束循环
//		}
//		maxMeals = max(maxMeals, meals); // 更新最大套餐数量
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

