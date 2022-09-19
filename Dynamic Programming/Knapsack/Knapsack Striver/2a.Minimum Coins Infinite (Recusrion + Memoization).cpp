#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> coins, int idx, int V, vector<vector<int>> dp)
{
    if (V == 0)
    {
        return 0;
    }
    if (idx == 0)
    {
        if (coins[0] == V)
        {
            return 1;
        }
        else
            return INT_MAX - 100;
    }

    if (dp[idx][V] != -1)
    {
        return dp[idx][V];
    }
    int nottake = solve(coins, idx - 1, V, dp);

    int take = INT_MAX;

    if (V >= coins[idx])
    {
        take = 1+solve(coins, idx, V - coins[idx], dp);
    }

    return dp[idx][V] = min(nottake, take);
}

int main()
{
    int n, Change;
    cin >> n >> Change;

    vector<int> coins(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    vector<vector<int>> dp(n, vector<int>(Change + 1, -1));

    cout << "minimum coins required : " << solve(coins, n - 1, Change, dp);
}