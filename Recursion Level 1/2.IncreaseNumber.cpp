#include <bits/stdc++.h>
using namespace std;

void printdec(int n)
{
    if (n==0)
    {
        return;
    }
    printdec(n - 1);
    cout << n << " ";
}

int main()
{
    int dec;
    cout << "enter number to incease:";
    cin >> dec;
    printdec(dec);
    return 0;
}