#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int col[15];
    vector<vector<string>> ans;
    bool check(int r, int c)
    {
        for (int i = 0; i < r; i++)
        {
            if (col[i] == c || (abs(col[i] - c) == r - i))
            {
                return false;
            }
        }
        return true;
    }
    void process(int n, int r)
    {
        if (r == n)
        {
            int index = ans.size();
            ans.insert(ans.end(), vector<string>(n, string(n, '.')));
            printf("ans.size() = %d\n", ans.size());
            for (int i = 0; i < n; i++)
            {
                ans[index][i][col[i]] = 'Q';
            }
        }
        for (int c = 0; c < n; c++)
        {
            if (check(r, c))
            {
                col[r] = c;
                process(n, r + 1);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        process(n, 0);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> v = s.solveNQueens(4);
    // print v
    for (int i = 0; i < v.size(); i++)
    {
        cout << "[" << endl;
        for (int j = 0; j < v[i].size(); j++)
            cout << "  " << v[i][j] << endl;
        cout << "]" << endl;
    }
}