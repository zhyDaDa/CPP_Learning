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
};

int main()
{
    int arr[] = {6, 5, 4, 3, 2, 1};
    Solution solution;
    solution.selectionSort(arr, 1, 4);
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}