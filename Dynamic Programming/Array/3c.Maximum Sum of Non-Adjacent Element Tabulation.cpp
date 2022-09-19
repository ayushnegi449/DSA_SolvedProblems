#include <bits/stdc++.h>
using namespace std;

int solve(int house[], int n, int dp[])
{
    dp[0] = house[0];

    for (int i = 1; i <= n; i++)
    {
        int pick = 0;
        if(i==1)
        {
            pick = house[i];

        }
        if (i > 1)
        {
            pick = house[i] + dp[i - 2];
        }
        
        int notpick = dp[i - 1];

        dp[i] = max(pick, notpick);
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int dp[n + 1];
    memset(dp, -1, sizeof(dp));

    cout << solve(arr, n - 1, dp);

    return 0;
}
