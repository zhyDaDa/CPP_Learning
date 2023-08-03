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

class Solution
{
public:
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

    void preOrderPrint(TreeNode *head)
    {
        if (head == nullptr)
        {
            return;
        }
        cout << head->value << " ";
        preOrderPrint(head->left);
        preOrderPrint(head->right);
    }

    string serialize(TreeNode *root)
    {
        if (root == nullptr)
        {
            return "#_";
        }
        string res = to_string(root->value) + "_";
        res += serialize(root->left);
        res += serialize(root->right);
        return res;
    }

    TreeNode *deserialize(string data)
    {
        queue<string> values;
        string buf;
        for (int i = 0; i < data.length(); i++)
        {
            if (data[i] == '_')
            {
                values.push(buf);
                buf = "";
            }
            else
            {
                buf += data[i];
            }
        }
        return deserialize(values);
    }

    TreeNode *deserialize(queue<string> &values)
    {
        if (values.size() == 0)
        {
            return nullptr;
        }
        TreeNode *head = generateNode(values.front());
        values.pop();
        if(head == nullptr)
        {
            return nullptr;
        }
        head->left = deserialize(values);
        head->right = deserialize(values);
        return head;
    }

    TreeNode *generateNode(string val)
    {
        if (val == "#")
        {
            return nullptr;
        }
        return new TreeNode(stoi(val));
    }
};

int main()
{
    // build a 3-level tree
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->right->left = new TreeNode(5);
    head->right->right = new TreeNode(6);
    head->right->left->right = new TreeNode(7);

    Solution s;
    s.printTree(head);
    cout << "ÏÈÐò±éÀú: ";
    s.preOrderPrint(head);
    cout << endl;
    string res = s.serialize(head);
    cout << res << endl;

    TreeNode *newHead = s.deserialize(res);
    s.printTree(newHead);
}