#pragma once
#include <iostream>
using namespace std;

template<class T>
struct BSTNode
{
	T data;
	BSTNode<T>* left;
	BSTNode<T>* right;
	BSTNode(const T& data = T()) : data(data), left(nullptr), right(nullptr) {}
};
template<class T>
class BSTree
{
private:
	BSTNode<T>* root;
public:
	typedef BSTNode<T> Node;
	typedef BSTNode<T>* PNode;
	BSTree() :root(nullptr) {}
	~BSTree() {}

	void InOrder() const
	{
		_InOrder(root);
	}
	PNode Find(const T& data) const
	{
		PNode p = root;
		while (p)
		{
			if (data == p->data)
				return p;
			else if (data < p->data)
				p = p->left;
			else
				p = p->right;
		}
		return nullptr;
	}
	bool Insert(const T& data)//若插入成功返回true，否则返回false
	{
		PNode p = root;
		PNode pp = nullptr;
		while (p)
		{
			pp = p;
			if (data == p->data)
				return false;
			else if (data < p->data)
				p = p->left;
			else
				p = p->right;
		}
		PNode newNode = new Node(data);
		if (pp == nullptr)
			root = newNode;
		else if (data < pp->data)
			pp->left = newNode;
		else
			pp->right = newNode;
		return true;
	}

	bool Remove(const T& data)
	{
		PNode p = root;
		PNode pp = nullptr;
		//找到要删除的节点
		while (p && p->data != data)
		{
			pp = p;
			if (data < p->data)
				p = p->left;
			else
				p = p->right;
		}
		if (p == nullptr)
			return false;
		//要删除的节点有两个子节点
		if (p->left && p->right)
		{
			PNode minP = p->right;
			PNode minPP = p;
			while (minP->left)
			{
				minPP = minP;
				minP = minP->left;
			}
			p->data = minP->data;
			p = minP;
			pp = minPP;
		}
		//要删除的节点是叶子节点或者仅有一个子节点
		PNode child = nullptr;
		if (p->left)
			child = p->left;
		else if (p->right)
			child = p->right;
		if (pp == nullptr)
			root = child;
		else if (pp->left == p)
			pp->left = child;
		else
			pp->right = child;
		delete p;
		return true;
	}

protected:
	void _InOrder(PNode p) const
	{
		if (p)
		{
			_InOrder(p->left);
			cout << p->data << " ";
			_InOrder(p->right);
		}
	}
};

void testBSTree()
{
	BSTree<int> bst;
	for(int i=3;i<22;i++)
		bst.Insert(i);
	bst.InOrder();

	cout << endl;
	for(int i=7;i<15;i++)
		bst.Remove(i);
	bst.InOrder();
	cout << endl;

	for (int i = 0; i < 20; i++)
	{
		if (bst.Find(i))
			cout << i << " found" << endl;
		else
			cout << i << " not found" << endl;
	}
}
