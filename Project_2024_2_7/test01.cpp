#define _CRT_SECURE_NO_WARNINGS 1
#include <cassert>
#include <cctype>
#include <cerrno>
//#include <cfloat>
//#include <ciso646>
//#include <climits>
//#include <clocale>
#include <cmath>
//#include <csetjmp>
//#include <csignal>
//#include <cstdarg>
//#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
//#include <cwchar>
//#include <cwctype>
#include <algorithm>
//#include <bitset>
//#include <complex>
//#include <deque>
//#include <exception>
//#include <fstream>
//#include <functional>
#include <iomanip>
//#include <ios>
//#include <iosfwd>
#include <iostream>
//#include <istream>
//#include <iterator>
//#include <limits>
//#include <list>
//#include <locale>
//#include <map>
//#include <memory>
//#include <new>
//#include <numeric>
//#include <ostream>
//#include <queue>
//#include <set>
//#include <sstream>
//#include <stack>
//#include <stdexcept>
//#include <streambuf>
#include <string>
//#include <typeinfo>
//#include <utility>
//#include <valarray>
#include <vector>
using namespace std;
//int main()
//{
//	int n, q;
//	cin >> n >> q;
//	int* a = (int*)malloc(n * sizeof(int));
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	int l, r;
//	while (q--)
//	{
//		cin >> l >> r;
//		--l;
//		--r;
//		int ret = 0;
//		int *b = (int*)calloc(32,sizeof(int));//�洢ÿһλ��λ��
//		if (b == nullptr)
//		{
//			cout<<"�ڴ����ʧ��"<<endl;
//			return 0;
//		}
//		for (i = l; i <= r; i++)
//		{
//			if ((a[i] >> (i - l)) & 1)
//			{
//				b[i - l] = 1;
//				break;
//			}
//		}
//		for (i = 0; i < 32; i++)
//		{
//			if (b[i])
//			{
//				ret += 1 << i;
//			}
//		}
//		free(b);
//		cout << ret << endl;
//	}
//	free(a);
//	return 0;
//}

//int main() {
//    int n, q;
//    cin >> n >> q;
//    vector<int> a(n);
//    for (int& x : a) cin >> x;
//
//    // Ԥ����ǰ׺��
//    vector<int> prefixOr(n);
//    prefixOr[0] = a[0];
//    for (int i = 1; i < n; ++i) {
//        prefixOr[i] = prefixOr[i - 1] | a[i];
//    }
//
//    while (q--) {
//        int l, r;
//        cin >> l >> r;
//        --l; --r; // ����Ϊ����0������
//        int result = prefixOr[r];
//        if (l > 0) {
//            result |= prefixOr[l - 1];
//        }
//        cout << result << endl;
//    }
//
//    return 0;
//}

////3400���ɭ��
//bool isSquare(int n)
//{
//	int left = 0;
//	int right = n;
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		if (mid * mid == n)
//		{
//			return true;
//		}
//		else if (mid * mid < n)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			right = mid - 1;
//		}
//	}
//	return false;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	int* a= new int[n];
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	//...
//	delete[] a;
//	return 0;
//}

//class Person {
//private:
//	int age;
//	string name;
//public:
//	void PrintPersonInfo();
//};
//void Person::PrintPersonInfo()
//{
//	cout << "name:" << name << " age:" << age << endl;
//}
//class Date {
//private:
//	int _year;
//	int _month;
//	int _day;
//public:
//	void Display() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//};
//int main()
//{
//
//	return 0;
//}

//class A
//{
//public:
//	A() { ++_scount; }
//	A(const A& t) { ++_scount; }
//	~A() { --_scount; }
//	static int GetACount() { return _scount; }
//private:
//	static int _scount;
//	int num;
//};
//int A::_scount = 0;
//void TestA()
//{
//	cout << A::GetACount() << endl;
//	A a1, a2;
//	A a3(a1);
//	cout << A::GetACount() << endl;
//}
//int main()
//{
//	//TestA();
//	A a1;
//	return 0;
//}

////ʵ����Ԫ��
//class Date
//{
//private:
//	int _year = 1900;
//	int _month = 1;
//	int _day = 1;
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	void Display() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	friend ostream& operator<<(ostream& cout, const Date& d);
//	friend istream& operator>>(istream& cin, Date& d);
//};
//ostream& operator<<(ostream& out, const Date& d)
//{
//	cout << d._year << "-" << d._month << "-" << d._day << endl;
//	return out;
//}
//istream& operator>>(istream& in,Date& d)
//{
//	cin >> d._year >> d._month >> d._day;
//	return in;
//}
//int main()
//{
//	Date d1;
//	cin >> d1;
//	cout << d1;
//	return 0;
//}

//#include <iostream>
//#include <cmath>
//
//class Date {
//private:
//    int year, month, day;
//
//    // ���ڼ���ĳ�������ĸ�������
//    int daysInMonth(int month, int year) const {
//        switch (month) {
//        case 4: case 6: case 9: case 11:
//            return 30;
//        case 2:
//            return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
//        default:
//            return 31;
//        }
//    }
//
//public:
//    // ���캯��
//    Date(int y, int m, int d) : year(y), month(m), day(d) {}
//
//    // ���رȽ������>
//    bool operator>(const Date& other) const {
//        if (year != other.year) return year > other.year;
//        if (month != other.month) return month > other.month;
//        return day > other.day;
//    }
//
//    // ���ظ�ֵ�����=
//    Date& operator=(const Date& other) {
//        if (this != &other) {
//            year = other.year;
//            month = other.month;
//            day = other.day;
//        }
//        return *this;
//    }
//
//    bool operator<(const Date& other) const {
//		if (year != other.year) return year < other.year;
//		if (month != other.month) return month < other.month;
//		return day < other.day;
//	}
//    // ���ؼ��������-��������������֮����������
//    int operator-(const Date& other) const {
//        // �򻯵�ʵ�֣��������������ϸ����
//        int days = 0;
//        Date tmp = *this;
//
//        while (tmp > other) {
//            --tmp.day;
//            ++days;
//            if (tmp.day == 0) {
//                if (tmp.month == 1) {
//                    tmp.year--;
//                    tmp.month = 12;
//                    tmp.day = 31;
//                }
//                else {
//                    tmp.month--;
//                    tmp.day = daysInMonth(tmp.month, tmp.year);
//                }
//            }
//        }
//        while (tmp < other)
//        {
//			++tmp.day;
//			--days;
//            if (tmp.day > daysInMonth(tmp.month, tmp.year)) {
//				tmp.day = 1;
//                if (tmp.month == 12) {
//					tmp.year++;
//					tmp.month = 1;
//				}
//                else {
//					tmp.month++;
//				}
//			}
//		}
//        return days;
//    }
//
//    // �������������ڵ�������
//    void decrement() {
//        if (day == 1) {
//            if (month == 1) {
//                year--;
//                month = 12;
//                day = 31;
//            }
//            else {
//                month--;
//                day = daysInMonth(month, year);
//            }
//        }
//        else {
//            day--;
//        }
//    }
//
//    // ��ӡ���ڣ����ڲ���
//    void print() const {
//        std::cout << year << "-" << month << "-" << day << std::endl;
//    }
//};
//
//int main() {
//    Date date1(2022, 4, 12);
//    Date date2(2022, 4, 22);
//
//    std::cout << "Date 1 is ";
//    date1.print();
//    std::cout << "Date 2 is ";
//    date2.print();
//
//    cout << "Days between Date 1 and Date 2: " << abs(date1 - date2)+1 << endl;
//
//    return 0;
//}

////��ģ��
//template<class T1>
//class A
//{
//public:
//	//...
//private:
//	//...
//	//T1 num;
//};

//template<class T>//����ģ��
//T add(const T& left, const T& right)
//{
//	return left + right;
//}
//int main()
//{
//	int i1 = 1, i2 = 2, i3;
//	i3 = add(i1, i2);//��ʽ����
//	double d1 = 1.3, d2 = 2.4, d3;
//	d3 = add<double>(i1, d2);//��ʾ����(ָ��T������)
//	cout << i3 << endl;
//	cout << d3 << endl;
//	return 0;
//}

//int main()
//{
//	string s1(10, 'a');//�޲ι���
//	string s2("hello");//���ι���
//	string s3(s2);//��������
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	return 0;
//}

//void test01()
//{
//	string s1;
//	string s2("hello");
//	string s3(s2);
//	string s4("hello", 2);
//	string s5(s2, 1, 2);
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//	cout << s5 << endl;
//
//}
//void test02()
//{
//	string s1("Hello");
//	s1 += ' ';
//	s1 += "world";
//	cout << s1 << endl;
//	//for (size_t i = 0; i < s1.size(); ++i)
//	//{
//	//	s1[i] += 1;
//	//	cout << s1[i] << " ";
//	//}
//	//������
//	string::iterator it = s1.begin();//auto it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	//��Χfor C++11
//	for (auto& e : s1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//int stringToInt(const string& tmp)
//{
//	int ret = 0;
//	//ʹ�õ�����ʵ��
//	auto it = tmp.begin();//string::iterator it = tmp.begin();
//	for (; it != tmp.end(); ++it)
//	{
//		ret = ret * 10 + (*it - '0');
//	}
//	return ret;
//}
//void test03()
//{
//	//���������
//	string s1("Hello");
//	string::reverse_iterator rit = s1.rbegin();//auto rit = s1.rbegin();
//	while (rit != s1.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//	string nums("124653");
//	cout << stringToInt(nums) << endl;
//}
//void test04()
//{
//	string s1("Hello world!");
//	cout << s1.size() << endl;//����
//	cout << s1.length() << endl;//���ȣ����ڵĽӿ�
//	//cout << s1.max_size() << endl;//û��ʲôʵ������
//	cout << s1.capacity() << endl;//����
//}
//void test05()
//{
//	//���capacity�ı仯
//	string s;
//	size_t sz = s.capacity();
//	cout << "current capacity:" << sz << endl;
//	for (int i = 0; i < 1000; i++)
//	{
//		s += 'a';//β��1����ĸa
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed:" << sz << endl;
//		}
//	}
//	s.reserve(1000);//Ԥ��1000���ַ��Ŀռ�
//	cout << "reserve capacity:" << s.capacity() << endl;
//	s.resize(100);//���������ַ�����С
//	cout << "resize size:" << s.size() << endl;
//}
//void test06()
//{
//	//�Ƽ�ʹ��+=�������ַ�����ƴ��
//	string s;
//	s.push_back('a');//β��
//	s.append("hello");//β��
//	s += ' ';
//	s += "world";//β��
//	cout << s << endl;
//}
//void test07()
//{
//	string s1("string.cpp");
//	string s2("string.h");
//	string s3("string.c");
//	string s4("string.txt");
//
//	size_t pos1 = s1.find('.');//����.��λ��
//	if (pos1 != string::npos)
//	{
//		cout << s1.substr(pos1) << endl;
//	}
//
//	size_t pos2 = s2.find('.');
//	if (pos2 != string::npos)
//	{
//		cout << s2.substr(pos2) << endl;
//	}
//}
//void test08()
//{
//	//https://www.bilibili.com/video/BV1Zv421C7E1/?spm_id_from=333.1007.tianma.1-3-3.click&vd_source=a820315ba9e9f48064a55b3b1b289346
//	//https://www.youtube.com/watch?v=l9eP9L-iJKc
//	//https://www.youtube.com/watch?v=3JZ_D3ELwOQ
//	//https://zh.m.wikipedia.org/wiki/%E7%BB%9F%E4%B8%80%E8%B5%84%E6%BA%90%E5%AE%9A%E4%BD%8D%E7%AC%A6
//	string url1("https://www.bilibili.com/video/BV1Zv421C7E1/?spm_id_from=333.1007.tianma.1-3-3.click&vd_source=a820315ba9e9f48064a55b3b1b289346");
//	string url2("https://www.youtube.com/watch?v=l9eP9L-iJKc");
//	string url3("https://www.youtube.com/watch?v=3JZ_D3ELwOQ");
//	string url4("https://zh.m.wikipedia.org/wiki/%E7%BB%9F%E4%B8%80%E8%B5%84%E6%BA%90%E5%AE%9A%E4%BD%8D%E7%AC%A6");
//	string& url = url4;
//	size_t pos1 = url.find(':');
//	if (pos1 != string::npos)
//	{
//		cout << "Э��:" << url.substr(0, pos1) << endl;
//	}
//	size_t pos2 = url.find('/', pos1 + 3);
//	if (pos2 != string::npos)
//	{
//		cout << "����:" << url.substr(pos1 + 3, pos2 - pos1 - 3) << endl;
//	}
//	cout<<"·��:"<<url.substr(pos2)<<endl;
//
//}
//int main()
//{
//	//test01();
//	//test02();
//	//test03();
//	//test04();
//	//test05();
//	//test06();
//	//test07();
//	test08();
//	return 0;
//}

//int main() {
//    string s;
//    getline(cin, s);
//    size_t pos = s.rfind(' ');
//    if (pos != string::npos)
//    {
//        int count = 0;
//        for (size_t i = pos + 1; i < s.size(); ++i)
//        {
//            count++;
//		}
//        cout<<count<<endl;
//    }
//    else {
//        cout<<s.size()<<endl;
//    }
//}

//int main()
//{
//	string num2;
//	string num1;
//	cin >> num1 >> num2;
//	if (num1.size() < num2.size())
//	{
//		swap(num1, num2);
//	}
//	//��λ���ٵ�ǰ�油0
//	num2.insert(0, num1.size() - num2.size(), '0');
//	//cout<<num1<<endl;
//	//cout<<num2<<endl;
//
//	string sum;
//	sum.resize(num1.size());
//	int carry = 0;
//	for (int i = num1.size() - 1; i >= 0; --i)
//	{
//		int ret = num1[i] - '0' + num2[i] - '0' + carry;
//		if (ret >= 10)
//		{
//			carry = 1;
//			sum[i] = ret - 10 + '0';
//		}
//		else
//		{
//			carry = 0;
//			sum[i] = ret + '0';
//		}
//	}
//	if (carry == 1)
//	{
//		sum.insert(0, 1, '1');
//	}
//	cout << sum << endl;
//	return 0;
//}

string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";

    int n1 = num1.size(), n2 = num2.size();
    string result(n1 + n2, '0'); // ��ʼ������ַ���

    // ��num1��num2�ĸ�λ����ʼ����λ���
    for (int i = n1 - 1; i >= 0; i--) {
        for (int j = n2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0'); // ���㵱ǰλ�ĳ˻�
            int sum = mul + (result[i + j + 1] - '0'); // ����֮ǰ�Ľ�λ
            result[i + j + 1] = sum % 10 + '0'; // ���µ�ǰλ�Ľ��
            result[i + j] += sum / 10; // ���½�λ
        }
    }

    // ȥ�����ǰ�˿��ܵĶ���0
    size_t startpos = result.find_first_not_of("0");
    if (string::npos != startpos) {
        return result.substr(startpos);
    }
    return "0";
}
int main()
{
	string num1 = "123";
	string num2 = "456";
	cout << multiply(num1, num2) << endl;
	return 0;
}