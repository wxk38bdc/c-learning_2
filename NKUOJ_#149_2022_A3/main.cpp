/*
题目描述

设计如下样式的链表类模板list，并对其进行简单使用。

template <class T> class list {
struct node {
// 存储具体数据项（的具体数据项）
T data;
// 每一表项的 data 数据类型均为类型形参 T 所指定
node* next;
// 通道指针域，将多个表项按“成”一个链表
};

node* head = nullptr, *tail; // 初始化 head 和 tail，均为空指针，即为链表的首尾指针

public:
list(); // 构造函数，创建一个“空表”
void Insert(T item); // 将链表项插入到原链表的链首
void Append(T item); // 将链表项附加到原链表的链尾
int count(); // 返回链表的项数
void ttoh(); // 把链表尾项移到链首
void display(); // 将链表数据项 data 显示在屏幕上
void SortList(); // 将链表数据项 data 排序后显示在屏幕上
};

八个成员函数的具体功能描述如下：
1. list(): 构造函数，将 head 与 tail 均置为 NULL，意味着创建出一个“空链表”；
2. void Insert(T item): 动态生成一块链表节点空间，将类型 T 类型的该数据项 item 放入该链表项的 data 域，而后将新生成的该链表项插入到原链表的链首（链表的“首”节点）；
3. void Append(T item): 动态生成一块链表节点空间，将类型 T 类型的该数据项 item 放入该链表项的 data 域，而后将新生成的该链表项附加到原链表的链尾（链表的“尾”节点）；
4. int count(): 统计并返回当前链表的节点项数目：空链表时返回0；链表非空时，意义等同于遍历链表，即从头到尾“数”出链表项的项数目；
5. void ttoh(): 将链表尾节点移到链首：空链表仅做一项无须动作；否则，要将原链首项“接到”尾项之后，而后将上述整链首指针 head 以及尾指针 tail；
6. void display(): 将链表的数据项依次显示在屏幕上；空链表输出“emptylist”；否则要按链表“行遍历”，从链表的头到尾将各项数据依次显示在屏幕上（每项显示之间用一个空格隔开）；
7. void SortList(): 将链表的数据项按 data 排序后显示在屏幕上：首先按链表数据项的值从小到大（按ASCII码排序）进行排序，排序结果输出。

要求
在主函数中，需要创建两个链表 link1 和 link2，将输入的所有链表元素依次通过 Append 加到 link1 中，并依次通过 Insert 加到 link2 中。必须用链表实现，否则0分。

输入
输入一共有三行，第一行为链表类型（只需考虑 int/char，均为小写字母）；第二行为链表长度；第三行为依次输入链表元素。

输出
输出有七行：
第一行为 link1.count() 的结果；
第二行为 link1.display() 的结果；
第三行为 link1 经过 ttoh() 后，link1.display() 的结果；
第四行为 link2.count() 的结果；
第五行为 link2.display() 的结果；
第六行为 link2 经过 ttoh() 后，link2.display() 的结果；
第七行为 link1 或者 link2 SortList() 的结果。

样例输入1
int
5
5 2 3 4 1

样例输出1
5
5 2 3 4 1
1 5 2 3 4
5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5

样例输入2
char
3
b a c

样例输出2
3
b a c
c b a
3
a c b
a b c
a b c

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

template<class T>
class list
{
	struct node {
		T data;
		node* next;
		node(T _data = T(), node* _next = nullptr) :data(_data), next(_next) {}
	}*head, * tail;
public:
	list()
	{
		head = tail = nullptr;
	}
	~list()
	{
		if (head != nullptr)
		{
			node* cur = head;
			while (cur != nullptr)
			{
				node* Next = cur->next;
				delete cur;
				cur = Next;
			}
		}
	}
	void Insert(T item)
	{
		node* newnode = new node(item);
		if (head == nullptr)
		{
			head = tail = newnode;
		}
		else {
			newnode->next = head;
			head = newnode;
		}
	}
	void Append(T item)
	{
		node* newnode = new node(item);
		if (head == nullptr)
		{
			head = tail = newnode;
		}
		else {
			tail->next = newnode;
			tail = newnode;
		}
	}
	int count()const
	{
		int size = 0;
		node* cur = head;
		while (cur != nullptr)
		{
			++size;
			cur = cur->next;
		}
		return size;
	}
	void htot()
	{
		if (count() > 1)
		{
			node* tmp = head;
			head = head->next;
			tmp->next = nullptr;
			tail->next = tmp;
			tail = tmp;
		}
	}
	void ttoh()
	{
		if (count() > 1)
		{
			node* tmp = tail;
			node* beforetail = head;
			while (beforetail->next->next != nullptr)
			{
				beforetail = beforetail->next;
			}
			beforetail->next = nullptr;
			tail = beforetail;
			tmp->next = head;
			head = tmp;
		}
	}
	void display()const
	{
		if (head == nullptr)cout << "emptylist" << endl;
		else {
			node* cur = head;
			while (cur != nullptr)
			{
				cout << cur->data << " ";
				cur = cur->next;
			}
			cout << endl;
		}
	}
	void SortList()const
	{
		vector<T>v;
		node* cur = head;
		while (cur != nullptr)
		{
			v.push_back(cur->data);
			cur = cur->next;
		}
		sort(v.begin(), v.end());
		for (auto& e : v)cout << e << " ";
		cout << endl;
	}
};
int main()
{
	string type;
	cin >> type;
	int len;
	cin >> len;

	if (type == "int")
	{
		list<int>link1;
		list<int>link2;
		int num;
		for (int i = 0; i < len; i++)
		{
			cin >> num;
			link1.Append(num);
			link2.Insert(num);
		}
		cout << link1.count() << endl;
		link1.display();
		link1.ttoh();
		link1.display();
		cout << link2.count() << endl;
		link2.display();
		link2.htot();
		link2.display();
		link2.SortList();
	}
	else
	{
		list<char>link1;
		list<char>link2;
		char ch;
		for (int i = 0; i < len; i++)
		{
			cin >> ch;
			link1.Append(ch);
			link2.Insert(ch);
		}
		cout << link1.count() << endl;
		link1.display();
		link1.ttoh();
		link1.display();
		cout << link2.count() << endl;
		link2.display();
		link2.htot();
		link2.display();
		link2.SortList();
	}
	return 0;
}
