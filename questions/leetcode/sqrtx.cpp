#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        int L = 0, R = x;
        while (L < R)
        {
            int mid = ((L + R) >> 1) + 1;
            if (1ll * mid * mid > x)
                R = mid - 1;
            else
                L = mid;
        }
        return L;
    }
};

class Solution2
{
public:
    int mySqrt(int x)
    {
        int l = 0, r = x, ans = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.mySqrt(17);
}