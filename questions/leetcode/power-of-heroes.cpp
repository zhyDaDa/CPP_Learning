#include <bits/stdc++.h>
using namespace std;

class Sort
{
public:
    void swap(vector<int> &arr, int a, int b)
    {
        if (a == b)
            return;
        arr[a] = arr[a] ^ arr[b];
        arr[b] = arr[a] ^ arr[b];
        arr[a] = arr[a] ^ arr[b];
    }

    void partition(vector<int> &arr, int L, int R, int returnArray[])
    {
        swap(arr, L + (int)(rand() % (R - L + 1)), R);
        // cout << setw(4) << L
        //      << setw(4) << R << endl;
        // printIntArray(arr, 1, 8);
        int less = L - 1, more = R - 1;
        int i = L;
        while (i <= more)
        {
            // cout << i << ":";
            // printIntArray(arr, 1, 8);
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
        // cout << setw(4) << L
        //      << setw(4) << less
        //      << setw(4) << more
        //      << setw(4) << R << endl;
        // printIntArray(arr, 1, 8);
        // printHr();
    }

    void quickSort(vector<int> &arr, int L, int R)
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
    vector<int> nums;
    int mod = 1000000007;
    int calcPow(int i, int j)
    {
        if (i == j)
            return (int)((long long)(nums[i] * nums[i] % mod) * nums[i] % mod);
        return (int)(((long long)((long long)(pow(nums[j], 2)) % mod * (long long)((long long)pow(2, j - i - 1) % mod)) % mod * nums[i]) % mod);
    }

public:
    int sumOfPower(vector<int> &nums)
    {
        Sort sort;
        int len = nums.size();
        long long ans = 0;
        sort.quickSort(nums, 0, len - 1);
        this->nums = nums;
        // print nums
        // for (int i = 0; i < len; i++)
        // {
        //     cout << nums[i] << " ";
        // }
        // cout << endl;
        for (int i = 0; i < len; i++)
        {
            for (int j = i; j < len; j++)
            {
                ans = calcPow(i, j) % mod + ans;
                ans %= mod;
            }
        }
        return (int)ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 1, 4};
    cout << s.sumOfPower(nums) << endl;
    return 0;
}