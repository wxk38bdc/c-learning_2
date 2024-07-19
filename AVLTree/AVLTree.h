#pragma once
#include <iostream>
using namespace std;

template <class T>
struct AVLTreeNode
{
	T _data;
	AVLTreeNode<T>* _left;
	AVLTreeNode<T>* _right;
	AVLTreeNode<T>* _parent;
	int _bf;//balance factor

	AVLTreeNode(const T& x=T())
		:_data(x)
		, _left(NULL)
		, _right(NULL)
		, _parent(NULL)
		, _bf(0)
	{}
};

template <class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
	typedef Node* pNode;
private:
	pNode _root;
public:
	AVLTree() :_root(nullptr) {}
	~AVLTree()
	{
		Destroy();
	}
	void RotateL(pNode parent)
	{
		pNode subR = parent->_right;
		pNode subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		pNode parentParent = parent->_parent;
		parent->_parent = subR;

		subR->_parent = parentParent;
		if (parentParent == nullptr)
			_root = subR;
		else
		{
			if (parentParent->_left == parent)
				parentParent->_left = subR;
			else
				parentParent->_right = subR;
		}
		parent->_bf = subR->_bf = 0;
	}

	void RotateR(pNode parent)
	{
		pNode subL = parent->_left;
		pNode subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		pNode parentParent = parent->_parent;
		parent->_parent = subL;

		subL->_parent = parentParent;
		if (parentParent == nullptr)
			_root = subL;
		else
		{
			if (parentParent->_left == parent)
				parentParent->_left = subL;
			else
				parentParent->_right = subL;
		}
		parent->_bf = subL->_bf = 0;
	}

	void RotateRL(pNode parent)
	{
		pNode subR = parent->_right;
		pNode subRL = subR->_left;

		int bf = subRL->_bf;
		RotateR(parent->_right);
		RotateL(parent);
		if (bf == 1)
		{
			parent->_bf = -1;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else //bf == 0
		{
			parent->_bf = subR->_bf = subRL->_bf = 0;
		}
	}
	void RotateLR(pNode parent)
	{
		pNode subL = parent->_left;
		pNode subLR = subL->_right;

		int bf = subLR->_bf;
		RotateL(parent->_left);
		RotateR(parent);
		if (bf == 1)
		{
			parent->_bf = 0;
			subL->_bf = -1;
			subLR->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 1;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else //bf == 0
		{
			parent->_bf = subL->_bf = subLR->_bf = 0;
		}
	}
	void _Destroy(pNode node) {
		if (node) {
			_Destroy(node->_left);
			_Destroy(node->_right);
			delete node;
		}
	}

	void Destroy() {
		_Destroy(_root);
		_root = nullptr;
	}

	bool Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			return true;
		}
		pNode parent = nullptr;
		pNode cur = _root;
		while (cur)
		{
			if (cur->_data == data)
				return false;
			parent = cur;
			if (cur->_data > data)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		cur = new Node(data);
		if (parent->_data > data)
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;

		//更新平衡因子
		while (parent)
		{
			if (parent->_left == cur)
				parent->_bf--;
			else
				parent->_bf++;
			if (parent->_bf == 0)
				break;
			if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else
			{
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)
						RotateL(parent);
					else
						RotateRL(parent);
				}
				else
				{
					if (cur->_bf == -1)
						RotateR(parent);
					else
						RotateLR(parent);
				}
				break;
			}
		}
		return true;
	}
	pNode Find(const T& data)
	{
		pNode cur = _root;
		while (cur)
		{
			if (cur->_data == data)
				return cur;
			else if (cur->_data > data)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		return nullptr;
	}

	void _InOrder(pNode p)const//从根节点开始中序遍历
	{
		if (p)
		{
			_InOrder(p->_left);
			cout << p->_data << " ";
			_InOrder(p->_right);
		}
	}

	void InOrder()const
	{
		_InOrder(_root);
	}
};

void testAVLTree01()
{
	AVLTree<int> t;
	t.Insert(5);
	t.Insert(3);
	t.Insert(8);
	t.Insert(1);
	t.Insert(4);
	t.Insert(6);
	t.Insert(9);
	t.Insert(2);
	t.Insert(7);
	t.Insert(10);
	t.InOrder();
	cout << endl;
}

void testAVLTreeInsert()
{
	AVLTree<int> t;
	t.Insert(10);
	t.Insert(20);
	t.Insert(30); // Should cause a left rotation
	t.InOrder();
	cout << endl;

	t.Insert(40);
	t.Insert(50); // Should cause a left rotation
	t.InOrder();
	cout << endl;

	t.Insert(25); // Should cause a right-left rotation
	t.InOrder();
	cout << endl;
}

void testAVLTreeFind()
{
	AVLTree<int> t;
	t.Insert(10);
	t.Insert(20);
	t.Insert(30);

	cout << "Finding 20: " << (t.Find(20) != nullptr ? "Found" : "Not Found") << endl;
	cout << "Finding 40: " << (t.Find(40) != nullptr ? "Found" : "Not Found") << endl;
}

void testAVLTreeBalance()
{
	AVLTree<int> t;
	for (int i = 1; i <= 15; ++i)
	{
		t.Insert(i);
	}
	t.InOrder();
	cout << endl;
}

void testAVLTreeDestroy()
{
	AVLTree<int> t;
	t.Insert(1);
	t.Insert(2);
	t.Insert(3);
	t.Insert(4);
	t.Insert(5);
	t.Destroy();
	t.InOrder();
	cout << endl;
}

void testAVLTreeComplex()
{
	AVLTree<int> t;
	t.Insert(50);
	t.Insert(25);
	t.Insert(75);
	t.Insert(10);
	t.Insert(30);
	t.Insert(60);
	t.Insert(80);
	t.Insert(5);
	t.Insert(15);
	t.Insert(27);
	t.Insert(65);

	cout << "Initial tree (InOrder): ";
	t.InOrder();
	cout << endl;

	t.Insert(13); // Insert to cause a rebalance
	cout << "After inserting 13 (InOrder): ";
	t.InOrder();
	cout << endl;

	t.Insert(55); // Insert to cause another rebalance
	cout << "After inserting 55 (InOrder): ";
	t.InOrder();
	cout << endl;
}