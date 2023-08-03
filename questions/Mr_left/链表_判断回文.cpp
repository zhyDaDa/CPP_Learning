/* 剑指 Offer II 027. 回文链表 */
#include <stack>
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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

void printString(string str)
{
    cout << "================="
         << str
         << "=================" << endl;
}

class Solution
{
public:
    // 暴力解
    bool isPalindrome1(ListNode *head)
    {
        ListNode *p = head;
        stack<int> myStack;
        while (p != nullptr)
        {
            myStack.push(p->val);
            p = p->next;
        }

        while (head != nullptr)
        {
            if (head->val != myStack.top())
                return false;
            myStack.pop();
            head = head->next;
        }

        return true;
    }

    // 暴力解折半优化
    bool isPalindrome2(ListNode *head)
    {
        if (head->next == nullptr)
            return true;
        stack<int> myStack;
        ListNode *fp = head->next;
        ListNode *sp = head;
        while (fp->next != nullptr && fp->next->next != nullptr)
        {
            sp = sp->next;
            fp = fp->next->next;
        }

        while (sp->next != nullptr)
        {
            sp = sp->next;
            myStack.push(sp->val);
        }

        while (!myStack.empty())
        {
            if (head->val != myStack.top())
                return false;
            myStack.pop();
            head = head->next;
        }

        return true;
    }

    // 不使用额外空间
    bool isPalindrome3(ListNode *head)
    {
        if (head->next == nullptr)
            return true;
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        while (p2->next != nullptr && p2->next->next != nullptr)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        p2 = p1->next;
        // printString("找到中点");
        // printList(p2);
        ListNode *p3;
        p1->next = nullptr;
        while (p2 != nullptr)
        {
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        p2 = head;
        p3 = p1;
        bool ans = true;
        while (p2 != nullptr)
        {
            if (p2->val != p1->val)
            {
                ans = false;
                break;
            }
            p2 = p2->next;
            p1 = p1->next;
        }
        p1 = p3->next;
        p3->next = nullptr;

        while (p1 != nullptr)
        {
            p2 = p1->next;
            p1->next = p3;
            p3 = p1;
            p1 = p2;
        }

        return ans;
    }

    // 同上, 不善后
    bool isPalindrome4(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return true;
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        while (p2->next != nullptr && p2->next->next != nullptr)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        p2 = p1->next;
        // printString("找到中点");
        // printList(p2);
        ListNode *p3;
        p1->next = nullptr;
        while (p2 != nullptr)
        {
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        while (head != nullptr)
        {
            if (head->val != p1->val)
                return false;
            head = head->next;
            p1 = p1->next;
        }
        return true;
    }

    // 利用迭代
    bool isPalindrome5(ListNode *head)
    {
        frontPointer = head;
        return reverselyCheck(head);
    }

private:
    ListNode *frontPointer;
    bool reverselyCheck(ListNode *cur)
    {
        if (cur != nullptr)
        {
            if (!reverselyCheck(cur->next))
                return false;
            if (cur->val != frontPointer->val)
                return false;
            frontPointer = frontPointer->next;
        }
        return true;
    }
};

int main()
{
    ListNode *head1 = new ListNode;
    head1->val = 0;
    head1->next = nullptr;
    ListNode *p1 = head1;
    int arr1[8] = {1, 2, 3, 4, 4, 3, 2, 1};
    for (int i = 0; i < 8; i++)
    {
        ListNode *temp = new ListNode(arr1[i], nullptr);
        p1->next = temp;
        p1 = p1->next;
    }
    ListNode *head2 = new ListNode;
    head2->val = 0;
    head2->next = nullptr;
    ListNode *p2 = head2;
    int arr2[9] = {1, 2, 3, 4, 4, 3, 2, 1, 0};
    for (int i = 0; i < 9; i++)
    {
        ListNode *temp = new ListNode(arr2[i], nullptr);
        p2->next = temp;
        p2 = p2->next;
    }

    Solution solution;
    bool Ans1 = solution.isPalindrome5(head1);
    bool Ans2 = solution.isPalindrome5(head2);
    cout << Ans1 << endl;
    cout << Ans2 << endl;
}