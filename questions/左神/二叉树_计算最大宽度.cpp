#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->value = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// 用map记录每个node所在层
int getMaxWidth1(Node *head)
{
    queue<Node *> q;
    q.push(head);
    map<Node *, int> m; // 该Node在第几层
    m[head] = 1;
    int curLevel = 1;
    int curLevelCount = 0;
    int max = 0;
    while (!q.empty())
    {
        Node *cur = q.front();
        q.pop();

        if (m[cur] != curLevel)
        {
            max = max > curLevelCount ? max : curLevelCount;
            curLevelCount = 1;
            curLevel++;
        }
        else
        {
            curLevelCount++;
        }

        if (cur->left != nullptr)
        {
            q.push(cur->left);
            m[cur->left] = m[cur] + 1;
        }
        if (cur->right != nullptr)
        {
            q.push(cur->right);
            m[cur->right] = m[cur] + 1;
        }
    }
    return max;
}
// 用上下两层的计数器判断是否走完
int getMaxWidth2(Node *head)
{
    queue<Node *> q;
    q.push(head);
    int curCount = 1;
    int nextCount = 0;
    int max = 1;
    while (!q.empty())
    {
        if (curCount == 0)
        {
            max = max > nextCount ? max : nextCount;
            curCount = nextCount;
            nextCount = 0;
        }
        Node *cur = q.front();
        q.pop();
        curCount--;

        if (cur->left != nullptr)
        {
            q.push(cur->left);
            nextCount++;
        }
        if (cur->right != nullptr)
        {
            q.push(cur->right);
            nextCount++;
        }
    }
    return max;
}
// 用两个指针记录最末尾的节点
int getMaxWidth3(Node *head)
{
    queue<Node *> q;
    q.push(head);
    Node *curEnd = head;
    Node *nextEnd;
    int count = 0;
    int max = 1;
    while (!q.empty())
    {
        Node *cur = q.front();
        q.pop();
        count++;

        if (cur->left != nullptr)
        {
            q.push(nextEnd = cur->left);
        }
        if (cur->right != nullptr)
        {
            q.push(nextEnd = cur->right);
        }

        if (cur == curEnd)
        {
            max = max > count ? max : count;
            count = 0;
            curEnd = nextEnd;
        }
    }
    return max;
}

int main()
{
    Node *head = new Node(1);
    head->left = new Node(-222222222);
    head->right = new Node(3);
    head->left->left = new Node(4444);
    head->right->left = new Node(55555555);
    head->right->right = new Node(66);
    head->left->left->right = new Node(777);

    cout << getMaxWidth1(head) << endl;
    cout << getMaxWidth2(head) << endl;
    cout << getMaxWidth3(head) << endl;

    return 0;
}