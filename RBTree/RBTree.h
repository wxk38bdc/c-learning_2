#pragma once
#include<iostream>
#include<algorithm>
#include<cassert>
#include<vector>
using namespace std;

enum Color { RED, BLACK };

template<class T>
struct RBTreeNode
{
	T _data;
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	Color _color;

	RBTreeNode(const T& data)
		:_data(data)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _color(RED)
	{}
};

template<class T, class Ref, class Ptr>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T, Ref, Ptr> Self;

	Node* _node;
	Node* _root;

	RBTreeIterator(Node* node, Node* root)
		:_node(node)
		, _root(root)
	{}

	Self& operator++()
	{
		if (_node->_right)
		{
			// 右不为空，右子树最左节点就是中序第一个
			Node* leftMost = _node->_right;
			while (leftMost->_left)
			{
				leftMost = leftMost->_left;
			}

			_node = leftMost;
		}
		else
		{
			// 孩子是父亲左的那个祖先
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				cur = parent;
				parent = cur->_parent;
			}

			_node = parent;
		}

		return *this;
	}

	Self& operator--()
	{
		if (_node == nullptr) // end()
		{
			// --end()，特殊处理，走到中序最后一个节点，整棵树的最右节点
			Node* rightMost = _root;
			while (rightMost && rightMost->_right)
			{
				rightMost = rightMost->_right;
			}

			_node = rightMost;
		}
		else if (_node->_left)
		{
			// 左子树不为空，中序左子树最后一个
			Node* rightMost = _node->_left;
			while (rightMost->_right)
			{
				rightMost = rightMost->_right;
			}

			_node = rightMost;
		}
		else
		{
			// 孩子是父亲右的那个祖先
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_left)
			{
				cur = parent;
				parent = cur->_parent;
			}

			_node = parent;

		}

		return *this;
	}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	bool operator!= (const Self& s)
	{
		return _node != s._node;
	}

	bool operator== (const Self& s)
	{
		return _node == s._node;
	}
};

template<class K, class T,class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
private:
	Node* _root = nullptr;
public:
	typedef RBTreeIterator<T, T&, T*> Iterator;
	typedef RBTreeIterator<T, const T&, const T*> ConstIterator;

	Iterator Begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}

		return Iterator(cur, _root);
	}

	Iterator End()
	{
		return Iterator(nullptr, _root);
	}

	ConstIterator Begin() const
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}

		return ConstIterator(cur, _root);
	}

	ConstIterator End() const
	{
		return ConstIterator(nullptr, _root);
	}

	RBTree() = default;
	RBTree(const RBTree& t)
	{
		_root = _Copy(t._root);
	}

	RBTree& operator=(RBTree t)
	{
		swap(_root, t._root);//交换根节点
		return *this;
	}

	~RBTree()
	{
		_Destroy(_root);
		_root = nullptr;
	}

	pair<Iterator, bool> Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_color = BLACK;
			return make_pair(Iterator(_root, _root), true);
		}

		KeyOfT kot;//获取键值
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kot(cur->_data) == kot(data))
			{
				return make_pair(Iterator(cur, _root), false);
			}
			parent = cur;
			if (kot(cur->_data) < kot(data))
			{
				cur = cur->_left;
			}
			else //kot(cur->_data) > kot(data)
			{
				cur = cur->_right;
			}
		}

		cur = new Node(data);
		Node* newNode = cur;
		if (KeyOfT()(data) < KeyOfT()(parent->_data))
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		cur->_parent = parent;

		while (parent && parent->_color == RED)
		{
			Node* grandFather = parent->_parent;
			//   g
			//  / \
			// p   u 
			if (parent == grandFather->_left)
			{
				Node* uncle = grandFather->_right;
				if (uncle && uncle->_color == RED)
				{
					// 叔叔是红色，变色再继续向上调整
					parent->_color = BLACK;
					uncle->_color = BLACK;
					grandFather->_color = RED;

					cur = grandFather;
					parent = cur->_parent;
				}
				else
				{
					// 叔叔是黑色/叔叔为空，旋转+变色
					if (cur == parent->_left)
					{
						//    g
						//   / \
						//  p   u
						// /
						//c
						RotateR(grandFather);
						parent->_color = BLACK;
						grandFather->_color = RED;
					}
					else
					{
						//    g
						//   / \
						//  p   u
						//   \
						//    c
						RotateL(parent);
						RotateR(grandFather);
						cur->_color = BLACK;
						grandFather->_color = RED;
					}
					break;
				}
			}
			else
			{
				//   g
				//  / \
				// u   p
				Node* uncle = grandFather->_left;
				// 叔叔是红色，变色再继续向上调整
				if (uncle && uncle->_color == RED)
				{
					parent->_color = BLACK;
					uncle->_color = BLACK;
					grandFather->_color = RED;

					cur = grandFather;
					parent = cur->_parent;
				}
				else // 叔叔是黑色/叔叔为空，旋转+变色
				{
					//	  g
					//	 / \
					//	u   p
					//	     \
					//	      c
					if (cur == parent->_right)
					{
						RotateL(grandFather);
						parent->_color = BLACK;
						grandFather->_color = RED;
					}
					else
					{
						//	  g
						//	 / \
						//	u   p
						//	   /
						//	  c
						RotateR(parent);
						//	  g
						//	 / \
						//	u   c
						//	     \
						//	      p
						RotateL(grandFather);
						cur->_color = BLACK;
						grandFather->_color = RED;
					}
					break;
				}
			}
		}
		_root->_color = BLACK;
		return make_pair(Iterator(newNode, _root), true);
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	int Size()
	{
		return _Size(_root);
	}
	int Height()
	{
		return _Height(_root);
	}
private:
	Node* _Copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;
		Node* newRoot = new Node(root->_data);
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
		//cout << root->_kv.first << " " << root->_kv.second << endl;
		cout<<root->_data<<" ";
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
