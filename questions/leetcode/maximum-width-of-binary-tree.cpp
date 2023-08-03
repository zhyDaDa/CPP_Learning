/* 662. 二叉树最大宽度 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        map<TreeNode *, long long> m;
        m[root] = 0;
        TreeNode *cur = root;
        int beginPos = 0;
        TreeNode *endN = root;
        TreeNode *nextEndN;
        int max = 1;

        while (!q.empty())
        {
            cur = q.front();
            q.pop();

            if (beginPos < 0)
            {
                beginPos = m[cur];
            }

            if (cur->left != nullptr)
            {
                m[cur->left] = (m[cur] * 2 + 1) % INT_MAX;
                q.push(nextEndN = cur->left);
            }
            if (cur->right != nullptr)
            {
                m[cur->right] = (m[cur] * 2 + 2) % INT_MAX;
                q.push(nextEndN = cur->right);
            }
            if (cur == endN)
            {
                endN = nextEndN;
                int curWidth = m[cur] - beginPos + 1;
                curWidth = curWidth > 0 ? curWidth : curWidth + INT_MAX;
                max = max > curWidth ? max : curWidth;
                beginPos = -1;
            }
        }
        return max;
    }
};

int main()
{
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(-222222222);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4444);
    head->right->left = new TreeNode(55555555);
    head->right->right = new TreeNode(66);
    head->left->left->right = new TreeNode(777);

    Solution s;

    cout << s.widthOfBinaryTree(head) << endl;

    return 0;
}