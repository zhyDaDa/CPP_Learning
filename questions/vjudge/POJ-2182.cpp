#include <stdio.h>
using namespace std;

// 暴力解法
int main1()
{
    const int MAX = 8005;
    int pre[MAX];
    int ans[MAX];
    bool num[MAX];
    int N;
    scanf("%d", &N);
    pre[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        scanf("%d", pre + i);
    }
    for (int i = N; i >= 1; i--)
    { // determine the i th
        int k = 0;
        for (int j = 1; j <= N; j++)
        {
            if (!num[j])
            {
                k++;
                if (k == pre[i] + 1)
                {
                    ans[i] = j;
                    num[j] = true;
                }
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        printf("%d\n", ans[i]);
    }
}

// 线段树二分查找
const int MAX = 10000;
struct node
{
    int l, r, len;
} tree[4 * MAX];

void buildTree(int L, int R, int u)
{
    tree[u].l = L;
    tree[u].r = R;
    tree[u].len = R - L + 1;
    if (L == R)
        return;
    buildTree(L, (L + ((R - L) >> 1)), u << 1);
    buildTree((L + ((R - L) >> 1) + 1), R, (u << 1) + 1);
}
int query(int u, int num)
{
    tree[u].len--;
    if (tree[u].l == tree[u].r)
        return tree[u].l;
    if (tree[(u << 1)].len >= num)
        query(u << 1, num);
    else
        query((u << 1) + 1, num - tree[(u << 1)].len);
}
int main()
{
    int pre[MAX];
    int ans[MAX];
    bool num[MAX];
    int N;
    scanf("%d", &N);
    pre[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        scanf("%d", pre + i);
    }
    buildTree(1, N, 1);
    for (int i = N; i >= 1; i--)
    {
        ans[i] = query(1, pre[i] + 1);
    }
    for (int i = 1; i <= N; i++)
    {
        printf("%d\n", ans[i]);
    }
}