#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    n *= factorial(n - 1);
    return n;
}

int main()
{
    int n;
    cout << "enter number :";
    cin >> n;
    int res = factorial(n);
    cout<<"Factorial of "<<n<<" is : "<<res;
    return 0;
}