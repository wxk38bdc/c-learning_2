/*
题目描述
给出一棵完全二叉树的先序遍历，输出其后序遍历。结点均为不重复的单个英文字母，区分大小写。结点总数小于52。

Input Format

输入先序字符串

Output Format
后序遍历字符串

Example
Input
ABDGHCEIF

Output
GHDCBIFEA



样例输入输出
样例1
输入:
ABDGHCEIF
输出:
GHDCBIFEA
样例2
输入:
a
输出:
a

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
int calculateLeftSubtreeNodes(int m) {
	if (m == 1)return 0;
	int height = static_cast<int>(log2(m));
	int maxNodesAtHeight = (1 << height) - 1; // Nodes in a full binary tree of given height

	// Calculate nodes in the left subtree based on whether it's a full or partial level.
	int lastLevelNodes = m - maxNodesAtHeight;
	int maxNodesInLeftSubtree = (1 << (height - 1)) - 1; // Full left subtree nodes

	if (lastLevelNodes > (1 << (height - 1))) {
		return maxNodesInLeftSubtree + (1 << (height - 1));
	}
	else {
		return maxNodesInLeftSubtree + lastLevelNodes;
	}
}
// 构造完全二叉树
TreeNode* constructTree(const string& preorder, int start, int end) {
	if (start > end) return nullptr;

	TreeNode* root = new TreeNode(preorder[start]);
	int totalNodes = end - start + 1;

	if (totalNodes == 1) return root; // 只有一个节点

	int leftSize = calculateLeftSubtreeNodes(totalNodes);

	root->left = constructTree(preorder, start + 1, start + leftSize);
	root->right = constructTree(preorder, start + leftSize + 1, end);

	return root;
}

// 后序遍历
void postorderTraversal(TreeNode* root) {
	if (!root) return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout << root->val;
}

int main() {
	string preorder;
	cin >> preorder;

	TreeNode* root = constructTree(preorder, 0, preorder.size() - 1);
	postorderTraversal(root);
	cout << endl;
	return 0;
}
