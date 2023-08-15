#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int len = 0;
    vector<vector<int>> result;

    void swap(vector<int> &nums, int a, int b)
    {
        nums[a] = nums[a] ^ nums[b];
        nums[b] = nums[a] ^ nums[b];
        nums[a] = nums[a] ^ nums[b];
    }

    void process(vector<int> &nums, int x)
    {
        if (x == len)
        {
            result.push_back(nums);
            return;
        }
        process(nums, x + 1);
        set<int> s;
        s.insert(nums[x]);
        for (int i = x + 1; i < len; i++)
        {
            if (!s.count(nums[i]))
            {
                s.insert(nums[i]);
                swap(nums, x, i);
                process(nums, x + 1);
                swap(nums, x, i);
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        len = nums.size();
        process(nums, 0);
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums{2,2,1,1};
    vector<vector<int>> res =s.permuteUnique(nums);
    for(auto i:res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}