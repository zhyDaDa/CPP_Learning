#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < nums.size(); i++)
        {
            if (q.size() < k)
            {
                q.push(nums[i]);
            }
            else if (nums[i] < q.top())
            {
                continue;
            }
            else
            {
                q.pop();
                q.push(nums[i]);
            }
        }
        return q.top();
    }
};