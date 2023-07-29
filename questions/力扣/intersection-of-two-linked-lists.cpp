/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
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
};