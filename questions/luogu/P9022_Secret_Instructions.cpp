#include <iostream>

using namespace std;

int main()
{
    int a;
    cin >> a;
    int lor = 0;
    while (a != 99999)
    {
        int b = a / 10000 + a / 1000 % 10;
        if (b != 0)
            lor = b % 2;
        cout << (lor ? "left " : "right ") << a % 1000 << endl;
        cin >> a;
    }
    return 0;
}