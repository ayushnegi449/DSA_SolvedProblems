#include <bits/stdc++.h>
using namespace std;

void printdec(int n)
{
    if(n==0)
    {
        return;
    }
    cout << n << " ";
    printdec(n - 1);
 
}

int main()
{
    int dec;
    cout << "enter number to dec:";
    cin >> dec;
    printdec(dec);
    return 0;
}