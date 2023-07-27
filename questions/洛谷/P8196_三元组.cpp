// #include <iostream>
// #include <vector>
// #include <unordered_set>
// using namespace std;

// int main()
// {
//     int turn;
//     cin >> turn;
//     for (int t = 0; t < turn; t++)
//     {
//         int n;
//         cin >> n;
//         vector<int> nums(n);
//         unordered_set<int> set;
//         for (int i = 0; i < n; i++)
//         {
//             cin >> nums[i];
//             set.insert(nums[i]);
//         }

//         int ans = 0;

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = i; j < n; j++)
//             {
//                 if (set.count(nums[i] + nums[j]))
//                     ans++;
//             }
//         }

//         cout << ans << endl;
//     }
// }

/*
# [传智杯 #4 决赛] 三元组

## 题目描述

给定一个长度为 $n$ 的数列 $a$，对于一个有序整数三元组 $(i, j, k)$，若其满足 $1 \leq i \leq j \leq k \leq n$ 并且 $a_i +a_j  = a_k$，则我们称这个三元组是「传智的」。

现在请你计算，有多少有序整数三元组是传智的。

## 输入格式

**本题单测试点内有多组测试数据**。

输入的第一行是一个整数 $T$，表示数据组数。

对于每组数据：

第一行是一个整数，表示数列的长度 $n$。
第二行有 $n$ 个整数，第 $i$ 个整数表示 $a_i$。

## 输出格式

对于每组数据，输出一行一个整数表示答案。

## 样例 #1

### 样例输入 #1

```
2
3
1 2 3
5
1 2 3 4 5
```

### 样例输出 #1

```
2
6
```

## 提示

### 样例 1 解释

对于第一组数据，因为 $a_1 + a_1 = a_2$，$a_1 + a_2 = a_3$，故共 $(1, 1, 2)$ 和 $(1, 2, 3)$ 两个三元组。
对于第二组数据六个三元组分别是：
- $(1, 1, 2)$
- $(1, 2, 3)$
- $(1, 3, 4)$
- $(1, 4, 5)$
- $(2, 2, 4)$
- $(2, 3, 5)$

### 数据规模与约定

对于全部测试点，保证 $1 \leq T \leq 100$，$1 \leq n , a_i \leq 100$，且各个测试点的 $n$ 之和不超过 $100$，即 $\sum n \leq 100$。 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    int turn;
    cin >> turn;
    for (int t = 0; t < turn; ++t)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        unordered_set<int> hashset;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            hashset.insert(a[i]);
        }
        int result = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                if (hashset.find(a[i] + a[j]) != hashset.end())
                {
                    ++result;
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}