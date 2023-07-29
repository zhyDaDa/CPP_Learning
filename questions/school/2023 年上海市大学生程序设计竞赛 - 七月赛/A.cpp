/* 有
 只狗吃骨头，共有
 (
 未知) 根骨头，且
 不是
 的倍数。把所有
 只狗编号
。

第
 只狗偷偷跑过去，吃了一根骨头，然后发现剩下的骨头数量非 0 且恰好能等分成
 份，于是又吃掉了其中一份(=剩余总数的

 )后离开。
第
 只狗也跑过去吃了一根，又发现剩下的骨头数量非 0 且也能恰好等分成
 份，于是又吃掉了其中一份(=剩余总数的

 )后离开。
以此类推，第
 只狗吃掉一根后，会发现剩下的骨头的数量非 0 且是
 的倍数，于是又吃掉了其中一份(=剩余总数的

 )后离开。
最后一只狗吃掉一根后，会发现剩下的骨头的数量非 0 且是
 的倍数，于是又吃掉了一份。
如果要让
 只狗全部按照上述规律(ie. 先吃一根，再吃一份)吃骨头，则该堆骨头至少有多少根？答案对 998244353 取模。

输入格式
一行一个整数

输出格式
一行一个整数
，如题目描述 */

// #include <bits/stdc++.h>
// using namespace std;

// int m;
// int boneCount;
// void getBoneCount(int x)
// {
//     if (x > m){
//         // 边界情况处理
//     }
//     while (boneCount % (m-1) != 0)
//     {
//         boneCount+=m;
//     }
    
//     boneCount = boneCount / (m-1) * m + 1;
// }

// int main()
// {
//     cin >> m;
//     boneCount = m-1;
//     getBoneCount(1);
// }

#include <iostream>

using namespace std;

int main()
{
    int m;
    cin >> m;

    long long n = 0;
    long long power = 1;

    for (int i = 1; i <= m; i++)
    {
        power = (power * (m - 1)) % 998244353;
        n = (n + power) % 998244353;
    }

    cout << n << endl;

    return 0;
}
