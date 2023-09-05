#include <bits/stdc++.h>
using namespace std;

// 暴力穷举模拟
class Solution1
{
public:
    int m, n, k;
    vector<int> choice;
    vector<int> p, t;
    int minWaitingTime = INT_MAX;

    void getAns()
    {
        int tick = 0;
        int count = 0;
        while (count < k)
        {
            tick++;
            for (auto i : choice)
            {
                if (t[i] <= tick && (tick - t[i]) % p[i] == 0)
                {
                    count++;
                }
            }
        }
        minWaitingTime = min(minWaitingTime, tick);
    }

    void process(int index, int lastChoice)
    {
        if (index == n)
        {
            getAns();
        }
        for (int i = lastChoice + 1; i < m; i++)
        {
            choice.push_back(i);
            lastChoice = i;
            process(index + 1, lastChoice);
            choice.pop_back();
        }
    }
};

int main1()
{
    Solution1 s;
    cin >> s.m >> s.n >> s.k;
    s.p = vector<int>(s.m);
    s.t = vector<int>(s.m);
    for (auto &i : s.t)
        cin >> i;
    for (auto &i : s.p)
        cin >> i;

    s.process(0, -1);
    cout << s.minWaitingTime << endl;
}

// 二分比对
class Solution2
{
public:
    int m, n, k;
    const int static N = 10e4 + 5;
    int t[N], p[N];
    int num[N];

    bool check(int x)
    {
        for (int i = 0; i < m; i++)
        {
            if (t[i] > x)
                num[i] = 0;
            else
                num[i] = (x - t[i]) / p[i] + 1;
        }
        sort(num, num + m, greater<int>());
        long long sum = 0;
        for (int i = 0; i < n; i++)
            sum += num[i];
        return sum >= k;
    }

    int getMinTime()
    {
        cin >> m >> n >> k;
        for (int i = 0; i < m; i++)
            cin >> t[i];
        for (int i = 0; i < m; i++)
            cin >> p[i];

        int left = 0, right = 10e8;
        int ans = 0;
        while (left < right)
        {
            int mid = left + ((right - left) >> 1);
            if (check(mid))
            {
                ans = mid;
                right = mid;
            }
            else
                left = mid + 1;
        }
        return ans;
    }
};

int main()
{
    Solution2 s;
    cout << s.getMinTime() << endl;
}