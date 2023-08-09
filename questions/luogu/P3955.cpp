#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    int min;
    vector<TrieNode *> nexts;

    TrieNode()
    {
        min = INT_MAX;
        nexts = vector<TrieNode *>(10, nullptr);
    }
};

class Solution
{

public:
    TrieNode *root;
    void buildTrieTree()
    {
        root = new TrieNode();
    }
    void insert(int number)
    {
        TrieNode *cur = root;
        int x = number;
        while (x != 0)
        {
            int index = x % 10;
            x /= 10;
            if (cur->nexts[index] == nullptr)
            {
                cur->nexts[index] = new TrieNode();
            }
            cur->min = min(cur->min, number);
            cur = cur->nexts[index];
        }
        cur->min = number;
    }
    void process(int number, int len)
    {
        TrieNode *cur = root;
        // number 一定是正整数
        while (number != 0)
        {
            int index = number % 10;
            number /= 10;
            if (cur->nexts[index] == nullptr)
            {
                cout << -1 << endl;
                return;
            }
            cur = cur->nexts[index];
        }
        cout << cur->min << endl;
    }
};

class ShabbySolution
{
public:
    vector<int> books;
    void insert(int number)
    {
        books.push_back(number);
    }
    void process(int number, int len)
    {
        int minIndex = -1;
        int min = INT_MAX;
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i] % (int)round(pow(10, len)) == number)
            {
                if (books[i] < min)
                {
                    min = books[i];
                    minIndex = i;
                }
            }
        }
        if (minIndex == -1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << min << endl;
        }
    }
};

int main2()
{
    Solution s;
    s.buildTrieTree();
    int n = 10, q = 1;
    int numbers[] = {
        6038, 24179, 18190, 29657, 7958, 6191, 19815, 22888, 19156, 11511};
    while (n--)
    {
        int number = numbers[n];
        s.insert(number);
    }
    cout << s.root->nexts[0]->min << endl;
    while (q--)
    {
        int len = 1, number = 0;
        s.process(number, len);
    }
}
int main1()
{
    // 对数器
    int times = 5;
    while (times--)
    {

        Solution s1;
        s1.buildTrieTree();
        ShabbySolution s2;
        int n = 10;
        // 随机生成5个5位数, 并让两个方案接收, 打印出来
        while (n--)
        {
            int number = rand() % 100000;
            s1.insert(number);
            s2.insert(number);
            cout << number << endl;
        }
        cout << "-------------------" << endl;
        // 随机生成10个查询, 并让两个方案接收
        n = 25;
        while (n--)
        {
            int len = rand() % 5 + 1;
            int number = rand() % (int)(pow(10, len));
            cout << len << " " << number << endl;
            cout << endl;

            s1.process(number, len);
            s2.process(number, len);
            cout << "-------------------" << endl;
        }
    }
}

int main()
{
    Solution s;
    s.buildTrieTree();
    int n, q;
    cin >> n >> q;
    while (n--)
    {
        int number;
        cin >> number;
        s.insert(number);
    }
    while (q--)
    {
        int len, number;
        cin >> len >> number;
        s.process(number, len);
    }
}