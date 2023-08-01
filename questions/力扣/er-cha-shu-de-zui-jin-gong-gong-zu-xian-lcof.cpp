/* 剑指 Offer 68 - II. 二叉树的最近公共祖先 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*自己的想法

class Solution
{
private:
    stack<TreeNode *> a1;
    stack<TreeNode *> a2;
    TreeNode *p0;
    TreeNode *q0;
    bool process1(TreeNode *head)
    {
        if (head == nullptr)
            return false;
        a1.push(head);
        if (head == p0 || process1(head->left) || process1(head->right))
            return true;
        else
        {
            a1.pop();
            return false;
        }
    }
    bool process2(TreeNode *head)
    {
        if (head == nullptr)
            return false;
        a2.push(head);
        if (head == q0 || process2(head->left) || process2(head->right))
            return true;
        else
        {
            a2.pop();
            return false;
        }
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        p0 = p;
        q0 = q;
        TreeNode *cur = root;
        process1(root);
        process2(root);
        while (a1.size() > a2.size())
        {
            a1.pop();
        }
        while (a1.size() < a2.size())
        {
            a2.pop();
        }
        while (a1.top() != a2.top())
        {
            a1.pop();
            a2.pop();
        }
        return a1.top();
    }
};

*/
/*左神笨办法
class Solution
{
private:
    map<TreeNode *, TreeNode *> m;
    void process(TreeNode *head)
    {
        if (head == nullptr)
            return;
        m[head->left] = head;
        m[head->right] = head;

        process(head->left);
        process(head->right);
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        process(root);
        set<TreeNode *> s;
        TreeNode *cur = p;

        while (cur != root)
        {
            s.insert(cur);
            cur = m[cur];
        }
        while (q != root)
        {
            if (s.count(q) > 0)
                return q;
            q = m[q];
        }
        return root;
    }
};
*/

/* 左神好方法 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(root == nullptr || root ==p||root ==q)
            return root;
        TreeNode *left = lowestCommonAncestor(  root->left,   p,   q);
        TreeNode *right  = lowestCommonAncestor( root->right,  p,  q);

        if(left!=nullptr&&right!=nullptr)
            return root;
        return left != nullptr ? left : right;
    }
};
