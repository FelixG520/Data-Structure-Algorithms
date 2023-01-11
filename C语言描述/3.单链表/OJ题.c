#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	struct ListNode* pre = NULL, * cur = head;
//	while (cur)
//	{
//		if (cur->val == val)
//		{
//			//ͷɾ
//			if (cur == head)
//			{
//				head = cur->next;
//				free(cur);
//				cur = head;
//			}
//			else
//			{
//				//ɾ��
//				pre->next = cur->next;
//				free(cur);
//				cur = pre->next;
//			}
//		}
//		else
//		{
//			//����������
//			pre = cur;
//			cur = cur->next;
//		}
//	}
//	return head;
//}

//******************************************************************************************************

 //Definition for singly-linked list.
struct ListNode 
{
    int val;
    struct ListNode *next;
};
 
//struct ListNode* reverseList(struct ListNode* head) 
//{
//    if (head == NULL)
//    {
//        return NULL;
//    }
//    struct ListNode* n1, *n2, *n3;
//    n1 = NULL;
//    n2 = head;
//    n3 = head->next;
//    while (n2)
//    {
//        //��ת
//        n2->next = n1;
//        //����
//        n1 = n2;
//        n2 = n3;
//        if (n3)
//        {
//            n3 = n3->next;
//        }
//    }
//    return n1;
//}

//struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* cur = head;
//    struct ListNode* newhead = NULL;
//    while (cur == NULL)//���Դ���û�нڵ�����
//    {
//        struct ListNode* next = cur->next;
//        //ͷ��
//        cur->next = newhead;
//        newhead = cur;
//        //����
//        cur = next;
//    }
//    return newhead;
//}

//***************************************************************************
//����ָ��
//struct ListNode* middleNode(struct ListNode* head)
//{
//    struct ListNode* slow, * fast;
//    slow = fast = head;
//    while (fast != NULL && fast->next != NULL)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return slow;
//}

//*****************************************************************
//struct ListNode* FindKthToTail(struct ListNode* pListHead,int k)
//{
//    struct ListNode* fast, * slow;
//    slow = fast = pListHead;
//    while (k--)
//    {
//        //k����������
//        if (fast == NULL)
//        {
//            return NULL;
//        }
//        fast = fast->next;
//    }
//    while (fast)
//    {
//        slow = slow->next;
//        fast = fast->next;
//    }
//    return slow;
//}

struct ListNode* mergeTwoLists(struct ListNode* l1,struct ListNode* l2)
{
    //�������һ������Ϊ�գ��ͷ�����һ��
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    struct ListNode* head = NULL, * tail = NULL;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            if (head == NULL)
            {
                head = tail = l1;
            }
            else
            {
                tail->next = l1;
                tail = tail->next;
            }
            l1 = l1->next;
        }
        else
        {
            if (head == NULL)
            {
                head = tail = l2;
            }
            else
            {
                tail->next = l2;
                tail = tail->next;
            }
            l2 = l2->next;
        }
    }
    if (l1)
    {
        tail->next = l1;
    }
    if (l2)
    {
        tail->next = l2;
    }
    return head;
}