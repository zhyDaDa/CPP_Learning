#include <bits/stdc++.h>
using namespace std;

class Solution1
{
    int len;
    bool process(string &start, string &target)
    {
        if (start == target)
            return true;
        bool res = false;
        if (start[0] == 'R' && start[1] == '_')
        {
            start[0] = '_';
            start[1] = 'R';
            res = res || process(start, target);
            start[0] = 'R';
            start[1] = '_';
        }
        for (int i = 1; i < len - 1; i++)
        {
            if (start[i] == 'L' && start[i - 1] == '_')
            {
                start[i - 1] = 'L';
                start[i] = '_';
                res = res || process(start, target);
                start[i - 1] = '_';
                start[i] = 'L';
            }
            if (start[i] == 'R' && start[i + 1] == '_')
            {
                start[i + 1] = 'R';
                start[i] = '_';
                res = res || process(start, target);
                start[i + 1] = '_';
                start[i] = 'R';
            }
        }
        if (start[len - 1] == 'L' && start[len - 2] == '_')
        {
            start[len - 1] = '_';
            start[len - 2] = 'L';
            res = res || process(start, target);
            start[len - 1] = 'L';
            start[len - 2] = '_';
        }
        return res;
    }

public:
    bool canChange(string start, string target)
    {
        len = start.size();
        return process(start, target);
    }
};

class Solution2
{
public:
    bool canChange(string start, string target)
    {
        int len = start.size();
        int i = 0;
        int j = 0;
        while (true)
        {
            while (i < len && start[i] == '_')
                i++;
            while (j < len && target[j] == '_')
                j++;
            if (i >= len || j >= len)
                return i == len && j == len;
            if (start[i] != target[j] || (start[i] == 'L' && j > i) || (start[i] == 'R' && i > j))
                return false;
            i++;
            j++;
        }
    }
};

class Solution3
{
    int arr1[3125];
    int arr2[3125];
    void record1(int index, bool isR)
    {
        int arrIndex = index / 32;
        int bitIndex = index % 32;
        if (isR)
            arr1[arrIndex] |= 1 << bitIndex;
        else
            arr1[arrIndex] &= ~(1 << bitIndex);
    }
    void record2(int index, bool isR)
    {
        int arrIndex = index / 32;
        int bitIndex = index % 32;
        if (isR)
            arr2[arrIndex] |= 1 << bitIndex;
        else
            arr2[arrIndex] &= ~(1 << bitIndex);
    }

public:
    bool canChange(string start, string target)
    {
        int len = start.size();
        for (int i = 0, j = 0; i < len; i++)
        {
            if (start[i] != '_')
            {
                record1(j++, start[i] == 'R');
            }
        }
        for (int i = 0, j = 0; i < len; i++)
        {
            if (target[i] != '_')
            {
                record2(j++, target[i] == 'R');
            }
        }
        for (int i = 0; i < 3125; i++)
        {
            if (arr1[i] != arr2[i])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution3 s;
    cout << s.canChange("_L__R__R_L", "L______RR_");
}