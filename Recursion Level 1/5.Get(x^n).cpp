#include <bits/stdc++.h>
using namespace std;

int power(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }

    int r = power(x, n / 2);
    int x2 = r * r;
    if (n % 2 != 0)
    {
        x2 = x2 * x;
    }
    return x2;
}

int main()
{
    int n, x;
    cout << "enter number :";
    cin >> x;
    cout << "enter power :";
    cin >> n;
    int res = power(x, n);
    cout << res;
    return 0;
}