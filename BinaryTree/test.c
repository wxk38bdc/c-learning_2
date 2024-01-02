#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

typedef char BTNDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
	BTNDataType _data;
}BTNode;

int TreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + TreeSize(root->_left) + TreeSize(root->_right);
}
int main()
{

	return 0;
}
