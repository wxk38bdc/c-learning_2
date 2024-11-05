/*
题目描述
给出一棵二叉树的先序遍历和中序遍历序列，计算该二叉树的高度。其中，二叉树的先序和中序遍历序列为不包含重复英文字母（区别大小写）的字符串。

Input Format

二叉树结点的总个数n<=50

然后输入先序和中序遍历序列，两个序列长度均为n。

Output Format
二叉树高度（整数） ，叶子结点高度为1

Example
Input
9
ABDGHCEIF
GDHBAEICF

Output
4
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct TreeNode {
	char val;
	TreeNode* left, * right;
	TreeNode(char _val) : val(_val), left(nullptr), right(nullptr) {}
};


TreeNode* _buildTree(string& preorder, string& inorder, int& prei, int inbegin, int inend)
{
	if (inbegin > inend)return nullptr;
	//前序确定根
	TreeNode* root = new TreeNode(preorder[prei]);
	//中序遍历查找根
	int i = inbegin;
	while (inorder[i] != root->val)++i;
	++prei;
	//划分区间，分别构建左右子树
	root->left = _buildTree(preorder, inorder, prei, inbegin, i - 1);
	root->right = _buildTree(preorder, inorder, prei, i + 1, inend);
	return root;

}
int height(TreeNode* root)
{
	if (!root)return 0;
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	return max(leftHeight, rightHeight) + 1;
}

int main() {
	int n = 0, i = 0;//i作为可更改的索引，n为节点数
	string preorder;
	string inorder;
	cin >> n >> preorder >> inorder;
	TreeNode* root = _buildTree(preorder, inorder, i, 0, inorder.size() - 1);
	cout << height(root);
	return 0;
}