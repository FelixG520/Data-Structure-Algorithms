#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Queen.h"


typedef char BTData;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTData data;
}BTNode;

void PrevOrder(BTNode* root);
void InOrder(BTNode* root);
void PostOrder(BTNode* root);
int TreeSize(BTNode* root, int* psize);
int TreeSize2(BTNode* root);
int TreeLeafSize(BTNode* root);
void LevelOrder(BTNode* root);
void DestoryTree(BTNode* root);
