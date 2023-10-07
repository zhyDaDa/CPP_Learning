#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int L = 0, R = m, x = 0, y = 0;
        while (L <= R)
        {
            int mid = (L + R) >> 1;
            if (target >= matrix[mid][0])
            {
                x = mid;
                L = mid + 1;
            }
            else
            {
                R = mid - 1;
            }
        }
        L = 0;
        R = n;
        while (L <= R)
        {
            int mid = L + (R - L >> 1);
            if (target >= matrix[x][mid])
            {
                y = mid;
                L = mid + 1;
            }
            else
            {
                R = mid - 1;
            }
        }
        return target == matrix[x][y];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1}};
    int target = 0;
    cout << s.searchMatrix(matrix, target);
}