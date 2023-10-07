#include <bits/stdc++.h>
using namespace std;

// 初始想法, coding错误
class Solution1
{
public:
    unordered_set<int> s;
    map<int, vector<int>> g;
    bool process(int x)
    {
        if (s.count(x))
            return true;
        s.insert(x);
        if (!g.count(x))
            return false;
        for (auto next : g[x])
        {
            if (process(next))
                return true;
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_set<int> s(numCourses);
        for (auto pair : prerequisites)
        {
            g[pair[0]] = vector<int>();
            g[pair[0]].push_back(pair[1]);
        }
        bool flag; // true 表示有环
        for (int i = 0; i < numCourses; i++)
        {
            if (s.count(i))
                continue;
            if (flag = process(i))
            {
                break;
            }
        }
        return !flag;
    }
};

// 仍旧是老想法, 还是行不通
class Solution2
{
public:
    unordered_set<int> s;
    struct Node
    {
    public:
        int value;
        vector<int>
            requires;
        Node(int v)
        {
            value = v;
            requires = vector<int>();
        }
    };

    bool process(int x, unordered_map<int, Node *> &g)
    {
        if (s.count(x))
            return true;
        s.insert(x);
        if (!g.count(x))
            return false;
        for (auto next : g[x]->requires)
        {
            if (process(next, g))
                return true;
        }
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, Node *> g;
        for (auto pair : prerequisites)
        {
            if (!g.count(pair[0]))
            {
                g[pair[0]] = new Node(pair[0]);
            }
            g[pair[0]]->
                requires
                .push_back(pair[1]);
        }
        bool flag; // true 表示有环
        for (auto pair : g)
        {
            if (s.count(pair.first))
                continue;
            s.clear();
            if (flag = process(pair.first, g))
            {
                break;
            }
        }
        return !flag;
    }
};

// 标答: 拓扑排序, 统计入度
class Solution
{
private:
    vector<vector<int>> edges;
    vector<int> indeg;

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto &info : prerequisites)
        {
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }

        int visited = 0;
        while (!q.empty())
        {
            ++visited;
            int u = q.front();
            q.pop();
            for (int v : edges[u])
            {
                --indeg[v];
                if (indeg[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        return visited == numCourses;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> pre = {{1, 0}};
    cout << s.canFinish(2, pre);
}