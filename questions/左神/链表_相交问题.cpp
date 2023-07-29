/*
【题目】给定两个可能有环也可能无环的单链表，头节点head1和head2。请实现一个函数，如果两个链表相交，请返回相交的第一个节点。如果不相交，返回null
【要求】如果两个链表长度之和为N,时间复杂度请达到0(N),额外空间复杂度请达到0(1)。
 */
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

class Solution
{
public:
    ListNode *getLoopNode(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return nullptr;
        ListNode *p1 = head->next;
        ListNode *p2 = head->next->next;

        while (p1 != p2)
        {
            if (p2->next == nullptr || p2->next->next == nullptr)
                return nullptr;
            p1 = p1->next;
            p2 = p2->next->next;
            // cout << "移动之后, p1: " << p1->val << " p2: " << p2->val << endl;
        }

        p1 = head;
        while (p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        return p1;
    }

    ListNode *noLoop(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
            return nullptr;

        ListNode *pA = headA;
        ListNode *pB = headB;
        int count = 0;

        while (pA->next != nullptr)
        {
            pA = pA->next;
            count++;
        }

        while (pB->next != nullptr)
        {
            pB = pB->next;
            count--;
        }

        if (pA != pB)
            return nullptr;

        pA = count > 0 ? headA : headB;
        pB = pA == headA ? headB : headA;

        count = abs(count);
        while (count != 0)
        {
            pA = pA->next;
            count--;
        }

        while (pA != pB)
        {
            pA = pA->next;
            pB = pB->next;
        }

        return pA;
    }

    ListNode *bothLoop(ListNode *headA, ListNode *loopA, ListNode *headB, ListNode *loopB)
    {
        if(loopA!=loopB){
            ListNode *p = loopA->next;
            while (p!=loopA)
            {
                if(p == loopB)
                    return loopB;
            }
            return nullptr;
        }else{
            // 将loop点当做收尾点, 复用noLoop
            ListNode *pA = headA;
            ListNode *pB = headB;
            int count = 0;

            while (pA != loopA)
            {
                pA = pA->next;
                count++;
            }

            while (pB != loopA)
            {
                pB = pB->next;
                count--;
            }

            pA = count > 0 ? headA : headB;
            pB = pA == headA ? headB : headA;

            count = abs(count);
            while (count != 0)
            {
                pA = pA->next;
                count--;
            }

            while (pA != pB)
            {
                pA = pA->next;
                pB = pB->next;
            }

            return pA;
        }
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        ListNode *loopA = getLoopNode(headA);
        ListNode *loopB = getLoopNode(headB);
        ListNode *ansNode = nullptr;

        if(loopA==nullptr&&loopB==nullptr){
            ansNode = noLoop(headA, headB);
        }else if(loopA!=nullptr&&loopB!=nullptr){
            ansNode = bothLoop(headA, loopA, headB, loopB);
        }

        return ansNode;
    }
};

int main()
{
    ListNode *headA = new ListNode(0);
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ListNode *p = headA;
    for (int i = 0; i < 10; i++)
    {
        ListNode *temp = new ListNode(arr[i]);
        temp->next = nullptr;
        p->next = temp;
        p = p->next;
    }

    printList(headA);

    ListNode *headB = new ListNode(0);
    p = headB;
    for (int i = 0; i < 10; i++)
    {
        ListNode *temp = new ListNode(arr[i]);
        temp->next = nullptr;
        p->next = temp;
        p = p->next;
    }

    printList(headB);

    // pA在7号节点, pB在3号节点
    ListNode *pA1 = headA;
    ListNode *pA2 = headA;
    ListNode *pA3 = headA;
    ListNode *pB1 = headB;
    ListNode *pB2 = headB;
    for (int i = 0; i < 2; i++)
    {
        pA1 = pA1->next;
    }
    for (int i = 0; i < 7; i++)
    {
        pA2 = pA2->next;
    }
    for (int i = 0; i < 9; i++)
    {
        pA3 = pA3->next;
    }
    for (int i = 0; i < 3; i++)
    {
        pB1 = pB1->next;
    }
    for (int i = 0; i < 8; i++)
    {
        pB2 = pB2->next;
    }
    pA1->next = pB1;
    pB2->next = pA2;
    pA3->next = pB2;

    // printList(headA);
    // printList(headB);

    Solution s;
    // ListNode *res = s.noLoop(headA, headB);
    // if (res == nullptr)
    //     cout << "No intersection node" << endl;
    // else
    //     cout << "Intersection Node: " << res->val << endl;
    ListNode *IntersectionNode = s.getIntersectionNode(headA,headB);
    if (IntersectionNode == nullptr)
        cout << "No IntersectionNode" << endl;
    else
        cout << "IntersectionNode: " << IntersectionNode->val << endl;

    return 0;
}