#include <bits/stdc++.h>
using namespace std;

// 给定一个不可以改动的数组, 要将其划分成若干个连续区间(不少于两个), 区间的数量和大小任意
// 取每个区间内元素之和, 要求最大和 和 最小和的差越小越好, 并打印这个差值. 给出思路, 没必要提供代码

class Solution
{
    vector<int> divid_pool;
    int len;
    int result = INT_MAX;

public:
    void get_result(vector<int> &arr)
    {
        int big = arr[0], small = arr[0];
        int lastLeft = 0;   // 当前区间的左边界(包括)
        // 补一个最后的divid len-1
        divid_pool.push_back(len-1);
        for (auto d: divid_pool)
        {
            // d是当前区间左边界(包括)
            int sum = 0;
            for (int i = lastLeft; i <= d; i++) {
                sum += arr[i];
            }
            lastLeft = d+1;
            big = max(big, sum);
            small = min(small, sum);
        }
        result = min(result, big - small);
        divid_pool.pop_back();
    }
    void process(vector<int> &arr, int x)
    {
        if (x == len - 2)
        {
            get_result(arr);
        }
        divid_pool.push_back(x);
        process(arr, x + 1);
        divid_pool.pop_back();
        process(arr, x + 1);
    }
    int min_diff(vector<int> arr)
    {
        len = arr.size();
        process(arr, 0);
    }
};

int main()
{
    Solution s;
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << s.min_diff(arr);
}