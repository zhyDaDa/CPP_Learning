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

    void bubbleSort_reverse(int arr[], int L, int R){
        for (int i = L; i < R;i++){
            for (int j = R; j > i;j--){
                if(arr[j]>arr[j-1])
                    swap(arr[j], arr[j - 1]);
            }
        }
    }
};

int main()
{
    int arr[] = {99, 6, 1, 4, 2, 8, 5, 7, 6, 99};
    Solution solution;
    solution.bubbleSort(arr, 1, 8);
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    solution.bubbleSort_reverse(arr, 1, 8);
    for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}