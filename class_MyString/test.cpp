#define _CRT_SECURE_NO_WARNINGS 1

#include"mystring.h"//自定义的string类


void test_string1()
{
	MyString::string s1("hello");
	MyString::string s2(s1);
	MyString::string s3 = s1;
	MyString::string s4 = "world";
	//cout << s1 << endl;
	//cout << s2.c_str() << endl;
	//cout << s3.c_str() << endl;
	//cout << s4.c_str() << endl;
	//for (auto e : s4)//范围for-底层使用迭代器
	//{
	//	cout << e << " ";
	//}
	//s1.push_back(' ');
	//s1.append(s4);
	//s1 += "you";
	//s1 += 'k';
	//s1 += s4;
	//cout << s1 << endl;
	//s1 += " world";
	//cout << s1 << endl;
	//s1.erase(1);
	//cout << s1 << endl;
	cout << s1 << endl;
	cin >> s1;
	cout << s1 << endl;
}
void test_string2()
{
	MyString::string s1("hello");
	MyString::string s2("world");
	cout << (s1 < s2) << endl;
	cout << (s1 > s2) << endl;
	cout << (s1 == s2) << endl;
	cout << (s1 != s2) << endl;
	cout << (s1 <= s2) << endl;
	cout << (s1 >= s2) << endl;
}
void test_string3()
{
	MyString::string s1("hello");
	s1.insert(1, 'a');
	cout << s1 << endl;
	s1.insert(1, "world");
	cout << s1 << endl;
	s1.erase(1, 5);
	cout << s1 << endl;
	cout << (s1.find('l')) << endl;
	cout << (s1.find("lo")) << endl;
	s1.insert(0, "00");
	cout << s1 << endl;
}
void test_string4()
{
	MyString::string s;
	s += 'a';
	s += 'b';
	s += "cde";
	cout << s << endl;
	MyString::string s2("hello");
	s += s2;
	s += "world";
	cout << s << endl;
}
void test_string5()
{
	MyString::string s1, s2;
	s1 = "accccccc";
	s2 = s1;
	cout << s2.substr() << endl;
	cout << s2.substr(1) << endl;
	cout << s2.substr(1, 2) << endl;
}
int main()
{
	//test_string1();
	//test_string2();
	//test_string3();
	//test_string4();
	test_string5();
	return 0;
}