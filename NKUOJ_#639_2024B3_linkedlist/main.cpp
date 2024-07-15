#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cctype>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int _val = 0) :val(_val), next(nullptr) {}
};
class LinkedList
{
public:
	ListNode* head;
	ListNode* tail;
public:
	LinkedList() :head(nullptr), tail(nullptr) {}
	LinkedList(const LinkedList& l) :head(nullptr), tail(nullptr)
	{
		if (l.head == nullptr)
		{
			return;
		}
		else
		{
			ListNode* cur = l.head;
			while (cur != nullptr)
			{
				push_back(cur->val);
				cur = cur->next;
			}

		}
	}
	void push_back(int value)
	{
		if (head == nullptr)
		{
			head = tail = new ListNode(value);
		}
		else
		{
			tail->next = new ListNode(value);
			tail = tail->next;
		}
	}
	void pop_back()
	{
		if (head == nullptr)return;
		else if (head->next == nullptr)
		{
			delete head;
			head = tail = nullptr;
		}
		else if (head->next == tail)
		{
			delete tail;
			head->next = nullptr;
			tail = head;
		}
		else {
			ListNode* beforetail = head->next;
			while (beforetail->next != tail)
			{
				beforetail = beforetail->next;
			}
			delete tail;
			beforetail->next = nullptr;
			tail = beforetail;
		}
	}
	void clear()
	{
		while (!empty())pop_back();
	}
	bool empty()
	{
		return head == nullptr;
	}
	void print()
	{
		if (head == nullptr)
		{
			cout << "NULL" << endl;
		}
		else
		{
			ListNode* cur = head;
			while (cur != nullptr)
			{
				cout << cur->val << " ";
				cur = cur->next;
			}
			cout << endl;
		}
	}
	void reverse()
	{
		vector<int>v;
		if (head == nullptr || head->next == nullptr)return;
		ListNode* cur = head;
		while (cur != nullptr)
		{
			v.push_back(cur->val);
			cur = cur->next;
		}
		clear();
		for (int i = v.size() - 1; i >= 0; i--)
		{
			push_back(v[i]);
		}
	}
	friend LinkedList operator+(LinkedList& A, LinkedList& B)
	{
		LinkedList C;
		ListNode* headA = A.head;
		ListNode* headB = B.head;
		if (headA == nullptr && headB == nullptr)return C;
		if (headA == nullptr)return B;
		if (headB == nullptr)return A;

		//正式开始计算

		ListNode* curA = headA;
		ListNode* curB = headB;
		int acount = 0, bcount = 0;
		while (curA != nullptr)
		{
			curA = curA->next;
			acount++;
		}
		while (curB != nullptr)
		{
			curB = curB->next;
			bcount++;
		}
		if (acount > bcount)
		{
			int num = acount - bcount;
			while (num--)B.push_back(1);
		}
		else if (acount < bcount)
		{
			int num = bcount - acount;
			while (num--)A.push_back(1);
		}
		int prime = 0;
		curA = headA, curB = headB;
		while (1)
		{
			int dataA=curA==nullptr? 1: curA->val;
			int dataB=curB==nullptr? 1: curB->val;
			int data = dataA * dataB + prime;
			if (data < 10)
			{
				prime = 0;
				C.push_back(data % 10);
			}
			else {
				prime = data / 10;
				C.push_back(data % 10);
			}
			curA = curA->next;
			curB = curB->next;
			if (curA == nullptr || curB == nullptr)break;
		}
		if (prime != 0)C.push_back(prime);
		return C;
	}
};

int main()
{
	LinkedList A;
	LinkedList B;
	string line1, line2;
	getline(cin, line1);
	getline(cin, line2);
	for (auto& e : line1)
	{
		if (isdigit(e))A.push_back((int)(e - '0'));
	}
	for (auto& e : line2)
	{
		if (isdigit(e))B.push_back((int)(e - '0'));
	}
	if (A.empty() && B.empty())
	{
		cout << "NULL" << endl;
		return 0;
	}
	A.reverse();
	B.reverse();
	if (A.empty())
	{
		B.print();
		return 0;
	}
	if (B.empty())
	{
		A.print();
		return 0;
	}
	LinkedList C = A + B;

	C.print();

	return 0;
}