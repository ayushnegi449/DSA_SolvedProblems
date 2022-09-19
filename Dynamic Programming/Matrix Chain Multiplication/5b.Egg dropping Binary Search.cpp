#include <bits/stdc++.h>
using namespace std;
int dp[101][10001];

int solve(int e, int f, int dp[][10001])
{
    if (dp[e][f] != -1)
    {
        return dp[e][f];
    }

    if (e == 1)
    {
        return f;
    }
    if (f == 0 || f == 1)
    {
        return f;
    }

    int ans = INT_MAX;

    int left = 1;
    int right = f;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        int a = 0;
        int b = 0;

        if (dp[e - 1][mid - 1] != -1)
        {
            a = dp[e - 1][mid - 1];
        }
        else
        {
            a = solve(e - 1, mid - 1, dp);
            dp[e - 1][mid - 1] = a;
        }
        if (dp[e][f - mid] != -1)
        {
            b = dp[e][f - mid];
        }
        else
        {
            b = solve(e, f - mid, dp);
            dp[e][f - mid] = b;
        }

        int temp = 1 + max(a, b);

        if (a > b)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
        ans = min(ans, temp);
    }

    return dp[e][f] = ans;
}

int main()
{
    int e, f;
    cin >> e >> f;
    int dp[e + 1][10001];
    memset(dp, -1, sizeof(dp));
    cout << solve(e, f, dp);
}

