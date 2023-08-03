#include <iostream>
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

class Solution
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

    void partition_reverse(int arr[], int L, int R, int returnArray[])
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
            if (arr[i] > arr[R])
            {
                swap(arr, i++, ++less);
            }
            else if (arr[i] < arr[R])
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

    void quickSort_reverse(int arr[], int L, int R)
    {
        if (L < R)
        {
            int mid[2];
            partition_reverse(arr, L, R, mid);
            quickSort_reverse(arr, L, mid[0] - 1);
            quickSort_reverse(arr, mid[1] + 1, R);
        }
    }
};

int main()
{
    int arr[] = {99, 6, 1, 4, 2, 8, 5, 7, 6, 99};
    int arrLen = sizeof(arr) / sizeof(*arr);
    Solution solution;
    solution.quickSort(arr, 1, 8);
    printIntArray(arr, 0, arrLen - 1);
    solution.quickSort_reverse(arr, 1, 8);
    printIntArray(arr, 0, arrLen - 1);
}