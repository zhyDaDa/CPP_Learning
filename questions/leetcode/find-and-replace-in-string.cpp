#include <bits/stdc++.h>
using namespace std;

class Solution
{
    struct Quest
    {
        int indice;
        string source;
        string target;

        Quest(int indice, string source, string target) : indice(indice), source(source), target(target) {}
    };

    struct Compare
    {
        bool operator()(const Quest &q1, const Quest &q2)
        {
            return q1.indice < q2.indice;
        }
    };
    
public:
    string findReplaceString(string s, vector<int> &indices, vector<string> &sources, vector<string> &targets)
    {
        string ret;
        int sIndex = 0;
        int k = indices.size();
        int len = s.length();
        int kIndex = 0;

        // 创建一个vector, 将所有的操作按照indice从小到大排序
        vector<Quest> quests;
        for (int i = 0; i < k; i++)
        {
            quests.push_back(Quest(indices[i], sources[i], targets[i]));
        }
        sort(quests.begin(), quests.end(), Compare());

        while (sIndex < len)
        {
            if (kIndex < k && sIndex == quests[kIndex].indice)
            {
                int tempLen = quests[kIndex].source.length();
                bool flag = false;
                for (int i = 0; i < tempLen; i++)
                {
                    if (s[sIndex + i] != quests[kIndex].source[i])
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                {
                    ret += s[sIndex];
                    sIndex++;
                }
                else
                {
                    ret += quests[kIndex].target;
                    sIndex += tempLen;
                }
                kIndex++;
            }
            else
            {
                ret += s[sIndex];
                sIndex++;
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    string str = "abcd";
    vector<int> indices = {0, 2};
    vector<string> sources = {"ab", "ec"};
    vector<string> targets = {"eee", "ffff"};

    cout << s.findReplaceString(str, indices, sources, targets) << endl;
    return 0;
}