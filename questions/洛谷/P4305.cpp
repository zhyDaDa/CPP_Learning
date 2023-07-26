/*
# [JLOI2011] 不重复数字

## 题目描述

给定 $n$ 个数，要求把其中重复的去掉，只保留第一次出现的数。

## 输入格式

**本题有多组数据。**

第一行一个整数 $T$，表示数据组数。

对于每组数据：

第一行一个整数 $n$。

第二行 $n$ 个数，表示给定的数。

## 输出格式

对于每组数据，输出一行，为去重后剩下的数，两个数之间用一个空格隔开。

## 样例 #1

### 样例输入 #1

```
2
11
1 2 18 3 3 19 2 3 6 5 4
6
1 2 3 4 5 6
```

### 样例输出 #1

```
1 2 18 3 19 6 5 4
1 2 3 4 5 6
```

## 提示

对于 $30\%$ 的数据，$n \le 100$，给出的数 $\in [0, 100]$。

对于 $60\%$ 的数据，$n \le 10^4$，给出的数 $\in [0, 10^4]$。

对于 $100\%$ 的数据，$1 \le T\le 50$，$1 \le n \le 5 \times 10^4$，给出的数在 $32$ 位有符号整数范围内。
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int deletRepeatedNums(vector<int> &nums)
    {
        unordered_set<int> set;
        for (auto item : nums)
        {
            if (set.count(item) == 0){

            set.insert(item);
            cout << item<<" ";
            }
        }
        cout << endl;
    }
};

int main(){
    Solution solution;
    int T = 0;
    cin >> T;
    for (int t = 0; t < T;t++){
        int n;
        int num;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> nums[i];
        }
        solution.deletRepeatedNums(nums);
    }

    return 0;
}