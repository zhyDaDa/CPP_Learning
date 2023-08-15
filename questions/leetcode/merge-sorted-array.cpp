#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (n == 0)
            return;
        int p1 = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto a : nums2)
            pq.push(a);
        while (p1 < m)
        {
            if (nums1[p1] > pq.top())
            {
                pq.push(nums1[p1]);
                nums1[p1] = pq.top();
                pq.pop();
            }
            p1++;
        }
        while (p1 < m + n)
        {
            nums1[p1++] = pq.top();
            pq.pop();
        }
    }
};

class Solution2
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        if(n==0) return;
        int p1 = m-1, p2 = n-1,p0=m+n-1;
        while(p1>=0 && p2>=0){
            if(nums1[p1]>nums2[p2])
                nums1[p0--] = nums1[p1--];
            else
                nums1[p0--] = nums2[p2--];
        }
        if(p2>=0)
            copy(nums2.begin(), nums2.begin() + p2 + 1, nums1.begin());
    }
};