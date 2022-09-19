// Time Complexity: O(N*K)
// Reason: There are two nested loops

// Space Complexity: O(N*K)
// Reason: We are using an external array of size ‘N*K’. Stack Space is eliminated.

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int n, int sum, vector<vector<int>> &dp)
{
    for (int i = 0; i < n; i++)
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

    if (arr[0] != 0 && arr[0] <= sum)
    {
        dp[0][arr[0]] = 1;
    }

    for(int i =1;i<n;i++)
    {
        for(int j = 0;j<sum+1;j++)
        {
            int nottake = dp[i-1][j];
            int take = 0;

            if(j >= arr[i])
            {
                take = dp[i-1][j-arr[i]];
            }

            dp[i][j] = take+nottake;
        }
    }

   return dp[n-1][sum];
}

int main()
{
    int n, diff, sum = 0;
    cin >> n >> diff;

    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    int target = sum - diff;

    if ((target % 2 == 0) && sum >= diff)
    {
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        cout << solve(arr, n, target / 2, dp);
    }
    else
    {
        cout << "0 subsets possible";
    }

    return 0;
}
