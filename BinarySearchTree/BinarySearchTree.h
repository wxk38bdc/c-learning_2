#pragma once
#include<iostream>
using namespace std;

namespace Key {
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

		PNode getRoot() const { return root; }
		void inOrder(PNode p) const
		{
			if (p)
			{
				inOrder(p->left);
				cout << p->data << " ";
				inOrder(p->right);
			}
		}
		PNode find(const T& data) const
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
		bool insert(const T& data)//若插入成功返回true，否则返回false
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
		bool erase(const T& data)
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
	};
}

namespace KeyValue {
	template<class K,class V>
	struct BSTNode
	{
		K key;
		V value;
		BSTNode<K,V>* left;
		BSTNode<K,V>* right;
		BSTNode(const K& key = K(), const V& value = V()) : key(key), value(value), left(nullptr), right(nullptr) {}
	};
	template<class K,class V>
	class BSTree
	{
		typedef BSTNode<K, V> Node;
		typedef BSTNode<K, V>* PNode;
	private:
		PNode root;
	public:
		BSTree() :root(nullptr) {}
		~BSTree() {}

		PNode getRoot() const { return root; }
		void inOrder(PNode p) const
		{
			if (p)
			{
				inOrder(p->left);
				cout << p->key << "->"<<p->value<<" ";
				inOrder(p->right);
			}
		}
		PNode find(const K& key) const
		{
			PNode p = root;
			while (p)
			{
				if (key == p->key)
					return p;
				else if (key < p->key)
					p = p->left;
				else
					p = p->right;
			}
			return nullptr;
		}
		bool insert(const K& key, const V& value)//若插入成功返回true，否则返回false
		{
			PNode p = root;
			PNode pp = nullptr;
			while (p)
			{
				pp = p;
				if (key == p->key)
					return false;
				else if (key < p->key)
					p = p->left;
				else
					p = p->right;
			}
			PNode newNode = new Node(key, value);
			if (pp == nullptr)
				root = newNode;
			else if (key < pp->key)
				pp->left = newNode;
			else
				pp->right = newNode;
			return true;
		}
		bool erase(const K& key)
		{
			PNode p = root;
			PNode pp = nullptr;
			//找到要删除的节点
			while (p && p->key != key)
			{
				pp = p;
				if (key < p->key)
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
				p->key = minP->key;
				p->value = minP->value;
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

	};
}