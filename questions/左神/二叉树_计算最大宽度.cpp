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

    return 0;
}