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
    void bubbleSort(int arr[], int L, int R)
    {
        for (int i = R; i > L; i--)
        {
            for (int j = L; j < i; j++)
            {
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
            }
        }
    }
};

int main()
{
    int arr[] = {6, 5, 4, 3, 2, 1};
    Solution solution;
    solution.bubbleSort(arr, 1, 4);
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]);i++){
        cout << arr[i]<<" ";
    }
    cout << endl;
}