#include <bits/stdc++.h>
using namespace std;

int solve(int house[], int n, int dp[])
{
    if (n == 0)
    {
        return house[n];
    }
    if (n < 0)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int pick = house[n] + solve(house, n - 2,dp);
    int notpick = solve(house, n - 1,dp);

    return dp[n] = max(pick, notpick);
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
