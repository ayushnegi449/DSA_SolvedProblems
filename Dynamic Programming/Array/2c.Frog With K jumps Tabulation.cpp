#include <bits/stdc++.h>
using namespace std;

int solve(int jump[], int idx, int k)
{
    int dp[idx + 2];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= idx; i++)
    {
        int minval = INT_MAX;

        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int v = dp[i - j] + abs(jump[idx] - jump[idx - j]);

                minval = min(v, minval);
            }
        }
        
        dp[i] = minval;
    }

    return dp[idx];
}

int main()
{
    int size, jump;
    cin >> size >> jump;

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << solve(arr, size - 1, jump);

    return 0;
}