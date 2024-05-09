#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
using namespace std;

class String
{
protected:
	char *str;
	int size;
public:
	String()
	{
		str = NULL;
		size = 0;
	}
	String(const char* s)
	{
		size = strlen(s);
		str = new char[size + 1];
		strcpy(str, s);
	}
	String(const String& s)
	{
		size = s.size;
		str = new char[size + 1];
		strcpy(str, s.str);
	}
	~String()
	{
		delete[] str;
	}
	void print()
	{
		cout << str << endl;
	}
	int length()
	{
		return size;
	}
};

class EditableString : public String
{
public:
	EditableString(const char* s) : String(s) {}
	EditableString(const EditableString& s) : String(s) {}
	void insert(int pos, char ch)
	{
		pos--;
		char* temp = new char[size + 2];
		strncpy(temp, str, pos);
		temp[pos] = ch;
		strcpy(temp + pos + 1, str + pos);
		delete[] str;
		str = temp;
		size++;
	}
	void Delete(int pos)
	{
		pos--;
		char* temp = new char[size];
		strncpy(temp, str, pos);
		strcpy(temp + pos, str + pos + 1);
		delete[] str;
		str = temp;
		size--;
	}
	void replace(int pos, char ch)
	{
		pos--;
		str[pos] = ch;
	}
};
int main()
{
	EditableString s1("1234567890");
	while (1)
	{
		char choice;
		cin >> choice;
		if (choice == 'i')
		{
			int pos;
			char ch;
			cin >> pos >> ch;
			if (pos <= s1.length() + 1 && pos > 0)
			{
				s1.insert(pos, ch);
				s1.print();
			}
			else
			{
				//cout << "Invalid position" << endl;
				s1.print();
			}
		}
		else if (choice == 'd')
		{
			int pos;
			cin >> pos;
			if (pos <= s1.length() && pos > 0)
			{
				s1.Delete(pos);
				s1.print();
			}
			else
			{
				//cout << "Invalid position" << endl;
				s1.print();
			}
		}
		else if (choice == 'r')
		{
			int pos;
			char ch;
			cin >> pos >> ch;
			if (pos <= s1.length() && pos > 0)
			{
				s1.replace(pos, ch);
				s1.print();
			}
			else
			{
				//cout << "Invalid position" << endl;
				s1.print();
			}
		}
		else
			break;
	}
	return 0;
}