#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	struct ListNode* pre = NULL, * cur = head;
//	while (cur)
//	{
//		if (cur->val == val)
//		{
//			//头删
//			if (cur == head)
//			{
//				head = cur->next;
//				free(cur);
//				cur = head;
//			}
//			else
//			{
//				//删除
//				pre->next = cur->next;
//				free(cur);
//				cur = pre->next;
//			}
//		}
//		else
//		{
//			//迭代往后走
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
//        //翻转
//        n2->next = n1;
//        //迭代
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
//    while (cur == NULL)//可以处理没有节点的情况
//    {
//        struct ListNode* next = cur->next;
//        //头插
//        cur->next = newhead;
//        newhead = cur;
//        //迭代
//        cur = next;
//    }
//    return newhead;
//}

//***************************************************************************
//快慢指针
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
//        //k大于链表长度
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
    //如果其中一个链表为空，就返回另一个
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



//**************************************************************************

#include <cstddef>
#include <cstdlib>
 struct ListNode {
     int val;
     struct ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Partition
{
public:
    ListNode* partition(ListNode* pHead, int x)
    {
        struct ListNode* lessHead, * lessTail, * greaterHead, * greaterTail;
        //开一个哨兵位的头节点，方便尾插
        lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
        lessTail->next = NULL;
        greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
        greaterTail->next = NULL;
        struct ListNode* cur = pHead;
        while (cur)
        {
            if (cur->val < x)
            {
                lessTail->next = cur;
                lessTail = cur;
            }
            else
            {
                greaterTail->next = cur;
                greaterTail = cur;
            }
            cur = cur->next;
        }
        lessTail->next = greaterHead->next;
        greaterTail->next = NULL;//一定要考虑成环的情况，要把原链表的尾结点置空

        struct ListNode* newHead = lessHead->next;
        free(lessHead);
        free(greaterHead);
        return newHead;
    }
};


//******************************************************************************
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    struct ListNode* tailA = headA;
    struct ListNode* tailB = headB;
    int lenA = 1;
    while (tailA->next)
    {
        ++lenA;
        tailA = tailA->next;
    }
    int lenB = 1;

    while (tailB->next)
    {
        lenB++;
        tailB->next;
    }
    if (tailA != tailB)
    {
        return NULL;
    }
    //距离差
    int gap = abs(lenA - lenB);
    //长的先走差距步，再同时走找交点
    int lenA = 1;
    struct ListNode* longList = headA;//假设A长
    struct ListNode* shortList = headB;
    if (lenA < lenB)//如果A短，就把A给shortList
    {
        shortList = headA;
        longList = headB;
    }
    //长的先走差距步
    while (gap--)
    {
        longList = longList->next;
    }

    while (longList!=shortList)
    {
        longList = longList->next;
        shortList = shortList->next;
    }
    return longList;
}