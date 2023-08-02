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

void inOrderPrintGraph(Node *root)
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

        for (int i = 0; i < cur->nexts.size(); i++)
        {
            if (!s.count(cur->nexts[i]))
            {
                q.push(cur->nexts[i]);
                s.insert(cur->nexts[i]);
            }
        }
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> matrix = {
        {3, 1, 2},
        {5, 1, 3},
        {1, 2, 3},
        {7, 2, 4},
        {4, 3, 5},
        {2, 3, 6},
        {6, 5, 2}};
    Graph *g = createGraph(matrix);
    inOrderPrintGraph(g->nodes[1]);
}