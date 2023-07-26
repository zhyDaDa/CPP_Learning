#include <iostream>
using namespace std;

int main()
{
    int k;
    cin >> k;
    int n = 1;
    double sn = 1.0;
    while ((int)(sn += 1.0 / (++n)) < k)
    {
        // cout << n << ": " << sn << endl;
    }
    cout << n;
    return 0;
}