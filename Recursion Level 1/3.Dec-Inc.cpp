#include <bits/stdc++.h>
using namespace std;

void pdec_inc(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << "\n"
         << n;
    pdec_inc(n - 1);
    cout << "\n"
         << n;
}

int main()
{
    int dec;
    cout << "enter number to dec then increase:";
    cin >> dec;
    pdec_inc(dec);
    return 0;
}