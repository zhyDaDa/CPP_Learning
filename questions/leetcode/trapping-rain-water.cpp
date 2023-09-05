#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int h = 0, ans = 0;
        int len = height.size();
        bool hasHigher;
        do
        {
            hasHigher = false;
            for (int i = 0; i < len; i++)
            {
                if (height[i] > h)
                {
                    hasHigher = true;
                    int temp = 0;
                    while (i < len - 1 && height[i + 1] <= h)
                    {
                        i++;
                        temp++;
                    }
                    if (i < len - 1)
                    {
                        ans += temp;
                    }
                }
            }
            h++;
        } while (hasHigher);
        return ans;
    }
};

class Solution2
{
public:
    int trap(vector<int> &height)
    {
        int len = height.size();
        vector<int> leftMax(len, 0);
        vector<int> rightMax(len, 0);
        for (int i = 1; i < len; i++)
        {
            leftMax[i] = max(leftMax[i - 1], height[i - 1]);
        }
        for (int i = len - 2; i >= 0; i--)
        {
            rightMax[i] = max(rightMax[i + 1], height[i + 1]);
        }
        int ans = 0;
        for (int i = 0; i < len; i++)
        {
            int minor = min(leftMax[i], rightMax[i]);
            ans += (height[i] < minor) ? minor - height[i] : 0;
        }
        return ans;
    }
};