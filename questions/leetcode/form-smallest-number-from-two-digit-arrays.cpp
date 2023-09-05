#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minNumber(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> s;
        int single = 10;
        int min1 = nums1[0], min2 = nums2[0];
        for(auto n:nums1){
            s.insert(n);
            min1 = min(min1, n);
        }
        for(auto n:nums2){
            if(s.count(n)>0){
                single = min(n, single);
            }
            min2 = min(min2, n);
        }

        if(single<10)
            return single;
        else{
            return min(min1 * 10 + min2, min2 * 10 + min1);
        }
    }
};