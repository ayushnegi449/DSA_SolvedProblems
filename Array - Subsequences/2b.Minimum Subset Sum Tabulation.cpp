#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int sum, int n)
{
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    if (sum >= arr[0])
    {
        dp[0][arr[0]] = true;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            bool nottake = dp[i - 1][j];

            bool take = false;

            if (j >= arr[i])
            {
                take += dp[i - 1][j - arr[i]];
            }

            dp[i][j] = nottake || take;
        }
    }

    int minval = INT_MAX;

    for (int j = 0; j <= sum/2  ; j++)
    {
        if (dp[n - 1][j] == true)
        {
            minval = min(minval, abs(sum - (2 * j)));
        }
    }

    return minval;
}

int main()
{
    int n, sum = 0;
    cin >> n;

    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    cout << "Min diff is : " << solve(arr, sum, n);

    return 0;
}