#include "BinaryTree.h"


//二叉树的前序遍历
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


//二叉树的最大深度
int maxDepth(BTNode* root)
{
	if (root == NULL)
		return 0;
	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);
	return  leftDepth > rightDepth ? leftDepth + 1:rightDepth +1;
}

//判断平衡二叉树
bool isBalanced(BTNode* root)
{
	if (root == NULL)
		return true;
	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);
	return  abs(leftDepth - rightDepth) < 2 
		&& isBalanced(root->left)
		&& isBalanced(root->right);//都满足才满足，一个不满足就不满足
}

//给先序遍历重构二叉树
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	char data;
}BTNode;

BTNode* CreateTree(char* a, int* pi)
{
	if (a[*pi] == '#')
	{
		++(*pi);
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL)
	{
		printf("Malloc fail!\n");
		exit(-1);
	}
	root->data = a[*pi];
	++(*pi);
	//递归
	root->left = CreateTree(a, pi);
	root->right= CreateTree(a, pi);
	return root;
}

//中序遍历
void InOrder(BTNode* root)
{
	if (root == NULL)
		return;
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}


int main()
{
	char str[100];
	scanf("%s", str);
	int i = 0;
	BTData* root = CreateTree(str, &i);
	return 0;
}