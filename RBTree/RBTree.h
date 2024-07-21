#pragma once
#include<iostream>
#include<algorithm>
#include<cassert>
#include<vector>
using namespace std;

enum Color { RED, BLACK };

template<class K, class V>
struct RBTreeNode
{
	pair<K, V> _kv;
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	Color _color;

	RBTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _color(RED)
	{}
};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
private:
	Node* _root;
public:
	RBTree() = default;
	RBTree(const RBTree<K, V>& t)
	{
		_root = _Copy(t._root);
	}

	RBTree<K, V>& operator=(RBTree<K, V> t)
	{
		swap(_root, t._root);//交换根节点
		return *this;
	}

	~RBTree()
	{
		_Destroy(_root);
		_root = nullptr;
	}
private:
	Node* _Copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;
		Node* newRoot = new Node(root->_kv);
		newRoot->_color = root->_color;
		newRoot->_left = _Copy(root->_left);
		newRoot->_right = _Copy(root->_right);
		if (newRoot->_left)
			newRoot->_left->_parent = newRoot;
		if (newRoot->_right)
			newRoot->_right->_parent = newRoot;
		return newRoot;
	}

	void _Destroy(Node* root)
	{
		if (root == nullptr)
			return;
		_Destroy(root->_left);
		_Destroy(root->_right);
		delete root;
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << " " << root->_kv.second << endl;
		_InOrder(root->_right);
	}
	int _Size(Node* root)
	{
		if (root == nullptr)
			return 0;
		return 1 + _Size(root->_left) + _Size(root->_right);
	}
	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		return 1 + max(_Height(root->_left), _Height(root->_right));
	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		Node* parentParent = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;

		if (parentParent == nullptr)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parent == parentParent->_left)
			{
				parentParent->_left = subR;
			}
			else
			{
				parentParent->_right = subR;
			}

			subR->_parent = parentParent;
		}
	}
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* parentParent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (parentParent == nullptr)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (parent == parentParent->_left)
			{
				parentParent->_left = subL;
			}
			else
			{
				parentParent->_right = subL;
			}

			subL->_parent = parentParent;
		}
	}
};
