#include <bits/stdc++.h>
using namespace std;

int josephuskill(int n, int k)
{
    if (n == 1)
    {
        return 0;
    }
     
    int solution = josephuskill(n - 1, k);
    int y = (solution + k) % n;
    return y;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << josephuskill(n, k);
}