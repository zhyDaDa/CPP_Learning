#include <bits/stdc++.h>
using namespace std;

/*时间复杂度为n*2^n, 朴素想法, 用二叉树递归翻转或不翻转两种情况*/
/*
class Solution
{
private:
    vector<int> fs;
    vector<int> bs;
    int n;
    int ans = 2001;
    void swap(int &a, int &b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    void check(){
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            s.insert(fs[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (!s.count(bs[i]))
            {
                ans = ans < bs[i] ? ans : bs[i];
            }
        }
    }
    void process(int x)
    {
        if (x == n)
        {
            check();
            return;
        }
        process(x + 1);
        if (fs[x] != bs[x])
        {
            swap(fs[x], bs[x]);
            process(x + 1);
        }
    }

public:
    int flipgame(vector<int> &fronts, vector<int> &backs)
    {
        n = fronts.size();
        fs = fronts;
        bs = backs;
        process(0);
        return ans == 2001 ? 0 : ans;
    }
};
*/


/* 分析得解, 先排序, 从小到大看, 只要没有正反一样的就对 */
class Sort
{
public:
    void swap(int arr[], int a, int b)
    {
        if (a == b)
            return;
        arr[a] = arr[a] ^ arr[b];
        arr[b] = arr[a] ^ arr[b];
        arr[a] = arr[a] ^ arr[b];
    }

    void partition(int arr[], int L, int R, int returnArray[])
    {
        swap(arr, L + (int)(rand() % (R - L + 1)), R);
        int less = L - 1, more = R - 1;
        int i = L;
        while (i <= more)
        {
            if (arr[i] < arr[R])
            {
                swap(arr, i++, ++less);
            }
            else if (arr[i] > arr[R])
            {
                swap(arr, i, more--);
            }
            else
            {
                i++;
            }
        }
        swap(arr, R, ++more);

        returnArray[0] = less + 1;
        returnArray[1] = more;
    }

    void quickSort(int arr[], int L, int R)
    {
        if (L < R)
        {
            int mid[2];
            partition(arr, L, R, mid);
            quickSort(arr, L, mid[0] - 1);
            quickSort(arr, mid[1] + 1, R);
        }
    }
};

class Solution
{
public:
    int flipgame(vector<int> &fronts, vector<int> &backs)
    {
        int n = fronts.size();
        vector<int> arr(n * 2);
        // merge
        for (int i = 0; i < n; i++)
        {
            arr[i] = fronts[i];
            arr[i + n] = backs[i];
        }
        // sort
        Sort sort;
        sort.quickSort(&arr[0], 0, n * 2 - 1);
        int i = 0;
        int cur = arr[0];
        while (i < n * 2)
        {
            cur = arr[i];
            bool flag = true;
            for (int j = 0; j < n; j++)
            {
                if (fronts[j] ==cur&& backs[j]==cur)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                return cur;
            }
            while ((++i) < n * 2 && arr[i] == cur)
                ;
        }
        return 0;
    }
};