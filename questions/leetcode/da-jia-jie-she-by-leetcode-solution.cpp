#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int a = 0;
        int b = nums[0];
        int c = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            c = max(a + nums[i], b);
            a = b;
            b = c;
        }
        return c;
    }
};