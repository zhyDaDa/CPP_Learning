/*
�����Ĵ����Ƿ�ת����Ȼ������ַ��������硱qwq��,��abba����
һ���ַ����еġ������Ӵ�����ָ����ַ���һ�����л������� ���Ӵ������硱qwq���еĻ����ִ��С�q��,��w��,��q��,��qwq����
������Ϊ��Щ����̫���ˣ������㶨��һ���ַ����еġ����ʲ�ͬ�Ļ����Ӵ�����ȥ�غ�Ļ����Ӵ������硱qwq���еġ����ʲ�ͬ�����Ӵ����С�q��,��w��,��qwq����
���⿴��������û��˼�������㶨�塱���ʲ�ͬ���������Ӵ����������ַ����ġ����ʲ�ͬ�����Ӵ����ļ��ϵĽ��������硱qaqw���͡�qwq���ġ����ʲ�ͬ�Ĺ��������Ӵ����ǡ�q��,��w����
 */
#include <bits/stdc++.h>
using namespace std;

int n, m;
set<string> s1, s2;

// ��ȡ�����Ӵ�
void getPalindrome(string &s)
{
    cout << s << endl;
    int len = s.length();
    cout << "s�ɶ�ȡ" << endl;
    // ����ÿ����ĸ, ����������ߵ���ĸ��ͬ, ���¼��s1��, ��������������չ
    // ������ĸҲ�ǻ����Ӵ�
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
    // ����ÿ����ĸ, ����������ߵ���ĸ��ͬ, ���¼��s1��, ��������������չ
    // ������ĸҲ�ǻ����Ӵ�
    for (int i = 0; i < s.length(); i++)
    {
        s1.insert(s.substr(i, 1));
        int l = i - 1, r = i + 1;
        while (l >= 0 && r < len && s[l] == s[r])
        {
            // ����������Ӵ���s1�в���, ����оͼ���s2
            if (s1.find(s.substr(l, r - l + 1)) != s1.end())
            {
                s2.insert(s.substr(l, r - l + 1));
            }
            l--;
            r++;
        }
    }
    // ����s2�Ĵ�С
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
    // ����m����ѯ, ÿ������������, ��ʾ�����ַ������±�
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        // �����ͬ, ��������ַ����ж��ٱ��ʲ�ͬ�Ĺ��������Ӵ�
        if (a == b)
        {
            // �����s1
            s1.clear();
            getPalindrome(strings[a]);
            cout << s1.size() << endl;
        }
        else
        {
            // �����s1��s2
            s1.clear();
            s2.clear();
            getPalindrome(strings[a]);
            cout << compare(strings[b]) << endl;
        }
    }
}