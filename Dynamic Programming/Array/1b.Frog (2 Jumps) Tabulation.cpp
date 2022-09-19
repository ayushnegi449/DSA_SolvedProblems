#include <bits/stdc++.h>
using namespace std;

int solve(int jumps[], int n)
{
    vector<int> dp(n + 1, 0);

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int l = dp[i - 1] + abs(jumps[i] - jumps[i - 1]);
        int r = INT_MAX;
        if (i > 1)
        {
            r = dp[i - 2] + abs(jumps[i] - jumps[i - 2]);
        }
  
        dp[i] = min(l, r);
    }

    return dp[n-1];
}

int main()
{
    int size;
    cin >> size;

    int jumps[size];
    for (int i = 0; i < size; i++)
    {
        cin >> jumps[i];
    }

    cout << solve(jumps, size);

    return 0;
}