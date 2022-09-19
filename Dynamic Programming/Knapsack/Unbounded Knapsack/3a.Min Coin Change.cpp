// Coin Change Problem Minimum Numbers of coins
// Given a value V, if we want to make change for V cents, and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins,
// what is the minimum number of coins to make the change?
// Example:

// Input: coins[] = {25, 10, 5}, V = 30
// Output: Minimum 2 coins required
// We can use one coin of 25 cents and one of 5 cents

#include <bits/stdc++.h>
using namespace std;

int coinChange(int n, int maxChange, vector<int> coins, vector<vector<int>> dp)
{
    // for (int j = 0; j < maxChange + 1; j++)
    // {
    //     dp[0][j] = INT_MAX - 1;
    // }

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < maxChange + 1; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 0;
            }
            if (i == 0)
            {
                dp[i][j] = INT_MAX - 1;
            }
        }
    }
    // for (int j = 1; j < maxChange + 1; j++)
    // {
    //     if (j % coins[0] == 0)
    //     {
    //         dp[1][j] = j / coins[0];
    //     }
    //     else
    //     {
    //         dp[1][j] = INT_MAX - 1;
    //     }
    // } just an extra step

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < maxChange + 1; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j]);
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

    vector<vector<int>> dp(n + 1, vector<int>(change + 1, 0));

    int counter = coinChange(n, change, coins, dp);
    cout << "Min coins required to get change of Rs." << change << " with given coins is : " << counter;

    return 0;
}