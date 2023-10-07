#include <bits/stdc++.h>
using namespace std;

// 暴力解
class Solution1
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int len = nums.size();
        int i;
        for (i = 0; i < len; i++)
        {
            if (nums[i] >= target)
            {
                break;
            }
        }
        return i;
    }
};

// 二分查找
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int L = 0, R = nums.size();
        while (L < R)
        {
            int mid = L + ((R - L) >> 1);
            if (target > nums[mid])
                L = mid + 1;
            else
                R = mid;
        }
        return L;
    }
};