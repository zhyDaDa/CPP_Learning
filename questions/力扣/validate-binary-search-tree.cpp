/* 98. ÑéÖ¤¶þ²æËÑË÷Ê÷ */
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
private:
    int pre = 114514;

public:
    bool isValidBST(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (!isValidBST(root->left))
        {
            return false;
        }
        if (pre == 114514)
        {
            pre = root->val;
        }
        else if (root->val <= pre)
        {
            return false;
        }
        else
        {
            pre = root->val;
        }

        return isValidBST(root->right);
    }
};

int main()
{
    TreeNode *head = new TreeNode(2);
    head->left = new TreeNode(1);
    head->right = new TreeNode(3);

    Solution s;
    cout << s.isValidBST(head) << endl;
}