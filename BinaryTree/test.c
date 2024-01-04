#define _CRT_SECURE_NO_WARNINGS 1

#include"queue.h"

BTNode* CreateNode(BTNDataType x)//�����ڵ�
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->_data = x;
	node->_left = NULL;
	node->_right = NULL;
	return node;
}
int TreeSize(BTNode* root)//��������Ľڵ����
{
	if (root == NULL)
		return 0;
	return 1 + TreeSize(root->_left) + TreeSize(root->_right);
}
int TreeLeafSize(BTNode* root)//���������Ҷ�ӽڵ����
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL&&root->_right == NULL)
		return 1;
	return TreeLeafSize(root->_left) + TreeLeafSize(root->_right);
}

int TreeDepth(BTNode* root)//������������
{
	if (root == NULL)
		return 0;
	int leftDepth = TreeDepth(root->_left);
	int rightDepth = TreeDepth(root->_right);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}
void PreOrder(BTNode* root)//�������
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
void InOrder(BTNode* root)//�������
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
void PostOrder(BTNode* root)//�������
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
//�ж�һ�����Ƿ�Ϊ��ȫ������
int BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL&&root->_right == NULL)
		return 1;
	if (root->_left&&root->_right)
		return BinaryTreeComplete(root->_left) && BinaryTreeComplete(root->_right);
	return 0;
}
//�ö����ж�һ�����Ƿ�Ϊ��ȫ����������������������սڵ�ֹͣ��ӣ�������滹�зǿսڵ㣬˵��������ȫ������
int BinaryTreeComplete2(BTNode* root)
{
	if (root == NULL)
		return 0;
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
		if (front)
			return 0;
	}
	return 1;
}
//���η���������ֽ�Ϊ�����⣬������Ľ��������ԭ������ͬ
int BinaryTreeLevelKSize(BTNode* root, int k)//���k��ڵ�ĸ���
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
BTNode* BinaryTreeFind(BTNode* root, BTNDataType x)//�ڶ������в���ֵΪx�Ľڵ�
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	BTNode* ret = BinaryTreeFind(root->_left, x);
	if (ret)
		return ret;
	return BinaryTreeFind(root->_right, x);
}
//����
//�������ָ�룬��ΪҪ�޸�ָ���ָ��
void BinaryTreeDestory(BTNode** root)
{
	assert(root);
	if (*root == NULL)
		return;
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free(*root);
	*root = NULL;
}
//��һ��ָ���destroy
void BinaryTreeDestory2(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeDestory2(root->_left);
	BinaryTreeDestory2(root->_right);
	free(root);
	root = NULL;
}
//����������ö���ʵ��
void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL)
		return;
	queue q;
	queueInit(&q);
	queuePush(&q, root);
	while (!queueEmpty(&q))
	{
		BTNode* front = queueFront(&q);
		printf("%c ", front->_data);
		queuePop(&q);
		if (front->_left)
			queuePush(&q, front->_left);
		if (front->_right)
			queuePush(&q, front->_right);
	}
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
	printf("TreeSize=%d\n", TreeSize(A));
	PreOrder(A);
	printf("\n");
	InOrder(A);
	printf("\n");
	PostOrder(A);
	printf("\n");
	printf("TreeLeafSize=%d\n", TreeLeafSize(A));
	printf("TreeDepth=%d\n", TreeDepth(A));
	//���ҽڵ�
	BTNode* ret = BinaryTreeFind(A, 'E');
	if (ret)
		printf("�ҵ�E��\n");
	else
		printf("û�ҵ�E\n");
	//���k��ڵ�ĸ���
	printf("��3��ڵ�ĸ���=%d\n", BinaryTreeLevelKSize(A, 3));
	//�ж�һ�����Ƿ�Ϊ��ȫ������
	if (BinaryTreeComplete2(A))
		printf("����ȫ������\n");
	else
		printf("������ȫ������\n");
	//�������
	BinaryTreeLevelOrder(A);
	return 0;
}
