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
//#include <string>
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
