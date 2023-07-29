/*
“回文串“是翻转后仍然不变的字符串，例如”qwq”,”abba”。
一个字符串中的”回文子串“是指这个字符串一个具有回文性质 的子串，例如”qwq”中的回文字串有”q”,”w”,”q”,”qwq”。
但你认为这些还是太简单了，于是你定义一个字符串中的”本质不同的回文子串“是去重后的回文子串，例如”qwq”中的”本质不同回文子串”有”q”,”w”,”qwq”。
但这看起来还是没意思，于是你定义”本质不同公共回文子串“是两个字符串的”本质不同回文子串”的集合的交集，例如”qaqw”和”qwq”的”本质不同的公共回文子串”是”q”,”w”。
 */
#include <bits/stdc++.h>
using namespace std;

int n, m;
set<string> s1, s2;

// 提取回文子串
void getPalindrome(string &s)
{
    cout << s << endl;
    int len = s.length();
    cout << "s可读取" << endl;
    // 遍历每个字母, 如果左右两边的字母相同, 则记录到s1中, 并继续向两边扩展
    // 单个字母也是回文子串
    for (int i = 0; i < s.length(); i++)
    {
        s1.insert(s.substr(i, 1));
        int l = i - 1, r = i + 1;
        while (l >= 0 && r < len && s[l] == s[r])
        {
            s1.insert(s.substr(l, r - l + 1));
            l--;
            r++;
        }
    }
}
int compare(string s)
{
    int len = s.length();
    // 遍历每个字母, 如果左右两边的字母相同, 则记录到s1中, 并继续向两边扩展
    // 单个字母也是回文子串
    for (int i = 0; i < s.length(); i++)
    {
        s1.insert(s.substr(i, 1));
        int l = i - 1, r = i + 1;
        while (l >= 0 && r < len && s[l] == s[r])
        {
            // 将这个回文子串在s1中查找, 如果有就加入s2
            if (s1.find(s.substr(l, r - l + 1)) != s1.end())
            {
                s2.insert(s.substr(l, r - l + 1));
            }
            l--;
            r++;
        }
    }
    // 返回s2的大小
    return s2.size();
}

int main()
{
    cin >> n >> m;
    string strings[n];
    for (int i = 0; i < n; i++)
    {
        cin >> strings[i];
    }
    int a, b;
    // 会有m次问询, 每次输入两个数, 表示两个字符串的下标
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        // 如果相同, 则输出该字符串有多少本质不同的公共回文子串
        if (a == b)
        {
            // 先清空s1
            s1.clear();
            getPalindrome(strings[a]);
            cout << s1.size() << endl;
        }
        else
        {
            // 先清空s1和s2
            s1.clear();
            s2.clear();
            getPalindrome(strings[a]);
            cout << compare(strings[b]) << endl;
        }
    }
}