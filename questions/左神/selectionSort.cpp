#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

class Solution
{
public:
    void selectionSort(int arr[], int L, int R)
    {
        for (int i = L; i < R; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j <= R; j++)
            {
                if (arr[j] < arr[minIndex])
                    minIndex = j;
            }
            if (minIndex != i)
                swap(arr[i], arr[minIndex]);
        }
    }

    void selectionSort_reverse(int arr[], int L, int R)
    {
        for (int i = L; i < R; i++)
        {
            int maxIndex = i;
            for (int j = i + 1; j <= R; j++)
            {
                if (arr[j] > arr[maxIndex])
                    maxIndex = j;
            }
            if (maxIndex != i)
                swap(arr[i], arr[maxIndex]);
        }
    }
};

int main()
{
    int arr[] = {99, 6, 1, 4, 2, 8, 5, 7, 6, 99};
    Solution solution;
    solution.selectionSort(arr, 1, 8);
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    solution.selectionSort_reverse(arr, 1, 8);
    for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}