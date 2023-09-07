#include <bits/stdc++.h>
using namespace std;

int const factorial[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int const dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int visited[1000001];
int start[9];
int target[] = {1, 2, 3, 8, 0, 4, 7, 6, 5};

struct Sitution
{
public:
    int sit[9];
    int step;
};

bool cantor(int sit[9])
{
    int ans = 0;
    for (int i = 0; i < 9; i++)
    {
        int cnt = 0;
        for (int j = i + 1; j < 9; j++)
            if (sit[j] < sit[i])
                cnt++;
        ans += cnt * factorial[8 - i];
    }
    if (visited[ans])
        return false;
    else
    {
        visited[ans] = 1;
        return true;
    }
}

int bfs()
{
    queue<Sitution> q;
    Sitution startS;
    memcpy(startS.sit, start, sizeof(start));
    startS.step = 0;
    q.push(startS);
    cantor(startS.sit);
    while (!q.empty())
    {
        Sitution now = q.front();
        q.pop();
        int zero = -1;
        for (int i = 0; i < 9; i++)
        {
            if (now.sit[i] == 0)
            {
                zero = i;
                break;
            }
        }
        int x = zero / 3, y = zero % 3;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < 3 && ny < 3)
            {
                Sitution next = now;
                swap(next.sit[zero], next.sit[3 * nx + ny]);
                next.step++;
                if (cantor(next.sit))
                {
                    if (memcmp(next.sit, target, sizeof(target)) == 0)
                        return next.step;
                    q.push(next);
                }
            }
        }
    }
    return 0;
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        scanf("%1d", &start[i]);
    }
    if (memcmp(start, target, sizeof(start)) == 0)
    {
        printf("0");
        return 0;
    }
    printf("%d", bfs());
    return 0;
}