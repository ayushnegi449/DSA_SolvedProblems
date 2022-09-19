#include <bits/stdc++.h>
using namespace std;

void pzz(int n)
{
    if (n == 0)
    {
        return;
    }

    cout << "\nPre" << n;
    pzz(n - 1);
    cout << "\nIn" << n;
    pzz(n - 1);
    cout << "\nPost" << n;
}

int main()
{
    int n;
    cout << "enter the pattern number : ";
    cin >> n;
    pzz(n);
    return 0;
}