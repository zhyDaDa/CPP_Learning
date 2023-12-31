/*
请把一段纸条竖着放在桌子上，然后从纸条的下边向上方对折 1 次，压出折痕后展开。
此时折痕是凹下去的，即折痕突起的方向指向纸条的背面如果从纸条的下边向上方连续对折 2 次，
压出折痕后展开，此时有三条折痕，从上到下依次是下折痕、下折痕和上折痕。

给定一个输入参数 N ，代表纸条都从下边向上方连续对折 N 次。
请从上到下打印所有折痕的方向。例如
N=I 时，打印， down
N = 2 时，打印， down down up */

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    void printProcess(int i, int N, bool down)
    {
        if (i > N)
        {
            return;
        }
        printProcess(i + 1, N, true);
        cout << (down ? "down" : "up") << endl;
        printProcess(i + 1, N, false);
    }

    void printAllFolds(int N)
    {
        printProcess(1, N, true);
    }
};

int main()
{
    Solution s;
    s.printAllFolds(4);
    return 0;
}