#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int idx, int sum, vector<vector<int>> &dp)
{
    // if (sum == 0)
    // return 1; fails for test case n = 4 , sum = 3 , arr = {0,0,3,3} ==> output 1.

    if (idx == 0)
    {
        if (sum == 0 && arr[idx] == 0)
        {
            return 2; // two options when we are at last index and 0 is there , i.e. take it or leave it.
        }
        if (sum == arr[idx])
        {
            return 1;
        }
        if (sum == 0)
        {
            return 1;
        }

        return 0;
    }

    if (dp[idx][sum] != -1)
    {
        return dp[idx][sum];
    }

    int nottake = solve(arr, idx - 1, sum, dp);

    int take = 0;

    if (sum >= arr[idx])
    {
        take = solve(arr, idx - 1, sum - arr[idx], dp);
    }

    return dp[idx][sum] = take + nottake;
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

    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    cout << solve(arr, n - 1, sum, dp);

    return 0;
}