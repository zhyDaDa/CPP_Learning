/*
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 
*/
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        unordered_set<int> set;
        for(auto item: nums){
            if(set.count(item)!=0)
                return item;
            set.insert(item);
        }

        return -1;
    }
};

int main(){
    Solution solution;
    int n = 0;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }
    cout << solution.findRepeatNumber(nums) << endl;
    return 0;
}