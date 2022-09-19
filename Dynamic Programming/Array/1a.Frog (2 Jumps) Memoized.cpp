#include <bits/stdc++.h>
using namespace std;

int solve(int jumps[], int idx, int dp[])
{
    if (idx == 0)
    {
        return 0;
    }
    
    if (dp[idx] != -1)
    {
        return dp[idx];
    }

    int jump1 = solve(jumps, idx - 1, dp) + abs(jumps[idx - 1] - jumps[idx]);

    int jump2 = INT_MAX;

    if (idx > 1)
    {
        jump2 = solve(jumps, idx - 2, dp) + abs(jumps[idx - 2] - jumps[idx]);
    }

    return dp[idx] = min(jump1, jump2);
}

int main()
{
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int dp[size + 1];
    memset(dp, -1, sizeof(dp));

    cout << solve(arr, size - 1, dp);

    return 0;
}