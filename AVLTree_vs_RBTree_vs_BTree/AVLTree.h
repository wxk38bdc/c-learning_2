#pragma once
#include <iostream>
using namespace std;

//template <class T>
//struct AVLTreeNode
//{
//	T _data;
//	AVLTreeNode<T>* _left;
//	AVLTreeNode<T>* _right;
//	AVLTreeNode<T>* _parent;
//	int _bf;//balance factor,平衡因子
//
//	AVLTreeNode(const T& x = T())
//		:_data(x)
//		, _left(nullptr)
//		, _right(nullptr)
//		, _parent(nullptr)
//		, _bf(0)
//	{}
//};
//
//template <class T>
//class AVLTree
//{
//	typedef AVLTreeNode<T> Node;
//	typedef Node* pNode;
//private:
//	pNode _root;
//public:
//	AVLTree() :_root(nullptr) {}
//	~AVLTree()
//	{
//		Destroy();
//	}
//
//	void Destroy() {
//		_Destroy(_root);
//		_root = nullptr;
//	}
//
//	bool Insert(const T& data)
//	{
//		if (_root == nullptr)
//		{
//			_root = new Node(data);
//			return true;
//		}
//		pNode parent = nullptr;
//		pNode cur = _root;
//		while (cur)
//		{
//			if (cur->_data == data)
//				return false;
//			parent = cur;
//			if (cur->_data > data)
//				cur = cur->_left;
//			else
//				cur = cur->_right;
//		}
//		cur = new Node(data);
//		if (parent->_data > data)
//			parent->_left = cur;
//		else
//			parent->_right = cur;
//		cur->_parent = parent;
//
//		//更新平衡因子
//		while (parent)
//		{
//			if (parent->_left == cur)
//				parent->_bf--;
//			else
//				parent->_bf++;
//			if (parent->_bf == 0)
//				break;
//			if (parent->_bf == 1 || parent->_bf == -1)
//			{
//				cur = parent;
//				parent = parent->_parent;
//			}
//			else
//			{
//				if (parent->_bf == 2)
//				{
//					if (cur->_bf == 1)
//						RotateL(parent);
//					else
//						RotateRL(parent);
//				}
//				else
//				{
//					if (cur->_bf == -1)
//						RotateR(parent);
//					else
//						RotateLR(parent);
//				}
//				break;
//			}
//		}
//		return true;
//	}
//
//	pNode Find(const T& data)
//	{
//		pNode cur = _root;
//		while (cur)
//		{
//			if (cur->_data == data)
//				return cur;
//			else if (cur->_data > data)
//				cur = cur->_left;
//			else
//				cur = cur->_right;
//		}
//		return nullptr;
//	}
//
//	void InOrderPrint()const
//	{
//		_InOrder(_root);
//	}
//
//	bool Remove(const T& val)
//	{
//		Node* cur = Find(val);  // 查找目标节点
//		if (!cur)
//		{
//			// 未找到目标节点
//			return false;
//		}
//
//		Node* parent = cur->_parent;
//		Node* delnode = cur; // 记录当前需要删除的节点
//
//		// 根据删除节点的位置分为四种情况
//		// 1. 左右子树均为空
//		if (!cur->_left && !cur->_right)
//		{
//			if (cur == _root) // 根节点特殊处理
//			{
//				_root = nullptr;
//			}
//			else
//			{
//				UpdateBalanceFactorAfterRemove(parent, cur); // 更新平衡因子
//				if (parent->_left == cur)
//				{
//					parent->_left = nullptr;
//				}
//				else
//				{
//					parent->_right = nullptr;
//				}
//			}
//			delete cur;
//		}
//		// 2. 只有左子树
//		else if (cur->_left && !cur->_right)
//		{
//			if (cur == _root) // 根节点特殊处理
//			{
//				_root = cur->_left;
//				_root->_parent = nullptr;
//			}
//			else
//			{
//				Node* curLeft = cur->_left;
//				UpdateBalanceFactorAfterRemove(parent, cur); // 更新平衡因子
//				curLeft->_parent = parent;
//				if (parent->_left == cur)
//				{
//					parent->_left = curLeft;
//				}
//				else
//				{
//					parent->_right = curLeft;
//				}
//			}
//			delete cur;
//		}
//		// 3. 只有右子树
//		else if (!cur->_left && cur->_right)
//		{
//			if (cur == _root) // 根节点特殊处理
//			{
//				_root = cur->_right;
//				_root->_parent = nullptr;
//			}
//			else
//			{
//				Node* curRight = cur->_right;
//				UpdateBalanceFactorAfterRemove(parent, cur); // 更新平衡因子
//				curRight->_parent = parent;
//				if (parent->_left == cur)
//				{
//					parent->_left = curRight;
//				}
//				else
//				{
//					parent->_right = curRight;
//				}
//			}
//			delete cur;
//		}
//		// 4. 左右子树均不为空
//		else
//		{
//			Node* successor = cur->_right; // 查找右子树中最小节点
//			while (successor->_left)
//			{
//				successor = successor->_left;
//			}
//
//			cur->_data = successor->_data; // 将后继节点的数据赋值到当前节点
//			Node* successorParent = successor->_parent;
//
//			// 后继节点是否有右子树（后继节点不可能有左子树）
//			if (successor->_right)
//			{
//				successor->_right->_parent = successorParent;
//			}
//
//			if (successorParent->_left == successor)
//			{
//				successorParent->_left = successor->_right;
//			}
//			else
//			{
//				successorParent->_right = successor->_right;
//			}
//
//			// 释放后继节点
//			delnode = successor;
//			UpdateBalanceFactorAfterRemove(successorParent, delnode); // 更新平衡因子
//			delete delnode;
//		}
//
//		return true;
//	}
//
//protected:
//	// 辅助函数：更新平衡因子并调整树结构
//	void UpdateBalanceFactorAfterRemove(Node* parent, Node* cur)
//	{
//		while (parent)
//		{
//			if (parent->_left == cur)
//			{
//				parent->_bf++;
//			}
//			else
//			{
//				parent->_bf--;
//			}
//
//			if (parent->_bf == 1 || parent->_bf == -1)
//			{
//				// 树高度未变化，停止调整
//				break;
//			}
//			else if (parent->_bf == 0)
//			{
//				// 树高度变短，继续向上调整
//				cur = parent;
//				parent = parent->_parent;
//			}
//			else if (parent->_bf == 2)
//			{
//				// 左旋或右左双旋
//				if (parent->_right->_bf == 0)
//				{
//					Node* parentRight = parent->_right;
//					RotateL(parent);
//					parent->_bf = 1;
//					parentRight->_bf = -1;
//					break;
//				}
//				else if (parent->_right->_bf == 1)
//				{
//					RotateL(parent);
//				}
//				else
//				{
//					RotateRL(parent);
//				}
//				cur = parent->_parent;
//				parent = cur ? cur->_parent : nullptr;
//			}
//			else if (parent->_bf == -2)
//			{
//				// 右旋或左右双旋
//				if (parent->_left->_bf == 0)
//				{
//					Node* parentLeft = parent->_left;
//					RotateR(parent);
//					parent->_bf = -1;
//					parentLeft->_bf = 1;
//					break;
//				}
//				else if (parent->_left->_bf == -1)
//				{
//					RotateR(parent);
//				}
//				else
//				{
//					RotateLR(parent);
//				}
//				cur = parent->_parent;
//				parent = cur ? cur->_parent : nullptr;
//			}
//			else
//			{
//				// 理论上不应该到这里
//				cout << "Error: Invalid balance factor at key: " << parent->_data << endl;
//				exit(-1);
//			}
//		}
//	}
//
//protected:
//	void RotateL(pNode parent)
//	{
//		pNode subR = parent->_right;
//		pNode subRL = subR->_left;
//
//		parent->_right = subRL;
//		if (subRL)
//			subRL->_parent = parent;
//
//		subR->_left = parent;
//		pNode parentParent = parent->_parent;
//		parent->_parent = subR;
//
//		subR->_parent = parentParent;
//		if (parentParent == nullptr)
//			_root = subR;
//		else
//		{
//			if (parentParent->_left == parent)
//				parentParent->_left = subR;
//			else
//				parentParent->_right = subR;
//		}
//		parent->_bf = subR->_bf = 0;
//	}
//
//	void RotateR(pNode parent)
//	{
//		pNode subL = parent->_left;
//		pNode subLR = subL->_right;
//
//		parent->_left = subLR;
//		if (subLR)
//			subLR->_parent = parent;
//
//		subL->_right = parent;
//		pNode parentParent = parent->_parent;
//		parent->_parent = subL;
//
//		subL->_parent = parentParent;
//		if (parentParent == nullptr)
//			_root = subL;
//		else
//		{
//			if (parentParent->_left == parent)
//				parentParent->_left = subL;
//			else
//				parentParent->_right = subL;
//		}
//		parent->_bf = subL->_bf = 0;
//	}
//
//	void RotateRL(pNode parent)
//	{
//		pNode subR = parent->_right;
//		pNode subRL = subR->_left;
//
//		int bf = subRL->_bf;
//		RotateR(parent->_right);
//		RotateL(parent);
//		if (bf == 1)
//		{
//			parent->_bf = -1;
//			subR->_bf = 0;
//			subRL->_bf = 0;
//		}
//		else if (bf == -1)
//		{
//			parent->_bf = 0;
//			subR->_bf = 1;
//			subRL->_bf = 0;
//		}
//		else //bf == 0
//		{
//			parent->_bf = subR->_bf = subRL->_bf = 0;
//		}
//	}
//	void RotateLR(pNode parent)
//	{
//		pNode subL = parent->_left;
//		pNode subLR = subL->_right;
//
//		int bf = subLR->_bf;
//		RotateL(parent->_left);
//		RotateR(parent);
//		if (bf == 1)
//		{
//			parent->_bf = 0;
//			subL->_bf = -1;
//			subLR->_bf = 0;
//		}
//		else if (bf == -1)
//		{
//			parent->_bf = 1;
//			subL->_bf = 0;
//			subLR->_bf = 0;
//		}
//		else //bf == 0
//		{
//			parent->_bf = subL->_bf = subLR->_bf = 0;
//		}
//	}
//	void _Destroy(pNode node) {
//		if (node) {
//			_Destroy(node->_left);
//			_Destroy(node->_right);
//			delete node;
//		}
//	}
//
//	void _InOrder(pNode p)const//从根节点开始中序遍历
//	{
//		if (p)
//		{
//			_InOrder(p->_left);
//			cout << p->_data << " ";
//			_InOrder(p->_right);
//		}
//	}
//};
//
//void testAVLTree()
//{
//	AVLTree<int> t;
//	for (int i = 0; i < 30; i++)
//		t.Insert(i);
//
//	cout << "Before removal:" << endl;
//	t.InOrderPrint();
//	cout << endl;
//
//	cout << "Removing:" << endl;
//	for (int i = 26; i >= 0; i-=2)
//	{
//		cout << "Removing " << i << ":";
//		t.Remove(i);
//		t.InOrderPrint();
//		cout << endl;
//	}
//	
//	for (int i = 0; i < 30; i++)
//	{
//		if (t.Find(i))
//			cout << i << " found" << endl;
//		else
//			cout << i << " not found" << endl;
//	}
//}


template <typename T>
class AVLTree {
public:
    class node {
    public:
        T key;
        int height;
        node* left;
        node* right;
        node(T k) {
            height = 1;
            key = k;
            left = NULL;
            right = NULL;
        }
    };
    node* root = NULL;
    int n;
    void Insert(T x) {
        root = insertUtil(root, x);
    }
    void Remove(T x) {
        root = removeUtil(root, x);
    }
    node* Find(T x) {
        return searchUtil(root, x);
    }
    void InOrderPrint() {
        inorderUtil(root);
        cout << endl;
    }
private:
    int height(node* head) {
        if (head == NULL) return 0;
        return head->height;
    }
    node* rightRotation(node* head) {
        node* newhead = head->left;
        head->left = newhead->right;
        newhead->right = head;
        head->height = 1 + max(height(head->left), height(head->right));
        newhead->height = 1 + max(height(newhead->left), height(newhead->right));
        return newhead;
    }

    node* leftRotation(node* head) {
        node* newhead = head->right;
        head->right = newhead->left;
        newhead->left = head;
        head->height = 1 + max(height(head->left), height(head->right));
        newhead->height = 1 + max(height(newhead->left), height(newhead->right));
        return newhead;
    }

    void inorderUtil(node* head) {
        if (head == NULL) return;
        inorderUtil(head->left);
        cout << head->key << " ";
        inorderUtil(head->right);
    }

    node* insertUtil(node* head, T x) {
        if (head == NULL) {
            n += 1;
            node* temp = new node(x);
            return temp;
        }
        if (x < head->key) head->left = insertUtil(head->left, x);
        else if (x > head->key) head->right = insertUtil(head->right, x);
        head->height = 1 + max(height(head->left), height(head->right));
        int bal = height(head->left) - height(head->right);
        if (bal > 1) {
            if (x < head->left->key) {
                return rightRotation(head);
            }
            else {
                head->left = leftRotation(head->left);
                return rightRotation(head);
            }
        }
        else if (bal < -1) {
            if (x > head->right->key) {
                return leftRotation(head);
            }
            else {
                head->right = rightRotation(head->right);
                return leftRotation(head);
            }
        }
        return head;
    }
    node* removeUtil(node* head, T x) {
        if (head == NULL) return NULL;
        if (x < head->key) {
            head->left = removeUtil(head->left, x);
        }
        else if (x > head->key) {
            head->right = removeUtil(head->right, x);
        }
        else {
            node* r = head->right;
            if (head->right == NULL) {
                node* l = head->left;
                delete(head);
                head = l;
            }
            else if (head->left == NULL) {
                delete(head);
                head = r;
            }
            else {
                while (r->left != NULL) r = r->left;
                head->key = r->key;
                head->right = removeUtil(head->right, r->key);
            }
        }
        if (head == NULL) return head;
        head->height = 1 + max(height(head->left), height(head->right));
        int bal = height(head->left) - height(head->right);
        if (bal > 1) {
            if (height(head->left) >= height(head->right)) {
                return rightRotation(head);
            }
            else {
                head->left = leftRotation(head->left);
                return rightRotation(head);
            }
        }
        else if (bal < -1) {
            if (height(head->right) >= height(head->left)) {
                return leftRotation(head);
            }
            else {
                head->right = rightRotation(head->right);
                return leftRotation(head);
            }
        }
        return head;
    }
    node* searchUtil(node* head, T x) {
        if (head == NULL) return NULL;
        T k = head->key;
        if (k == x) return head;
        if (k > x) return searchUtil(head->left, x);
        if (k < x) return searchUtil(head->right, x);
    }
};

