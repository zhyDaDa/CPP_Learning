#include <iostream>
#include <climits>
#include <iomanip>
#include <math.h>
using namespace std;

void printIntArray(int arr[], int L, int R)
{
    for (int i = L; i <= R; i++)
    {
        cout << setw(3) << setfill(' ') << arr[i] << " ";
    }
    cout << endl;
}

void printHr()
{
    for (int i = 0; i < 50; i++)
    {
        cout << "=";
    }
    cout << endl;
}

void swap(int arr[], int a, int b)
{
    if (a == b)
        return;
    arr[a] = arr[a] ^ arr[b];
    arr[b] = arr[a] ^ arr[b];
    arr[a] = arr[a] ^ arr[b];
}

class Solution
{
public:
    int maxBit(int arr[], int L, int R)
    {
        int max = arr[R];
        for (int i = L; i < R; i++)
        {
            max = arr[i] > max ? arr[i] : max;
        }
        int ans = 0;
        while (max != 0)
        {
            max /= 10;
            ans++;
        }
        return ans;
    }

    int getDigit(int x, int digit)
    {
        return x % (int)(pow(10, digit)) / (int)(pow(10, digit - 1));
    }

    void radixSort(int arr[], int L, int R, int digit)
    {
        // cout << digit << endl;
        const int radix = 10;
        int arr_cpy[R - L + 1];
        for (int d = 1; d <= digit; d++)
        {
            int count[radix] = {}; // 多少种数字
            // 统计该数位上各个数字出现的次数
            for (int i = L; i <= R; i++)
            {
                ++count[getDigit(arr[i], d)];
            }
            // printIntArray(count, 0, radix - 1);
            // 调整count, 改为小于等于出现的次数
            for (int i = 1; i < radix; i++)
            {
                count[i] += count[i - 1];
            }
            // printIntArray(count, 0, radix - 1);
            // 从右向左放置数字
            for (int i = R; i >= L; i--)
            {
                int j = getDigit(arr[i], d);
                arr_cpy[--count[j]] = arr[i];
            }
            // printIntArray(arr_cpy, L, R);
            // 复制回去
            for (int i = L; i <= R; i++)
            {
                arr[i] = arr_cpy[i - L];
            }
            // printIntArray(arr, L, R);
            // printHr();
        }
    }

    void bucketSort(int arr[], int L, int R)
    {
        if (arr == NULL || R <= L)
            return;
        radixSort(arr, L, R, maxBit(arr, L, R));
    }

    void radixSort_reverse(int arr[], int L, int R, int digit)
    {
        // cout << digit << endl;
        const int radix = 10;
        int arr_cpy[R - L + 1];
        for (int d = 1; d <= digit; d++)
        {
            int count[radix] = {}; // 多少种数字
            // 统计该数位上各个数字出现的次数
            for (int i = L; i <= R; i++)
            {
                ++count[getDigit(arr[i], d)];
            }
            // printIntArray(count, 0, radix - 1);
            // 调整count, 改为小于等于出现的次数
            for (int i = radix-2; i >=0; i--)
            {
                count[i] += count[i + 1];
            }
            // printIntArray(count, 0, radix - 1);
            // 从右向左放置数字
            for (int i = R; i >= L; i--)
            {
                int j = getDigit(arr[i], d);
                arr_cpy[--count[j]] = arr[i];
            }
            // printIntArray(arr_cpy, L, R);
            // 复制回去
            for (int i = L; i <= R; i++)
            {
                arr[i] = arr_cpy[i - L];
            }
            // printIntArray(arr, L, R);
            // printHr();
        }
    }

    void bucketSort_reverse(int arr[], int L, int R)
    {
        if (arr == NULL || R <= L)
            return;
        radixSort_reverse(arr, L, R, maxBit(arr, L, R));
    }


};

int main()
{
    int arr[] = {99, 6, 1, 4, 2, 8, 5, 7, 6, 199};
    int arrLen = sizeof(arr) / sizeof(*arr);
    Solution solution;
    solution.bucketSort(arr, 0, 9);
    printIntArray(arr, 0, arrLen - 1);
    solution.bucketSort_reverse(arr, 0, 9);
    printIntArray(arr, 0, arrLen - 1);
}