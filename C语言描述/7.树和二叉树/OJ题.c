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
//	//每一层递归函数都有一个i，下一层放了值，++i，不会影响上一层函数中的i
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
	//开辟大小为树的结点个数的数组
	int* a = (int*)malloc(size * sizeof(int));
	int i = 0;
	_PreOrder(root, a, &i);
	*returnSize = size;
	return a;
}