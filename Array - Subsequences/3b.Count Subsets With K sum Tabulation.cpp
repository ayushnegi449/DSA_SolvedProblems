#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int sum)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

    for (int i = 0; i < sum; i++)
    {
        if (arr[i] == 0)
        {
            dp[i][0] = 2;
        }
        else
        {
            dp[i][0] = 1;
        }
    }

    if (sum >= arr[0] && arr[0]!=0)
    {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            int nottake = dp[i - 1][j];
            
            int take = 0;

            if (j >= arr[i])
            {
                take = dp[i - 1][j - arr[i]];
            }

            dp[i][j] = take + nottake;
        }
    }

    return dp[n - 1][sum];
}

int main()
{
    int n, sum;
    cin >> n >> sum;

    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << solve(arr, sum);

    return 0;
}