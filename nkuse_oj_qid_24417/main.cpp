/*
题目描述
在AVL树中，任何节点的两个子树的高度最多相差1；如果它们高度相差不止1，则需要重新平衡以恢复这种属性。
现在给定一个插入序列， 一个一个地将键值插入初始为空的AVL树中，输出得到的AVL树的层次顺序遍历序列，并判断它是否是一个完全二叉树。

输入格式：

第一行包含一个正整数N(<= 20)。然后在下一行给出N个不同的整数键。所有数字都用空格隔开。

输出格式：

第一行打印得到的AVL树的层次顺序遍历序列。所有数字都必须用空格隔开，并且行尾必须没有多余的空格。然后在下一行中，如果树为完全二叉树，则打印“Yes”;如果不是，则打印“No”。

样例输入1：

5
88 70 61 63 65

样例输出1：

70 63 88 61 65

Yes

样例输入2：
10
62 88 58 47 35 73 51 99 37 93

样例输出2：
62 47 88 35 58 73 99 37 51 93
No
*/

#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    int height;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr), height(1) {}
};

int getHeight(TreeNode* node) {
    return node ? node->height : 0;
}

int getBalance(TreeNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

void updateHeight(TreeNode* node) {
    if (node) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }
}

TreeNode* rightRotate(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

TreeNode* leftRotate(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

TreeNode* insert(TreeNode* node, int key) {
    if (!node) return new TreeNode(key);

    if (key < node->val) {
        node->left = insert(node->left, key);
    }
    else if (key > node->val) {
        node->right = insert(node->right, key);
    }
    else {
        return node;
    }

    updateHeight(node);

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->val) {
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && key > node->right->val) {
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && key > node->left->val) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->val) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

vector<int> levelOrder(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        result.push_back(node->val);

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }

    return result;
}

bool isCompleteBinaryTree(TreeNode* root) {
    if (!root) return true;

    queue<TreeNode*> q;
    q.push(root);
    bool mustHaveNoChild = false;

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node->left) {
            if (mustHaveNoChild) return false;
            q.push(node->left);
        }
        else {
            mustHaveNoChild = true;
        }

        if (node->right) {
            if (mustHaveNoChild) return false;
            q.push(node->right);
        }
        else {
            mustHaveNoChild = true;
        }
    }

    return true;
}

int main() {
    int N;
    cin >> N;
    vector<int> keys(N);
    for (int i = 0; i < N; i++) {
        cin >> keys[i];
    }

    TreeNode* root = nullptr;
    for (int key : keys) {
        root = insert(root, key);
    }

    vector<int> traversal = levelOrder(root);
    for (int i = 0; i < traversal.size(); i++) {
        if (i > 0) cout << " ";
        cout << traversal[i];
    }
    cout << endl;

    if (isCompleteBinaryTree(root)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}
