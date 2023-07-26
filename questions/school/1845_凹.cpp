#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    int ans = 0;
    for (int i = 0; i < n-1; i++)
    {
        ans++;
        int maxIndex = i + 1;
        for (int j = i+2; j < n && array[maxIndex]<array[i]; j++)
        {
            if(array[j]>array[maxIndex]){
                ans++;
                maxIndex = j;
            }            
        }
        
    }

    cout << ans;
    return 0;
}