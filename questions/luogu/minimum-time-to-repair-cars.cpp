#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    bool canSolve(ll t, vector<int> &ranks, int cars)
    {
        for (auto r : ranks)
        {
            cars -= (int)sqrt(t / r);
            if (cars <= 0)
                return true;
        }
        return false;
    }
    ll repairCars(vector<int> &ranks, int cars)
    {
        ll L = 1;
        ll R = (ll)ranks[0] * cars * cars;
        ll mid;
        while (L < R)
        {
            mid = L + ((R - L) >> 1);
            if (canSolve(mid, ranks, cars))
                R = mid;
            else
                L = mid + 1;
        }
        return L;
    }
};