#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    vector<int> circularGameLosers(int n, int k)
    {
        vector<bool> check = vector<bool>(n);
        int i = 1;
        int p = 0;
        while (!check[p])
        {
            check[p] = true;
            p = (p + k*i++) % n;
        }
        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            if (!check[i])
            {
                result.push_back(i + 1);
            }
        }
        return result;   
    }
};
