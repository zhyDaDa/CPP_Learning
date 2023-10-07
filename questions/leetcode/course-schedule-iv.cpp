#include <bits/stdc++.h>
using namespace std;

// 原始想法, 超时
class Solution1
{
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        bool g[numCourses][numCourses];
        memset(g, false, sizeof(g));

        for (auto p : prerequisites)
        {
            g[p[0]][p[1]] = true;
        }
        for (int i = 0; i < numCourses; i++)
        {
            queue<int> bfs;
            bfs.push(i);
            while (!bfs.empty())
            {
                int cur = bfs.front();
                bfs.pop();
                for (int j = 0; j < numCourses; j++)
                {
                    // printf("cur: %d, j: %d", cur, j);
                    if (g[cur][j])
                    {
                        bfs.push(j);
                        g[i][j] = true;
                    }
                }
            }
        }

        int len = queries.size();
        vector<bool> ans(len);
        for (int i = 0; i < len; i++)
        {
            ans[i] = g[queries[i][0]][queries[i][1]];
        }
        return ans;
    }
};

// BFS, 计算入度
class Solution2
{
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        bool g[numCourses][numCourses];
        memset(g, false, sizeof(g));
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> nexts(numCourses);
        for (auto p : prerequisites)
        {
            nexts[p[0]].push_back(p[1]);
            inDegree[p[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (auto next : nexts[cur])
            {
                g[cur][next] = true;
                for (int i = 0; i < numCourses; i++)
                {
                    g[i][next] |= g[i][cur];
                }
                inDegree[next]--;
                if (inDegree[next] == 0)
                {
                    q.push(next);
                }
            }
        }

        vector<bool> ans;
        for (auto q : queries)
        {
            ans.push_back(g[q[0]][q[1]]);
        }
        return ans;
    }
};

// DFS, 记忆化
class Solution3
{
private:
    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int cur, vector<vector<bool>> &pre)
    {
        if (visited[cur])
            return;
        visited[cur] = true;
        int len = graph.size();
        for (auto next : graph[cur])
        {
            dfs(graph, visited, next, pre);
            pre[cur][next] = true;
            for (int i = 0; i < len; i++)
            {
                pre[cur][i] = pre[next][i] | pre[cur][i];
            }
        }
    }

public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        vector<vector<bool>> pre(numCourses, vector<bool>(numCourses, false));
        vector<vector<int>> graph(numCourses);
        vector<bool> visited(numCourses, false);
        for (auto p : prerequisites)
        {
            graph[p[0]].push_back(p[1]);
        }
        for (int i = 0; i < numCourses; i++)
        {
            dfs(graph, visited, i, pre);
        }

        vector<bool> ans;
        for (auto q : queries)
        {
            ans.push_back(pre[q[0]][q[1]]);
        }
        return ans;
    }
};