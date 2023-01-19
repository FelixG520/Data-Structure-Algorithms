
#include "BinaryTree.h"



//前序遍历
void PrevOrder(BTNode* root) 
{
	if (root == NULL) 
	{
		printf("NULL ");
		return;
	}

	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

//中序遍历
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}

//后序遍历
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);

}

//结点个数（遍历思维）--递归
int TreeSize(BTNode* root,int* psize)
{
	if (root == NULL)
		return;
	else
		++(*psize);

	TreeSize(root->left, psize);
	TreeSize(root->right, psize);

}

//分治算法（后序思维）--递归
int TreeSize2(BTNode* root)
{
	return root == NULL ? 0 : TreeSize2(root->left) + TreeSize2(root->right) + 1;
}

//叶子结点的个数--递归
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

//层序遍历 -- 上一层出的时候，带下一层结点进
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		//根先进队，再出队
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->data);

		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}
	printf("\n");
	QueueDestroy(&q);
}

//后序思路（先销毁跟就会找不到左右子树）
void DestoryTree(BTNode* root)
{
	if (root == NULL)
		return;
	DestoryTree(&root->left);
	DestoryTree(root->right);
	free(root);
}


int main()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	if (A == NULL)
		exit(-1);
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;


	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	if (B == NULL)
		exit(-1);
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	if (C == NULL)
		exit(-1);
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	if (D == NULL)
		exit(-1);
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	if (E == NULL)
		exit(-1);
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	PrevOrder(A);
	printf("\n");

	InOrder(A);
	printf("\n");

	PostOrder(A);
	printf("\n");

	int Asize = 0;
	TreeSize(A, &Asize);
	printf("TreeSize:%d\n", Asize);


	int Bsize = 0;
	TreeSize(B, &Bsize);
	printf("TreeSize:%d\n", Bsize);

	printf("TreeSize:%d\n", TreeSize2(A));
	printf("TreeSize:%d\n", TreeSize2(B));

	LevelOrder(A);

	return 0;
}