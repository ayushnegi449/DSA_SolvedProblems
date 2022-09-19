// Coin Change Problem Maximum Number of ways
// Given a value N, if we want to make change for N cents, and we have infinite supply of each of 
// S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.

// Example:
// for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4.

#include <bits/stdc++.h>
using namespace std;

int coinChange(int n, int maxChange, vector<int> coins, vector<vector<int>> dp)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < maxChange + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            if (j == 0)
            {
                dp[i][j] = 1;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < maxChange + 1; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][maxChange];
}

int main()
{
    int n, change;
    cin >> n >> change;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(change + 1, -1));

    int counter = coinChange(n, change, coins, dp);
    cout << "No of times you can get a change of Rs." << change << " with given coins is : " << counter;

    return 0;
}