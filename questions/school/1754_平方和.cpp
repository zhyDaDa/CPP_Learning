/* 存在n个变量xi，现在告诉你每个变量的取值范围在[li, ri]中。
假设这n个数字的平方和为S，求总共存在多少种不同的S。 */

/*
朴素

#include <iostream>
#include <set>
#include <map>
using namespace std;

int n;
map<int, int> sqrArr;
map<int, int[2]> nums;
set<int> s;

void checkNthNum(int x)
{
    if (x > n - 1)
    {
        // 边界处理
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += sqrArr[i];
        }
        s.insert(sum);
        return;
    }
    for (int i = nums[x][0]; i <= nums[x][1]; i++)
    {
        sqrArr[x] = i * i;
        checkNthNum(x + 1);
    }

    return;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i][0] >> nums[i][1];
    }

    checkNthNum(0);

    cout << s.size() << endl;

    return 0;
}

*/

/* 高端解 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1000 * 1000 + 10;
bool pd[N]; // passed 通过的

int main()
{
    int n;
    cin >> n;
    pd[0] = 1;
    int ml=0, mr=0; // mass l/r
    int cl, cr; // current l/r
    for (int i = 0; i < n; i++)
    {
        cin >> cl >> cr;
        ml += cl * cl;
        mr += cr * cr;
        for (int j = mr; j >= ml; j--)
        {
            pd[j] = 0;
            for (int k = cl; k <= cr; k++)
            {
                if (j < (k * k + ml - cl * cl))
                    break;
                if (pd[j - k * k])
                {
                    pd[j] = 1;
                    break;
                }
            }
        }
    }
    int ans = 0;
    for (int i = ml; i <= mr; i++)
    {
        ans += pd[i];
    }
    cout << ans << endl;
    return 0;
}
