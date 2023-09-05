#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<long long> arr)
    {
        int res = 0;
        for (auto i : arr)
        {
            res ^= i;
        }
        return res;
    }

    void divide(vector<long long> arr)
    {
        cout << 1;
        for (int i = 1; i < arr.size(); i++)
        {
            cout << 0;
        }

        cout << endl;
    }
};

int main()
{
    Solution s;
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (s.check(a)||n==1)
        {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
        s.divide(a);
    }
}