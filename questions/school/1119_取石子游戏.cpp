#include <bits/stdc++.h>
using namespace std;

bool process(int a, int b)
{
    if (a < b)
        swap(a, b);

    if (a == b || a >= 2 * b)
    {
        return true;
    }
    else
        return !process(b, a - b);
}

int main()
{
    int a, b;
    while (true)
    {
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        cout << (process(a, b) ? "win" : "lose") << endl;
    }
}