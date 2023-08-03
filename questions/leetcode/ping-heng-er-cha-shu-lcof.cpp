/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
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

    BBT_return BBT_process(TreeNode *head)
    {
        if (head == nullptr)
        {
            return BBT_return(true, 0);
        }
        BBT_return left = BBT_process(head->left);
        BBT_return right = BBT_process(head->right);

        bool isBBT = left.isBBT && right.isBBT && abs(left.height - right.height) < 2;
        int height = 1 + (left.height > right.height ? left.height : right.height);

        return BBT_return(isBBT, height);
    }

public:
    bool isBalanced(TreeNode *head)
    {
        return BBT_process(head).isBBT;
    }
};