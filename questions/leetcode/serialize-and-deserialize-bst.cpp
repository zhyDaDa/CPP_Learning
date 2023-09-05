#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            if (cur)
            {
                ans += to_string(cur->val) + '_';
                q.push(cur->left);
                q.push(cur->right);
            }
            else
            {
                ans += "#";
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        TreeNode *root = nullptr;
        queue<TreeNode **> q;
        q.push(&root);
        int i = 0;
        while (i < data.size())
        {
            TreeNode **cur = q.front();
            q.pop();
            if (data[i] != '#')
            {
                int val = 0;
                while (data[i] != '_')
                {
                    val = val * 10 + data[i] - '0';
                    i++;
                }
                *cur = new TreeNode(val);
                q.push(&((*cur)->left));
                q.push(&((*cur)->right));
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;