#include <iostream>
using namespace std;

class Solution
{
public:
    void swap(int &a, int &b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }

    void merge(int arr[], int L, int mid, int R)
    {
        int i = L;
        int j = mid + 1;
        int help[R - L + 1];
        int p = 0;
        while (i <= mid && j <= R)
        {
            help[p++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
        }
        while (i <= mid)
        {
            help[p++] = arr[i++];
        }
        while (j <= R)
        {
            help[p++] = arr[j++];
        }
        for (p = 0; p < R - L + 1; p++)
        {
            arr[L + p] = help[p];
        }
    }

    void mergeSort(int arr[], int L, int R)
    {
        if (L == R)
            return;
        int mid = L + ((R - L) >> 1);
        mergeSort(arr, L, mid);
        mergeSort(arr, mid + 1, R);
        merge(arr, L, mid, R);
    }

    void merge_reverse(int arr[], int L, int mid, int R)
    {
        int i = L;
        int j = mid + 1;
        int help[R - L + 1];
        int p = 0;
        while (i <= mid && j <= R)
        {
            help[p++] = arr[i] >= arr[j] ? arr[i++] : arr[j++];
        }
        while (i <= mid)
        {
            help[p++] = arr[i++];
        }
        while (j <= R)
        {
            help[p++] = arr[j++];
        }
        for (p = 0; p < R - L + 1; p++)
        {
            arr[L + p] = help[p];
        }
    }

    void mergeSort_reverse(int arr[], int L, int R)
    {
        if (L == R)
            return;
        int mid = L + ((R - L) >> 1);
        mergeSort_reverse(arr, L, mid);
        mergeSort_reverse(arr, mid + 1, R);
        merge_reverse(arr, L, mid, R);
    }
};

int main()
{
    int arr[] = {99, 6, 1, 4, 2, 8, 5, 7, 6, 99};
    Solution solution;
    solution.mergeSort(arr, 1, 8);
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    solution.mergeSort_reverse(arr, 1, 8);
    for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}