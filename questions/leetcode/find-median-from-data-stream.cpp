#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
    struct min
    {
        bool operator()(int a, int b)
        {
            return a > b;
        }
    };
    struct max
    {
        bool operator()(int a, int b)
        {
            return a < b;
        }
    };

public:
    priority_queue<int, vector<int>, min> minPQ;
    priority_queue<int, vector<int>, max> maxPQ;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxPQ.empty() || num <= maxPQ.top())
        {
            maxPQ.push(num);
        }
        else
        {
            minPQ.push(num);
        }
        if (maxPQ.size() - minPQ.size() == 2)
        {
            minPQ.push(maxPQ.top());
            maxPQ.pop();
        }
        else if (minPQ.size() - maxPQ.size() == 2)
        {
            maxPQ.push(minPQ.top());
            minPQ.pop();
        }
    }

    double findMedian()
    {
        if (maxPQ.size() == minPQ.size())
        {
            return (maxPQ.top() + minPQ.top()) / 2.0;
        }
        else if (maxPQ.size() > minPQ.size())
        {
            return maxPQ.top();
        }
        else
        {
            return minPQ.top();
        }
    }
};