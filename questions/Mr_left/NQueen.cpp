#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    int n = 0;
    vector<int> col;
    int ans = 0;

    bool isValid(int x, int y)
    {
        for (int i = 0; i < x; i++)
        {
            if (col[i] == y || abs(i - x) == abs(col[i] - y))
            {
                return false;
            }
        }
        return true;
    }

    int process(int x)
    {
        if (x == n)
        {
            return 1;
        }
        int ret = 0;
        for (int y = 0; y < n; y++)
        {
            if (isValid(x, y))
            {
                col[x] = y;
                ret += process(x + 1);
            }
        }
        return ret;
    }

    int getAns(int num)
    {
        if (num < 1)
        {
            return 0;
        }
        ans = 0;
        n = num;
        col = vector<int>(num, 0);
        process(0);
    }
};

// 使用位运算
class Solution2
{
public:
    int n = 0;
    vector<int> col;
    int ans = 0;

    bool isValid(int x, int y)
    {
        for (int i = 0; i < x; i++)
        {
            if (col[i] == y || abs(i - x) == abs(col[i] - y))
            {
                return false;
            }
        }
        return true;
    }

    int process(int x, int limit)
    {
        if (x == limit)
        {
            return 1;
        }
        int ret = 0;
        int pos = limit & (~(x | col[x]));
        while (pos > 0)
        {
            int p = pos & (~pos + 1);
            pos -= p;
            col[x] = log2(p) + 1;
            ret += process(x + 1, limit);
        }
        return ret;
    }

    int getAns(int num)
    {
        if (num < 1)
        {
            return 0;
        }
        ans = 0;
        n = num;
        col = vector<int>(num, 0);
        process(0, (1 << num) - 1);
    }

};

int main()
{
    Solution1 s1;
    // 获得当前时间，单位为毫秒
    clock_t currentTime = clock();
    cout << s1.getAns(14) << endl;
    // 输出运行时间, 到毫秒
    cout << (int)(1000 * (clock() - currentTime) / (double)CLOCKS_PER_SEC) << "ms" << endl;
}