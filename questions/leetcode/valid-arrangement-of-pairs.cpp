#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void swap(vector<vector<int>> &pairs, int i, int j)
    {
        auto temp = pairs[i];
        pairs[i] = pairs[j];
        pairs[j] = temp;
    }

public:
    int len;
    vector<vector<int>> ans;
    bool bfs(int x, vector<vector<int>> &pairs)
    {
        if (x == len - 1)
        {
            return true;
        }
        for (int i = x + 1; i < len; i++)
        {
            if (pairs[i][0] == pairs[x][1])
            {
                swap(pairs, i + 1, x);
                if (bfs(x + 1, pairs))
                    return true;
                swap(pairs, i + 1, x);
            }
        }
        return false;
    }

    vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
    {
        len = pairs.size();
        int difn1 = 114514, difn2 = 0;
        unordered_map<int, int> m;
        for (auto &p : pairs)
        {
            m[p[0]]++;
            m[p[1]]++;
        }
        for (auto p : m)
        {
            if (p.second % 2)
            {
                if (difn1 == 114514)
                    difn1 = p.first;
                else
                    difn2 = p.first;
            }
        }

        if (difn1 == 114514) // 说明所有数出现偶数次
        {
            // 取第一个为root, 直接改变pairs

            vector<vector<int>> ans(pairs);
            bfs(0, ans);
        }
        else
        {
            for (int i = 0; i < len && ans.size() < len; i++)
            {
                if (pairs[i][0] == difn1 || pairs[i][0] == difn2)
                {
                    // 创建复制
                    vector<vector<int>> ans(pairs);
                    // 把可能的root放到第一个
                    swap(ans, 0, i);
                    if (bfs(0, ans))
                        break;
                }
            }
        }
        return ans;
    }
};

class Solution2
{
    void swap(vector<vector<int>> &pairs, int i, int j)
    {
        auto temp = pairs[i];
        pairs[i] = pairs[j];
        pairs[j] = temp;
    }

public:
    int len;
    bool check(vector<vector<int>> &pairs)
    {
        for (int i = 1; i < len; i++)
        {
            if (pairs[i][0] != pairs[i - 1][1])
                return false;
        }
        return true;
    }
    bool process(vector<vector<int>> &pairs, int x)
    {
        bool flag = false;
        if (x == len)
        {
            return check(pairs);
        }
        for (int i = x; i < len && !flag; i++)
        {
            if (pairs[i][0] == pairs[x - 1][1])
            {
                swap(pairs, i, x);
                flag = process(pairs, x + 1);
                swap(pairs, i, x);
            }
        }
        return flag;
    }
    vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
    {
        len = pairs.size();
        if (process(pairs, 0))
            return pairs;
        bool flag = false;
        for (int i = 1; i < len && !flag; i++)
        {
            swap(pairs, i, 0);
            flag = process(pairs, 1);
        }
        return pairs;
    }
};