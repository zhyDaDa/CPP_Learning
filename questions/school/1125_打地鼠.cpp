#include <bits/stdc++.h>
using namespace std;

struct Mouse
{
    int t, v;

public:
    Mouse(int t, int v) : t(t), v(v) {}
};

int main()
{
    int n;
    cin >> n;
    int t[n], v[n];
    for (auto &i : t)
        cin >> i;
    for (auto &i : v)
        cin >> i;

    vector<Mouse> mice;
    for (int i = 0; i < n; i++)
    {
        mice.push_back(Mouse(t[i], v[i]));
    }
    sort(mice.begin(), mice.end(), [](Mouse a, Mouse b)
         { return a.v > b.v; });
    sort(mice.begin(), mice.end(), [](Mouse a, Mouse b)
         { return a.t < b.t; });
    int tick = 0;
    int score = 0;
    while (!mice.empty())
    {
        if (tick > mice.front().t)
        {
            mice.erase(mice.begin());
        }
        else
        {
            score += mice.front().v;
            mice.erase(mice.begin());
            tick++;
        }
    }
    cout << score << endl;
}
