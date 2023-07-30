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

string getSpace(int num)
{
    string space = " ";
    string buf;
    for (int i = 0; i < num; i++)
    {
        buf += space;
    }
    return buf;
}

void printInOrder(Node *head, int height, string to, int len)
{
    if (head == nullptr)
    {
        return;
    }
    printInOrder(head->right, height + 1, "v", len);
    string val = to + " " + to_string(head->value) + " " + to;
    int lenM = val.length();
    int lenL = (len - lenM) / 2;
    int lenR = len - lenM - lenL;
    val = getSpace(lenL) + val + getSpace(lenR);
    cout << getSpace(height * len) + val << endl;
    printInOrder(head->left, height + 1, "^", len);
}

void printTree(Node *head)
{
    cout << "Binary Tree:" << endl;
    printInOrder(head, 0, "H", 17);
    cout << endl;
}

bool isCBT_flag = false;

bool isCBT(Node *head)
{
    queue<Node *> q;
    q.push(head);
    Node *cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();

        Node *left = cur->left;
        Node *right = cur->right;

        if (isCBT_flag && (left != nullptr || right != nullptr) || (left == nullptr && right != nullptr))
        {
            return false;
        }

        if (left != nullptr)
        {
            q.push(left);
        }
        if (right != nullptr)
        {
            q.push(right);
        }
        else
        {
            isCBT_flag = true;
        }
    }
    return true;
}

struct BBT_return
{
    bool isBBT;
    int height;
    BBT_return(bool isBBT, int height)
    {
        this->isBBT = isBBT;
        this->height = height;
    }
};

BBT_return BBT_process(Node *head)
{
    if (head ==nullptr){
        return BBT_return(true, 0);
    }
    BBT_return left = BBT_process(head->left);
    BBT_return right = BBT_process(head->right);

    bool isBBT = left.isBBT && right.isBBT && abs(left.height - right.height) < 2;
    int height = 1 + (left.height > right.height ? left.height : right.height);

    return BBT_return(isBBT, height);
}

bool isBBT(Node *head)
{
    return BBT_process(head).isBBT;
}

int main()
{
    Node *head = new Node(1);
    head->left = new Node(-222222222);
    head->right = new Node(3);
    head->left->left = new Node(4444);
    head->left->right = new Node(45);
    head->right->left = new Node(55555555);
    head->right->right = new Node(666);
    // head->left->left->left = new Node(67);
    head->left->left->right = new Node(777);

    printTree(head);
    cout << (isCBT(head) ? "Is CBT" : "Isn't CBT") << endl;
    return 0;
}