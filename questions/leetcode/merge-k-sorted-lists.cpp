#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    // 比较函数，小根堆
    struct minCmp
    {
        bool operator()(ListNode *a, ListNode *b) const
        {
            return a->val > b->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // 把lists转化为小根堆
        priority_queue<ListNode *, vector<ListNode *>, minCmp> minHeap;
        for (auto list : lists)
        {
            if (list != nullptr)
            {
                minHeap.push(list);
            }
        }
        if (minHeap.empty() || minHeap.top() == nullptr)
        {
            return nullptr;
        }
        // 每次从小根堆中取出最小的元素, 将其下一个元素压入堆中(没有就不做)
        // 该元素作为cur的下一个元素, cur再后移, 循环
        ListNode *head = minHeap.top();
        ListNode *cur = head;
        minHeap.pop();
        if (cur->next != nullptr)
        {
            minHeap.push(cur->next);
        }
        while (!minHeap.empty())
        {
            cur->next = minHeap.top();
            cur = cur->next;
            minHeap.pop();
            if (cur->next != nullptr)
            {
                minHeap.push(cur->next);
            }
        }
        return head;
    }
};

int main()
{
    // [[1,4,5],[1,3,4],[2,6]]
    vector<ListNode *> lists;
    ListNode *head1 = new ListNode(1);
    ListNode *cur = head1;
    cur->next = new ListNode(4);
    cur = cur->next;
    cur->next = new ListNode(5);
    lists.push_back(head1);
    ListNode *head2 = new ListNode(1);
    cur = head2;
    cur->next = new ListNode(3);
    cur = cur->next;
    cur->next = new ListNode(4);
    lists.push_back(head2);
    ListNode *head3 = new ListNode(2);
    cur = head3;
    cur->next = new ListNode(6);
    lists.push_back(head3);
    // test
    Solution solution;
    ListNode *head = solution.mergeKLists(lists);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}