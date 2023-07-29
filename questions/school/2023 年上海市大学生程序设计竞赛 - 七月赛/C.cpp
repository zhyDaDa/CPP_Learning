#include <bits/stdc++.h>
using namespace std;

int n;
long int maxDiv;
bool pg[3002]; // people gender
int pd[3002];  // people diversity
int c1, c0;    // count of 1 and 0

// 记录上次计算结果和变化位置
long int lastDiv;
long int divRecord[3002];

// 利用先前记录往后计算
void calcDiv(int x)
{
    divRecord[x] = divRecord[x-1];
    if (pg[x] == pg[x / 2])
    {
        divRecord[x] += pd[x];
    }
}

void gD(int x)
{ // gender Divid
    if (x > n)
    {
        maxDiv = max(maxDiv, divRecord[n]);
        return;
    }
    if (c1 > 0)
    {
        pg[x] = 1;
        calcDiv(x);
        c1--;
        gD(x + 1);
        c1++;
    }
    if (c0 > 0)
    {
        pg[x] = 0;
        calcDiv(x);
        c0--;
        gD(x + 1);
        c0++;
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> pd[i];
    }
    c1 = c0 = n / 2;
    gD(1);
    cout << maxDiv << endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int n;
// long int maxDiv;
// bool pg[3002]; // people gender
// int pd[3002];  // people diversity
// int c1, c0;    // count of 1 and 0

// long int calcDiv()
// {
//     // 遍历pg数组, 对于第i个, 如果他和第i/2(向下取整)个bool相同, 则div+=pd[i]
//     // i从1到n
//     long int div = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         if (pg[i] == pg[i / 2])
//         {
//             div += pd[i];
//         }
//     }
//     return div;
// }

// void gD(int x)
// { // gender Divid
//     if (x > n)
//     {
//         // 检查中, 打印pg数组
//         // for (int i = 1; i <= n; i++)
//         // {
//         //     cout << pg[i] << " ";
//         // }
//         // cout << endl;
//         // 边界情况处理
//         maxDiv = max(maxDiv, calcDiv());
//         return;
//     }
//     if (c1>0)
//     {
//         pg[x] = 1;
//         c1--;
//         gD(x + 1);
//         c1++;
//     }
//     if (c0>0)
//     {
//         pg[x] = 0;
//         c0--;
//         gD(x + 1);
//         c0++;
//     }
// }

// int main()
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> pd[i];
//     }
//     c1 = c0 = n / 2;
//     gD(1);
//     cout << maxDiv << endl;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int n;
// long int maxDiv;
// bool pg[3002]; // people gender
// int pd[3002];  // people diversity
// stack<bool> s1;
// stack<bool> s0;

// long int calcDiv()
// {
//     // 遍历pg数组, 对于第i个, 如果他和第i/2(向下取整)个bool相同, 则div+=pd[i]
//     // i从1到n
//     long int div = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         if (pg[i] == pg[i / 2])
//         {
//             div += pd[i];
//         }
//     }
//     return div;
// }

// void gD(int x)
// { // gender Divid
//     if (x > n)
//     {
//         // 检查中, 打印pg数组
//         // for (int i = 1; i <= n; i++)
//         // {
//         //     cout << pg[i] << " ";
//         // }
//         // cout << endl;
//         // 边界情况处理
//         maxDiv = max(maxDiv, calcDiv());
//         return;
//     }
//     if (!s1.empty())
//     {
//         pg[x] = 1;
//         s1.pop();
//         gD(x + 1);
//         s1.push(1);
//     }
//     if (!s0.empty())
//     {
//         pg[x] = 0;
//         s0.pop();
//         gD(x + 1);
//         s0.push(0);
//     }
// }

// int main()
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> pd[i];
//     }
//     // 初始化s1和s0, 分别压入n/2个1和n/2个0
//     for (int i = 0; i < n / 2; i++)
//     {
//         s1.push(1);
//         s0.push(0);
//     }
//     gD(1);
//     cout << maxDiv << endl;
//     return 0;
// }