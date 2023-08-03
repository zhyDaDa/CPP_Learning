/* 958. 二叉树的完全性检验 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isCBT_flag = false;

    bool isCompleteTree(TreeNode *head)
    {
        queue<TreeNode *> q;
        q.push(head);
        TreeNode *cur;
        while (!q.empty())
        {
            cur = q.front();
            q.pop();

            TreeNode *left = cur->left;
            TreeNode *right = cur->right;

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
};