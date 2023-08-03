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

int main()
{
    vector<vector<int>> matrix = {
        {1, 1, 2},
        {2, 1, 3},
        {3, 2, 3},
        {4, 2, 4},
        {5, 3, 5},
        {6, 3, 6},
        // {7, 5, 2},
    };
    Graph *g = createGraph(matrix);
    // BFS(g->nodes[1]);
    // DFS(g->nodes[1]);
    vector<Node *> v = sortedTopology(g);
    cout << v.size() << endl;
    for (auto i : v)
    {
        cout << i->value << " ";
    }
    cout << endl;
}