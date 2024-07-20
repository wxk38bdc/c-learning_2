#pragma once
#include<iostream>
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
		, _left(NULL)
		, _right(NULL)
		, _parent(NULL)
		, _color(RED)
	{}
};
