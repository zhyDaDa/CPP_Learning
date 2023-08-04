#include <bits/stdc++.h>
using namespace std;

class Node;
class Edge;
class Graph;

class Node
{
public:
    int value;
    int in;  // 入度
    int out; // 出度

    vector<Node *> nexts;
    vector<Edge *> edges;

    Node()
    {
        this->value = 0;
        this->in = 0;
        this->out = 0;
        this->nexts = vector<Node *>();
        this->edges = vector<Edge *>();
    }
    Node(int x)
    {
        this->value = x;
        this->in = 0;
        this->out = 0;
        this->nexts = vector<Node *>();
        this->edges = vector<Edge *>();
    }
};

class Edge
{
public:
    int weight;
    Node *from;
    Node *to;

    Edge()
    {
        this->weight = 0;
        this->from = nullptr;
        this->to = nullptr;
    }

    Edge(int weight, Node *from, Node *to)
    {
        this->weight = weight;
        this->from = from;
        this->to = to;
    }

    bool operator>(Edge *edge) const
    {
        return this->weight > edge->weight;
    }
    bool operator==(Edge *edge) const
    {
        return this->weight == edge->weight;
    }
    bool operator<(Edge *edge) const
    {
        return this->weight < edge->weight;
    }
};

class Graph
{
public:
    map<int, Node *> nodes;
    set<Edge *> edges;

    Graph()
    {
        this->nodes = map<int, Node *>();
        this->edges = set<Edge *>();
    }

    Graph(map<int, Node *> nodes, set<Edge *> edges)
    {
        this->nodes = nodes;
        this->edges = edges;
    }
};

Graph *createGraph(vector<vector<int>> matrix)
{
    Graph *g = new Graph();
    for (int i = 0; i < matrix.size(); i++)
    {
        int weight = matrix[i][0];
        int fromIndex = matrix[i][1];
        int toIndex = matrix[i][2];

        if (g->nodes[fromIndex] == nullptr)
        {
            g->nodes[fromIndex] = new Node(fromIndex);
        }
        if (g->nodes[toIndex] == nullptr)
        {
            g->nodes[toIndex] = new Node(toIndex);
        }

        Node *fromNode = g->nodes[fromIndex];
        Node *toNode = g->nodes[toIndex];

        Edge *newEdge = new Edge(weight, fromNode, toNode);
        g->edges.insert(newEdge);
        fromNode->out++;
        fromNode->nexts.push_back(toNode);
        fromNode->edges.push_back(newEdge);
        toNode->in++;
    }
    return g;
}

Graph *createUndirectedGraph(vector<vector<int>> matrix)
{
    Graph *g = new Graph();
    for (int i = 0; i < matrix.size(); i++)
    {
        int weight = matrix[i][0];
        int fromIndex = matrix[i][1];
        int toIndex = matrix[i][2];

        if (g->nodes[fromIndex] == nullptr)
        {
            g->nodes[fromIndex] = new Node(fromIndex);
        }
        if (g->nodes[toIndex] == nullptr)
        {
            g->nodes[toIndex] = new Node(toIndex);
        }

        Node *fromNode = g->nodes[fromIndex];
        Node *toNode = g->nodes[toIndex];

        Edge *newEdge = new Edge(weight, fromNode, toNode);
        Edge *newEdge_reverse = new Edge(weight, toNode, fromNode);
        g->edges.insert(newEdge);
        fromNode->out++;
        fromNode->nexts.push_back(toNode);
        fromNode->edges.push_back(newEdge);
        toNode->in++;
        toNode->out++;
        toNode->nexts.push_back(fromNode);
        toNode->edges.push_back(newEdge_reverse);
        fromNode->in++;
    }
    return g;
}

void BFS(Node *root)
{
    queue<Node *> q;
    set<Node *> s;
    q.push(root);
    s.insert(root);
    while (!q.empty())
    {
        Node *cur = q.front();
        q.pop();
        cout << cur->value << " ";
        for (auto next : cur->nexts)
        {
            if (!s.count(next))
            {
                q.push(next);
                s.insert(next);
            }
        }
    }
    cout << endl;
}

void DFS(Node *root)
{
    stack<Node *> st;
    set<Node *> se;
    st.push(root);
    se.insert(root);
    cout << root->value << " ";
    while (!st.empty())
    {
        Node *cur = st.top();
        st.pop();
        for (auto next : cur->nexts)
        {
            if (!se.count(next))
            {
                st.push(cur);
                st.push(next);
                se.insert(next);
                cout << next->value << " ";
                break;
            }
        }
    }
    cout << endl;
}

vector<Node *> sortedTopology(Graph *g)
{
    map<Node *, int> m;
    queue<Node *> zeroQ;
    for (auto i : g->nodes)
    {
        if (i.second->in == 0)
        {
            zeroQ.push(i.second);
        }
        else
        {
            m[i.second] = i.second->in;
        }
    }
    // for (int i = 1; i <= 6; i++)
    // {
    //     cout << m[g->nodes[i]] << " ";
    // }
    // cout << endl;
    // for (Node *q = zeroQ.front(); q != zeroQ.back(); q++)
    // {
    //     cout << q->value << " ";
    // }
    // cout << zeroQ.back()->value << endl;

    vector<Node *> ansList;
    while (!zeroQ.empty())
    {
        Node *cur = zeroQ.front();
        ansList.push_back(cur);
        zeroQ.pop();
        for (Node *next : cur->nexts)
        {
            if (--m[next] == 0)
            {
                zeroQ.push(next);
            }
        }
    }
    return ansList;
}

class MySets
{

public:
    map<Node *, Node *> setMap;
    void setUp(map<int, Node *> nodes)
    {
        for (auto pair : nodes)
        {
            setMap[pair.second] = pair.second;
        }
    }

    bool isSameSet(Node *fromNode, Node *toNode)
    {
        return setMap[fromNode] == setMap[toNode];
    }

    void mergeSet(Node *fromNode, Node *toNode)
    {
        Node *from = setMap[fromNode];
        Node *to = setMap[toNode];
        for (auto pair : setMap)
        {
            if (pair.second == from)
            {
                setMap[pair.first] = to;
            }
        }
    }
};

set<Edge *> KruskalMST(Graph *g)
{
    MySets unionFind;
    unionFind.setUp(g->nodes);

    struct edgeCmp
    {
        bool operator()(Edge *e1, Edge *e2) const
        {
            return e1->weight > e2->weight;
        }
    };

    priority_queue<Edge *, vector<Edge *>, edgeCmp> q;
    for (auto edge : g->edges)
    {
        q.push(edge);
    }

    set<Edge *> ansSet;
    while (!q.empty())
    {
        Edge *cur = q.top();
        q.pop();
        Node *from = cur->from;
        Node *to = cur->to;
        if (!unionFind.isSameSet(from, to))
        {
            ansSet.insert(cur);
            unionFind.mergeSet(from, to);
        }
    }
    return ansSet;
}

set<Edge *> PrimMST(Graph *g)
{
    struct edgeCmp
    {
        bool operator()(Edge *e1, Edge *e2) const
        {
            return e1->weight > e2->weight;
        }
    };

    priority_queue<Edge *, vector<Edge *>, edgeCmp> unlockedEdges;
    set<Node *> visitedNodes;
    set<Edge *> ansSet;

    for (auto pair : g->nodes)
    {
        Node *cur = pair.second;
        visitedNodes.insert(cur);
        for (auto e : cur->edges)
        {
            unlockedEdges.push(e);
        }
        while (!unlockedEdges.empty())
        {
            Edge *curEdge = unlockedEdges.top();
            unlockedEdges.pop();
            bool flag = visitedNodes.count(curEdge->from) == 0;
            if (!flag && visitedNodes.count(curEdge->to) != 0)
            {
                continue;
            }
            ansSet.insert(curEdge);
            cur = flag ? curEdge->from : curEdge->to;
            visitedNodes.insert(cur);
            for (auto e : cur->edges)
            {
                unlockedEdges.push(e);
            }
        }
    }
    return ansSet;
}

map<Node *, int> DiJkstra(Graph *g, Node *startNode)
{
    // 初始化
    map<Node *, int> bufMap;
    map<Node *, int> ansMap;
    int nodeCount = 0;
    for (auto pair : g->nodes)
    {
        bufMap[pair.second] = INT_MAX;
        nodeCount++;
    }
    bufMap[startNode] = 0;

    while (--nodeCount > 0) // 处理到最后一个节点的时候, 必定其余都锁定
    {
        // 选出表格中最小的
        Node *cur = startNode;
        int minDistance = INT_MAX;
        for (auto pair : bufMap)
        {
            if (pair.second < minDistance)
            {
                cur = pair.first;
                minDistance = bufMap[cur];
            }
        }
        // cout << "The chosen closest Node: " << cur->value << ", it's distance is: " << bufMap[cur] << endl;

        // 考察邻居能不能改进
        for (Edge *e : cur->edges)
        {
            if (bufMap.count(e->to) && bufMap[e->to] > bufMap[cur] + (e->weight))
            {
                bufMap[e->to] = bufMap[cur] + (e->weight);
                // cout << e->to->value << ": " << bufMap[e->to] << endl;
            }
        }

        // 锁定该点
        ansMap[cur] = bufMap[cur];
        bufMap.erase(cur);
    }
    // 别落下最后一位
    auto lastNodePair = bufMap.begin();
    ansMap[lastNodePair->first] = lastNodePair->second;

    return ansMap;
}

int main()
{
    // vector<vector<int>> matrix = {
    //     {1, 1, 2},
    //     {2, 1, 3},
    //     {3, 2, 3},
    //     {4, 2, 4},
    //     {5, 3, 5},
    //     {6, 3, 6},
    //     {7, 5, 2},
    // };

    vector<vector<int>> matrix = {
        {1, 1, 2},
        {2, 1, 4},
        {3, 1, 5},
        {4, 3, 4},
        {5, 3, 5},
        {6, 4, 5},
        {7, 6, 7},
        {8, 6, 8},
        {9, 6, 9},
        {10, 7, 8},
        {11, 8, 9},
        {12, 3, 9},
    };
    // Graph *g = createGraph(matrix);
    Graph *g = createUndirectedGraph(matrix);
    // BFS(g->nodes[1]);
    // DFS(g->nodes[1]);
    // vector<Node *> v = sortedTopology(g);
    // cout << v.size() << endl;
    // for (auto i : v)
    // {
    //     cout << i->value << " ";
    // }
    // cout << endl;
    // set<Edge *> kruskalEdgeSet = KruskalMST(g);
    // set<Edge *> kruskalEdgeSet = PrimMST(g);
    // for (auto e : kruskalEdgeSet)
    // {
    //     cout << e->weight << "\t"
    //          << e->from->value << "\t"
    //          << e->to->value << endl;
    // }
    map<Node *, int> m = DiJkstra(g, g->nodes[1]);
    for (int i = 1; i <= 9; i++)
    {
        cout << i << "\t";
    }
    cout << endl;
    for (int i = 1; i <= 9; i++)
    {
        cout << m[g->nodes[i]] << "\t";
    }
    cout << endl;
}

/*
有疑惑的代码
在setUp中设置断点, 可以看到setMap[pair.second] = l执行完毕后
又会来到list<Node *> l不知道执行了什么, 然后才继续下一个循环
从结果上看, 这个setUp执行正确

但mergeSet中设置断点, 和刚才一样, 两处定义又会在执行结束后执行一次,
且对setMap并未产生修改

应该是实例和指针的关系, 但实在不懂为什么程序走着走着会向上走...


class MySets
{

public:
    map<Node *, list<Node *>> setMap;
    void setUp(map<int, Node *> nodes)
    {
        for (auto pair : nodes)
        {
            list<Node *> l;
            l.push_back(pair.second);
            setMap[pair.second] = l;
        }
    }

    bool isSameSet(Node *fromNode, Node *toNode)
    {
        return setMap[fromNode] == setMap[toNode];
    }

    void mergeSet(Node *fromNode, Node *toNode)
    {
        list<Node *> fromSet = setMap[fromNode];
        list<Node *> toSet = setMap[toNode];

        for (auto from : fromSet)
        {
            setMap[from] = toSet;
            toSet.push_back(from);
        }
    }
};

set<Edge *> KruskalMST(Graph *g)
{
    MySets unionFind;
    unionFind.setUp(g->nodes);
    // for(auto pair:unionFind.setMap){
    //     cout << pair.first->value << "\t" << pair.second.size() << endl;
    // }
    priority_queue<Edge *> q;
    for (auto edge : g->edges)
    {
        q.push(edge);
    }

    set<Edge *> ansSet;
    while (!q.empty())
    {
        Edge *cur = q.top();
        q.pop();
        Node *from = cur->from;
        Node *to = cur->to;
        cout << "Deal with the edge:" << cur->weight << ",\t";
        if (!unionFind.isSameSet(from, to))
        {
            cout << "the two nodes belongs to different set." << endl;
            ansSet.insert(cur);
            unionFind.mergeSet(from, to);
        }
    }
    return ansSet;
}

 */