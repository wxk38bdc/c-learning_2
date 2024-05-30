/*
题目描述：
编写程序，实现一个具有插入和删除功能的单向链表类来存储数字。
首先，要求用户输入一组数字，若一个数字非0，则创建类对象(即节点)，节点去重后按照从小到大的顺序依次插入到链表当中;若该数字为0，则停止创建节点。
接着，当链表构建完成后，要求用户再输入一个链表中节点的序号(链表中节点的序号从1开始)，然后从链表中删除该序号所对应的节点。若输入的序号大于链表节点的个数，则不用删除。最终打印链表的奇数序号的数字。
输入：
第一行输入要构建链表的组数N(1<=N<=5) 接下来每两行构建一个链表: 第一行构建链表，输入一组整数，空格隔开，最后输0. 第二行输入要删除的节点的序号。
输出：
N行，每一行输出所构建的链表中奇数序号的数字，每个数字用空格隔开，行末不要有空格
样例输入：
3
5 2 8 6 11 3 9 0
2
1 2 3 4 4 6 0
9
45 17 21 33 31 0
5
样例输出：
2 6 9 1 3 6 17 31
注意：必须实现链表，禁止使用STL，否则计0分。
*/
#include<iostream>
#include<algorithm>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int _data = int()) :data(_data), next(nullptr) {}
};

class List // 带头单向不循环链表
{
private:
	Node* head; // 实节点
	Node* tail; // 虚节点
	size_t size;
public:
	List()
	{
		head = new Node();
		tail = head;
		size = 0;
	}
	void push_back(int val)
	{
		Node* newnode = new Node(val);
		tail->next = newnode;
		tail = newnode;
		size++;
	}
	void erase(int pos)
	{
		if (pos < size)
		{
			Node* cur = head->next; // 实节点开始
			Node* prev = head;
			for (int i = 0; i < pos; ++i) // 找到要删除的节点及其前驱节点
			{
				prev = cur;
				cur = cur->next;
			}
			prev->next = cur->next;
			if (cur == tail) tail = prev; // 修正：如果删除的是尾节点，更新尾节点指针
			delete cur;
			size--;
		}
	}
	void printOddNodes()
	{
		Node* cur = head->next; // 实节点开始
		int count = 1; // 第一个实节点索引为 1
		while (cur)
		{
			if (count % 2 != 0)
			{
				cout << cur->data;
				if (cur->next && cur->next->next) // 防止多余空格
					cout << " ";
			}
			count++;
			cur = cur->next;
		}
	}
};

int main()
{
	int N; // 组数
	cin >> N;
	while (N--)
	{
		int arr[100];
		int num;
		int count = 0;
		while (cin >> num)
		{
			if (num != 0) arr[count++] = num;
			else break;
		}
		int toDelete;
		cin >> toDelete;
		sort(arr, arr + count);
		int* end = unique(arr, arr + count);
		count = end - arr;
		List l;
		for (int j = 0; j < count; j++)
		{
			l.push_back(arr[j]);
		}
		l.erase(toDelete - 1); // 序号从1开始，转换为从0开始的索引
		l.printOddNodes();
		cout << endl;
	}
	return 0;
}
