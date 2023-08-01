/* P8 6.图 1:48:00
 * 在有父节点指针的二叉树中找到一个节点的后继节点
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode *father = nullptr;
    TreeNode(int v)
    {
        this->value = v;
        this->left = nullptr;
        this->right = nullptr;
        this->father = nullptr;
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

void printInOrder(TreeNode *head, int height, string to, int len)
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

void printTree(TreeNode *head)
{
    cout << "Binary Tree:" << endl;
    printInOrder(head, 0, "H", 17);
    cout << endl;
}

void inOrderPrint(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    inOrderPrint(root->left);
    cout << root->value << " ";
    inOrderPrint(root->right);
}

class Solution
{
private:
    TreeNode *getLeftMost(TreeNode *p)
    {
        if (p == nullptr)
        {
            return p;
        }
        while (p->left != nullptr)
        {
            p = p->left;
        }
        return p;
    }

public:
    TreeNode *findInOrderNextNode(TreeNode *p)
    {
        if (p->right != nullptr)
        {
            return getLeftMost(p->right);
        }
        while (p->father != nullptr && p->father->left != p)
        {
            p = p->father;
        }
        return p->father;
    }
};

int main()
{
    TreeNode *head = new TreeNode(1);

    // 造一颗高度为3的满二叉树, 每个节点的father指针都指向其父节点
    head->left = new TreeNode(2);
    head->left->father = head;
    head->right = new TreeNode(3);
    head->right->father = head;
    head->left->left = new TreeNode(4);
    head->left->left->father = head->left;
    head->left->right = new TreeNode(5);
    head->left->right->father = head->left;
    head->right->left = new TreeNode(6);
    head->right->left->father = head->right;
    head->right->right = new TreeNode(7);
    head->right->right->father = head->right;

    printTree(head);

    Solution s;
    TreeNode *p = head->right->right;
    TreeNode *q = s.findInOrderNextNode(p);
    cout
        << "中序遍历: ";
    inOrderPrint(head);
    cout << endl;
    cout << "p: " << p->value << endl;
    cout << "p的后继节点: " << (q == nullptr ? "null" : to_string(q->value))
         << endl;
}