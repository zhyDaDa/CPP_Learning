#include <bits/stdc++.h>
using namespace std;

class TrieNode;
class TrieNode
{
public:
    int pass;
    int end;
    vector<TrieNode *> nexts;

    TrieNode()
    {
        this->pass = 0;
        this->end = 0;
        this->nexts = vector<TrieNode *>(26);
    }
};

class Trie
{
public:
    TrieNode *root;
    void createTrie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        if (word.empty())
        {
            return;
        }
        // 将字符串转化为字符数组
        vector<char> chars(word.begin(), word.end());
        TrieNode *cur = root;
        cur->pass++;
        for (int i = 0; i < chars.size(); i++)
        {
            int index = chars[i] - 'a';
            if (cur->nexts[index] == nullptr)
            {
                cur->nexts[index] = new TrieNode();
            }
            cur = cur->nexts[index];
            cur->pass++;
        }
        cur->end++;
    }

    int wordCount(string word)
    {
        if (word.empty())
        {
            return 0;
        }
        vector<char> chars(word.begin(), word.end());
        TrieNode *cur = root;
        for (int i = 0; i < chars.size(); i++)
        {
            int index = chars[i] - 'a';
            if (cur->nexts[index] == nullptr)
            {
                return 0;
            }
            cur = cur->nexts[index];
        }
        return cur->end;
    }

    int prefixCount(string word)
    {
        if (word.empty())
        {
            return 0;
        }
        vector<char> chars(word.begin(), word.end());
        TrieNode *cur = root;
        for (int i = 0; i < chars.size(); i++)
        {
            int index = chars[i] - 'a';
            if (cur->nexts[index] == nullptr)
            {
                return 0;
            }
            cur = cur->nexts[index];
        }
        return cur->pass;
    }

    void delet(string word)
    {
        if (wordCount(word) < 1)
        {
            return;
        }
        vector<char> chars(word.begin(), word.end());
        TrieNode *cur = root;
        cur->pass--;

        TrieNode *deletStartNode = nullptr;
        int deletStartIndex = -1;
        set<TrieNode *> deleteSet;
        for (int i = 0; i < chars.size(); i++)
        {
            int index = chars[i] - 'a';
            if (--cur->nexts[index]->pass < 1)
            {
                deletStartNode = deletStartNode == nullptr ? cur : deletStartNode;
                deletStartIndex = deletStartIndex == -1 ? i : deletStartIndex;
                deleteSet.insert(cur->nexts[index]);
            }
            cur = cur->nexts[index];
        }
        cur->end--;
        if (deletStartIndex == -1)
        {
            deletStartNode->nexts[deletStartIndex] = nullptr;
            // 遍历set, 析构
            for (auto it = deleteSet.begin(); it != deleteSet.end(); it++)
            {
                delete *it;
            }
        }
    }
};