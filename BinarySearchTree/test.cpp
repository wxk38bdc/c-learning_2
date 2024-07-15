#include"BinarySearchTree.h"
int main()
{
	BSTree bst;
	bst.insert(5);
	bst.insert(3);
	bst.insert(7);
	bst.insert(2);
	bst.insert(4);
	bst.insert(6);
	bst.insert(8);
	bst.inOrder(bst.getRoot());
	cout << endl;
	bst.erase(3);
	bst.inOrder(bst.getRoot());
	cout << endl;
	bst.erase(5);
	bst.inOrder(bst.getRoot());
	cout << endl;
	bst.erase(7);
	bst.inOrder(bst.getRoot());
	cout << endl;
	bst.erase(6);
	bst.inOrder(bst.getRoot());
	cout << endl;
	bst.erase(8);
	bst.inOrder(bst.getRoot());
	cout << endl;
	bst.erase(2);
	bst.inOrder(bst.getRoot());
	cout << endl;
	bst.erase(4);
	bst.inOrder(bst.getRoot());
	return 0;
}