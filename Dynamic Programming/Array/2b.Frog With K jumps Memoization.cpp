#include <bits/stdc++.h>
using namespace std;

int solve(int jump[], int idx, int dp[])
{
    if (idx == 0)
    {
        return 0;
    }

    if (dp[idx] != -1)
    {
        return dp[idx];
    }

    int minval = INT_MAX;

    for (int k = 1; k <= idx; k++)
    {
        int l = 0;

        if (idx - k >= 0)
        {
            l = solve(jump, idx - k, dp) + abs(jump[idx] - jump[idx - k]);

            if (l < minval)
            {
                minval = l;
            }
        }
    }

    return dp[idx] = minval;
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