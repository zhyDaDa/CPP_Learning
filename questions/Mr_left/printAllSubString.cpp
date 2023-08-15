// 打印一个字符串的全部子序列，包括空字符串
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    string origin;
    int len;
    vector<char> cur;

public:
    void process(int x)
    {
        if (x == len)
        {
            for (auto i : cur)
            {
                cout << i;
            }
            cout << endl;
            return;
        }
        cur.push_back(origin[x]);
        process(x + 1);
        cur.pop_back();
        process(x + 1);
    }

    void printAllSubString(string str)
    {
        origin = str;
        len = str.length();
        cur = vector<char>(str.length());
        process(0);
    }
};

int main()
{
    Solution s;
    string str;
    cin >> str;
    cout << "========================" << endl;
    s.printAllSubString(str);
    return 0;
}