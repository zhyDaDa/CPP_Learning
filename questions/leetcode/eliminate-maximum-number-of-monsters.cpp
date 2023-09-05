#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        int len = dist.size();
        vector<int> arriveTime(len, 0);
        for (int i = 0; i < len; i++)
        {
            arriveTime[i] = (dist[i] + speed[i] - 1) / speed[i];
        }
        int n = 0;
        sort(arriveTime.begin(), arriveTime.end(), less<int>());
        for (auto i : arriveTime)
        {
            cout << i << ' ';
        }
        cout << endl;
        while (n < len && n <= arriveTime[n] - 1)
        {
            n++;
        }
        return n;
    }
};

int main()
{
    Solution s;
    vector<int> dist = {1, 3, 4};
    vector<int> speed = {1, 1, 1};
    cout << s.eliminateMaximum(dist, speed) << endl;
}
