/* 剑指 Offer II 044. 二叉树每层的最大值 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
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
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> ans;
        if(root==nullptr)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        
        TreeNode *cur;
        int curLevelCount = 1;
        int nextLevelCount = 0;
        int max=root->val;
        while (!q.empty())
        {
            cur = q.front();
            q.pop();
            if(curLevelCount==0){
                curLevelCount = nextLevelCount;
                nextLevelCount = 0;
                ans.push_back(max);
                max = cur->val;
            }else{
                max = max > cur->val ? max : cur->val;
            }
            curLevelCount--;

            if(cur->left!=nullptr){
                q.push(cur->left);
                nextLevelCount++;
            }
            if(cur->right!=nullptr){
                q.push(cur->right);
                nextLevelCount++;
            }
        }
        ans.push_back(max);
        return ans;
    }
};