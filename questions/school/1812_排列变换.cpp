// 给定一个长度为n的排列a，需要将这个排列变成b。
// 每次可以选择一个数字往左移若干个位置。
// 请求出最小移动次数。

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int minMoves(int len, vector<int> &a, vector<int> &b)
    {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < len; ++i)
        {
            hashtable[a[i]] = i;
        }
        int result = 0;
        for (int i = 0; i < len; ++i)
        {
            int index = hashtable[b[i]];
            result += index - i;
            for (int j = index; j > i; --j)
            {
                hashtable[a[j]] = j - 1;
                swap(a[j], a[j - 1]);
            }
        }
        return result;
    }
};

int main()
{
    int len = 0;
    cin >> len;
    vector<int> a(len);
    vector<int> b(len);
    for (int i = 0; i < len; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < len; ++i)
    {
        cin >> b[i];
    }
    Solution solution;
    cout << solution.minMoves(len, a, b) << endl;
    return 0;
}