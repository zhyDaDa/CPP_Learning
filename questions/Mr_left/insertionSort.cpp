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
    void insertionSort(int arr[], int L, int R){
        for (int i = L + 1; i <= R;i++){
            for (int j = i; arr[j] < arr[j - 1] && j > L;j--){
                swap(arr[j], arr[j - 1]);
            }
        }
    }

    void insertionSort_reverse(int arr[], int L, int R){
        for (int i = L + 1; i <= R;i++){
            for (int j = i; arr[j] > arr[j - 1] && j > L;j--){
                swap(arr[j], arr[j - 1]);
            }
        }
    }
};

int main()
{
    int arr[] = {99, 6, 1, 4, 2, 8, 5, 7, 6, 99};
    Solution solution;
    solution.insertionSort(arr, 1, 8);
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    solution.insertionSort_reverse(arr, 1, 8);
    for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}