#include <bits/stdc++.h>
using namespace std;

// 暴力递归
class Solution1
{
public:
    vector<int> cards;
    int limit;
    int process(int L, int R, int left)
    {
        if (!left)
            return 0;
        return max(cards[L] + process(L + 1, R, left - 1), cards[R] + process(L, R - 1, left - 1));
    }
    int maxScore(vector<int> &cardPoints, int k)
    {

        cards = cardPoints;
        limit = k;
        return process(0, cards.size() - 1, k);
    }
};

// 滑动窗口
class Solution2
{
public:
    int minPoints = INT_MAX;

    int maxScore(vector<int> &cardPoints, int k)
    {
        int len = cardPoints.size();
        int windowSize = len - k;
        for (int i = 0; i <= k; i++)
        {
            int sum = 0;
            for (int j = i; j < i + windowSize; j++)
                sum += cardPoints[j % len];
            minPoints = min(minPoints, sum);
        }
        int sum = 0;
        for (auto i : cardPoints)
            sum += i;

        return sum - minPoints;
    }
};

// 滑动窗口PLUS
class Solution3
{
public:
    int minPoints = INT_MAX;

    int maxScore(vector<int> &cardPoints, int k)
    {
        int len = cardPoints.size();
        int windowSize = len - k;
        int window = 0;
        for (int i = 0; i < windowSize; i++)
        {
            window += cardPoints[i];
        }
        minPoints = window;
        for (int i = 1; i <= k; i++)
        {
            int L = cardPoints[i - 1];
            int R = cardPoints[i + windowSize - 1];
            window += R - L;
            if (R < L)
            {
                minPoints = min(minPoints, window);
            }
        }

        int sum = 0;
        for (auto i : cardPoints)
            sum += i;

        return sum - minPoints;
    }
};
