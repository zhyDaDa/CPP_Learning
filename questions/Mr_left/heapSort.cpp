#include <iostream>
#include <iomanip>
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
    void heapInsert(int arr[], int L, int insert)
    {
        // int cur = arr[insert];
        // int father = arr[(insert - L - 1) / 2+L];
        while (arr[insert] > arr[(insert - L - 1) / 2 + L])
        {
            swap(arr, insert, (insert - L - 1) / 2 + L);
            insert = (insert - L - 1) / 2 + L;
        }
    }

    void heapify(int arr[], int L, int R, int index)
    {
        // 和两个比较, 如果大孩子比自己大, 往下走, 直到两个孩子都比自己小
        int child1 = (index - L << 1) + 1 + L;

        while (child1 <= R)
        {
            int big = (child1 + 1) > R || arr[child1] > arr[(child1 + 1)] ? child1 : (child1 + 1);
            big = arr[index] > arr[big] ? index : big;
            if (index == big)
                break;
            swap(arr, index, big);
            index = big;
            child1 = (index - L << 1) + 1 + L;
        }
    }

    void heapSort(int arr[], int L, int R)
    {
        if (arr == NULL || R <= L)
            return;
        // 先将数组转化为大根堆
        for (int i = L + 1; i <= R; i++)
        {
            // 末位的数向上比对, 直至合适的位置
            heapInsert(arr, L, i);
        }
        swap(arr, L, R--);
        while (R > L)
        {
            // printIntArray(arr, L, R);
            // 整理一下, 取走一个
            heapify(arr, L, R, L);
            // printIntArray(arr, L, R);
            swap(arr, L, R--);
        }
    }

    void heapInsert_reverse(int arr[], int L, int insert)
    {
        // int cur = arr[insert];
        // int father = arr[(insert - L - 1) / 2+L];
        while (arr[insert] < arr[(insert - L - 1) / 2 + L])
        {
            swap(arr, insert, (insert - L - 1) / 2 + L);
            insert = (insert - L - 1) / 2 + L;
        }
    }

    void heapify_reverse(int arr[], int L, int R, int index)
    {
        // 和两个比较, 如果大孩子比自己大, 往下走, 直到两个孩子都比自己小
        int child1 = (index - L << 1) + 1 + L;

        while (child1 <= R)
        {
            int small = (child1 + 1) > R || arr[child1] < arr[(child1 + 1)] ? child1 : (child1 + 1);
            small = arr[index] < arr[small] ? index : small;
            if (index == small)
                break;
            swap(arr, index, small);
            index = small;
            child1 = (index - L << 1) + 1 + L;
        }
    }

    void heapSort_reverse(int arr[], int L, int R)
    {
        if (arr == NULL || R <= L)
            return;
        // 先将数组转化为小根堆
        for (int i = L + 1; i <= R; i++)
        {
            // 末位的数向上比对, 直至合适的位置
            heapInsert_reverse(arr, L, i);
        }
        swap(arr, L, R--);
        while (R > L)
        {
            // printIntArray(arr, L, R);
            // 整理一下, 取走一个
            heapify_reverse(arr, L, R, L);
            // printIntArray(arr, L, R);
            swap(arr, L, R--);
        }
    }
};

int main()
{
    int arr[] = {99, 6, 1, 4, 2, 8, 5, 7, 6, 99};
    int arrLen = sizeof(arr) / sizeof(*arr);
    Solution solution;
    solution.heapSort(arr, 1, 8);
    printIntArray(arr, 0, arrLen - 1);
    solution.heapSort_reverse(arr, 1, 8);
    printIntArray(arr, 0, arrLen - 1);
}