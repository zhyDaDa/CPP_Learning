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
    void process(TreeNode *root1, TreeNode *root2)
    {
        root1->val += root2->val;
        if (root2->left != nullptr)
        {
            if (root1->left != nullptr)
                process(root1->left, root2->left);
            else
                root1->left = root2->left;
        }
        if (root2->right != nullptr)
        {
            if (root1->right != nullptr)
                process(root1->right, root2->right);
            else
                root1->right = root2->right;
        }
    }
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if(root2==nullptr) return root1;
        if(root1==nullptr) return root2;
        process(root1, root2);
        return root1;
    }
};