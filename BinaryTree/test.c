#define _CRT_SECURE_NO_WARNINGS 1

#include"queue.h"

//创建节点
BTNode* CreateNode(BTNDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->_data = x;
	node->_left = NULL;
	node->_right = NULL;
	return node;
}
//销毁
void BinaryTreeDestory(BTNode** root)//传入二级指针，因为要修改指针的指向
{
	assert(root);
	if (*root == NULL)
		return;
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free(*root);
	*root = NULL;
}
void BinaryTreeDestory2(BTNode* root)//传一级指针的destroy
{
	if (root == NULL)
		return;
	BinaryTreeDestory2(root->_left);
	BinaryTreeDestory2(root->_right);
	free(root);
	root = NULL;
}
//求二叉树的节点个数
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : 1 + TreeSize(root->_left) + TreeSize(root->_right);
}
//求二叉树的叶子节点个数
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL&&root->_right == NULL)
		return 1;
	return TreeLeafSize(root->_left) + TreeLeafSize(root->_right);
}

int TreeDepth(BTNode* root)//求二叉树的深度
{
	if (root == NULL)
		return 0;
	int leftDepth = TreeDepth(root->_left);
	int rightDepth = TreeDepth(root->_right);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}
void PreOrder(BTNode* root)//先序遍历
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->_data);
	PreOrder(root->_left);
	PreOrder(root->_right);
}
void InOrder(BTNode* root)//中序遍历
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->_left);
	printf("%c ", root->_data);
	InOrder(root->_right);
}
void PostOrder(BTNode* root)//后序遍历
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->_left);
	PostOrder(root->_right);
	printf("%c ", root->_data);
}
//判断一棵树是否为完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
		return false;
	if (root->_left == NULL&&root->_right == NULL)
		return true;
	if (root->_left&&root->_right)
		return BinaryTreeComplete(root->_left) && BinaryTreeComplete(root->_right);
	return false;
}
//用队列判断一棵树是否为完全二叉树，层序遍历，遇到空节点停止入队，如果后面还有非空节点，说明不是完全二叉树
bool BinaryTreeComplete2(BTNode* root)
{
	if (root == NULL)
		return false;
	queue q;
	queueInit(&q);
	queuePush(&q, root);
	while (!queueEmpty(&q))
	{
		BTNode* front = queueFront(&q);
		queuePop(&q);
		if (front == NULL)
			break;
		queuePush(&q, front->_left);
		queuePush(&q, front->_right);
	}
	while (!queueEmpty(&q))
	{
		BTNode* front = queueFront(&q);
		queuePop(&q);
		if (front)//非空节点,不是完全二叉树
		{
			queueDestroy(&q);
			return false;
		}
			
	}
	queueDestroy(&q);
	return true;
}
//分治法：将问题分解为子问题，子问题的解决方案与原问题相同
int BinaryTreeLevelKSize(BTNode* root, int k)//求第k层节点的个数
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
BTNode* BinaryTreeFind(BTNode* root, BTNDataType x)//在二叉树中查找值为x的节点
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	//在左子树中找
	BTNode* ret1 = BinaryTreeFind(root->_left, x);
	if (ret1)
		return ret1;
	//在右子树中找
	BTNode* ret2 = BinaryTreeFind(root->_right, x);
	if (ret2)
		return ret2;
	//左右子树都没找到
	return NULL;
}
bool IsXExist(BTNode*root,BTNDataType x)//判断x是否在二叉树中
{
	if (root == NULL)
		return false;
	if (root->_data == x)
		return true;
	return IsXExist(root->_left, x) || IsXExist(root->_right, x);
}

//层序遍历，用队列实现
void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL)
		return;
	queue q;
	queueInit(&q);
	queuePush(&q, root);
	while (!queueEmpty(&q))//队列不为空
	{
		BTNode* front = queueFront(&q);
		printf("%c ", front->_data);
		queuePop(&q);
		if (front->_left)
			queuePush(&q, front->_left);
		if (front->_right)
			queuePush(&q, front->_right);
	}
	queueDestroy(&q);
}
int main()
{
	BTNode* A = CreateNode('A');
	BTNode* B = CreateNode('B');
	BTNode* C = CreateNode('C');
	BTNode* D = CreateNode('D');
	BTNode* E = CreateNode('E');
	BTNode* F = CreateNode('F');
	BTNode* G = CreateNode('G');
	A->_left = B;
	A->_right = C;
	B->_left = D;
	B->_right = E;
	C->_right = F;
	F->_left = G;
	printf("先序遍历：");
	PreOrder(A);
	printf("\n");
	printf("TreeSize=%d\n", TreeSize(A));
	printf("Level4Size=%d\n", LevelKSize(A,4));
	//找‘E’
	printf("'E'的地址：%p\n", BinaryTreeFind(A, 'G'));

	//PreOrder(A);
	//printf("\n");
	//InOrder(A);
	//printf("\n");
	//PostOrder(A);
	//printf("\n");
	//printf("TreeLeafSize=%d\n", TreeLeafSize(A));
	//printf("TreeDepth=%d\n", TreeDepth(A));
	////查找节点
	//BTNode* ret = BinaryTreeFind(A, 'E');
	//if (ret)
	//	printf("找到E了\n");
	//else
	//	printf("没找到E\n");
	////求第k层节点的个数
	//printf("第3层节点的个数=%d\n", BinaryTreeLevelKSize(A, 3));
	////判断一棵树是否为完全二叉树
	//if (BinaryTreeComplete2(A))
	//	printf("是完全二叉树\n");
	//else
	//	printf("不是完全二叉树\n");
	////层序遍历
	//BinaryTreeLevelOrder(A);
	return 0;
}
