/*
将单向链表按某值划分成左边小、中间相等、右边大的形式
【题目】给定一个单链表的头节点head,节点的值类型是整型，再给定一个整数pivot。实现一个调整链表的函数，将链表调整为左部分都是值小于pivotl的节点，中间部分都是值等于pivot的节点，右部分都是值大于pivotl的节点。
【进阶】在实现原问题功能的基础上增加如下的要求
【要求】调整后所有小于pivot的节点之间的相对顺序和调整前一样
【要求】调整后所有等于pivot的节点之间的相对顺序和调整前一样
【要求】调整后所有大于pivot的节点之间的相对顺序和调整前一样
【要求】时间复杂度请达到0()，额外空间复杂度请达到0(1)。
 */

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *next) : val(x), next(next){};
};

void printList(ListNode *head)
{
    ListNode *p = head;
    while (p != nullptr)
    {
        cout << p->val << " -> ";
        p = p->next;
    }
    cout << "nullptr" << endl;
}

class Solution
{
public:
    ListNode *listPartition(ListNode *head, int pivot)
    {
        ListNode *sH = nullptr;
        ListNode *sT = nullptr;
        ListNode *eH = nullptr;
        ListNode *eT = nullptr;
        ListNode *bH = nullptr;
        ListNode *bT = nullptr;
        ListNode *cur = head;

        while (cur != nullptr)
        {
            if (cur->val < pivot)
            {
                if (sH == nullptr)
                {
                    sH = cur;
                    sT = cur;
                }
                else
                {
                    sT->next = cur;
                    sT = cur;
                }
            }
            else if (cur->val == pivot)
            {
                if (eH == nullptr)
                {
                    eH = cur;
                    eT = cur;
                }
                else
                {
                    eT->next = cur;
                    eT = cur;
                }
            }
            else
            {
                if (bH == nullptr)
                {
                    bH = cur;
                    bT = cur;
                }
                else
                {
                    bT->next = cur;
                    bT = cur;
                }
            }
            cur = cur->next;
        }

        if (sT != nullptr)
        {
            sT->next = eH;
            eT = eT == nullptr ? sT : eT;
        }

        if (eT != nullptr)
        {
            eT->next = bH;
        }

        return sH != nullptr ? sH : 
               eH != nullptr ? eH : bH;
    }
};

int main()
{
    ListNode *head = new ListNode(0);
    int arr[] = {9, 0, 4, 5, 1, 3, 2, 7, 8, 5, 6};
    ListNode *p = head;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        p->next = new ListNode(arr[i]);
        p = p->next;
    }

    printList(head);

    Solution s;
    ListNode *res = s.listPartition(head, 5);
    printList(res);

    return 0;
}