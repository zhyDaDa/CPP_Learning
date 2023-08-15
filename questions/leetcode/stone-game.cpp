#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstHand(vector<int> &piles, int i, int j)
    {
        if (i == j)
            return piles[i];
        else
            return max(piles[i] + secondHand(piles, i + 1, j), piles[j] + secondHand(piles, i, j - 1));
    }
    int secondHand(vector<int> &piles, int i, int j)
    {
        if (i == j)
            return 0;
        else
            return min(firstHand(piles, i + 1, j), firstHand(piles, i, j - 1));
    }
    bool stoneGame(vector<int> &piles)
    {
        int len = piles.size();
        int sum = 0;
        for (auto i : piles)
            sum += i;
        return firstHand(piles, 0, len - 1) > (sum >> 1);
    }
};