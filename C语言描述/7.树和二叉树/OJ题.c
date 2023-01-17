#include "BinaryTree.h"

int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

//void _PreOrder(BTNode* root, int* a, int i)
//{
//	if (root == NULL)
//		return;
//	a[i] = root->data;
//	++i;
//	//ÿһ��ݹ麯������һ��i����һ�����ֵ��++i������Ӱ����һ�㺯���е�i
//	_PreOrder(root->left, a, i);
//	_PreOrder(root->right, a, i);
//}


void _PreOrder(BTNode* root, int* a, int* pi)
{
	if (root == NULL)
		return;
	a[*pi] = root->data;
	++(*pi);
	_PreOrder(root->left, a, pi);
	_PreOrder(root->right, a, pi);
}


int* preorderTraversal(BTNode* root, int* returnSize)
{
	int size = TreeSize(root);
	//���ٴ�СΪ���Ľ�����������
	int* a = (int*)malloc(size * sizeof(int));
	int i = 0;
	_PreOrder(root, a, &i);
	*returnSize = size;
	return a;
}