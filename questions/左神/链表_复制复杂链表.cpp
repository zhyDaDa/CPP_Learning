#include <iostream>
#include <map>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node()
    {
        val = 0;
        next = NULL;
        random = NULL;
    }

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void printListWithRandom(Node *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        if (head->random != nullptr)
            cout << head->random->val;
        else
            cout << "nullptr";
        cout << endl;
        head = head->next;
    }
    cout << endl;
}

class Solution
{
public:
    // 用MAP
    Node *copyRandomList1(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        map<Node *, Node> m;
        Node *cur = head;
        while (cur != nullptr)
        {
            Node *temp = new Node(cur->val);
            m.insert({cur, *temp});
            cur = cur->next;
        }

        cur = head;
        while (cur != nullptr)
        {
            m.at(cur).next = cur->next == nullptr ? nullptr : &m.at(cur->next);
            m.at(cur).random = cur->random == nullptr ? nullptr : &m.at(cur->random);
            cur = cur->next;
        }
        return &m.at(head);
    }

    // 在源节点后面创建替身节点
    Node *copyRandomList2(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        Node *p1 = head;
        Node *p2;
        Node *p3;
        // 创建替身, 且其生命周期在函数结束后
        while (p1 != nullptr)
        {
            p2 = new Node(p1->val);
            p3 = p1->next;
            p1->next = p2;
            p2->next = p3;
            p1 = p3;
        }

        // 处理替身的random
        p1 = head;
        while (p1 != nullptr)
        {
            p2 = p1->next;
            p3 = p2->next;
            p2->random = p1->random == nullptr ? nullptr : p1->random->next;
            p1 = p3;
        }
        // 拆分
        p1 = head;
        Node *newHead = head->next;
        while (p1 != nullptr)
        {
            p2 = p1->next;
            p3 = p2->next;
            p1->next = p3;
            p2->next = p3 == nullptr ? nullptr : p3->next;
            p1 = p3;
        }
        return newHead;
    }
};

int main()
{
    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    n1.random = nullptr;
    n2.random = &n1;
    n3.random = &n5;
    n4.random = &n3;
    n5.random = &n1;

    printListWithRandom(&n1);

    Solution s;
    Node *head1 = s.copyRandomList1(&n1);
    printListWithRandom(head1);
    Node *head2 = s.copyRandomList2(&n1);
    printListWithRandom(head2);

    return 0;
}