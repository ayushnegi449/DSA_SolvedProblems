#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> coins, int idx, int V, vector<vector<int>> dp)
{
    for(int j =0 ;j<V+1;j++)
    {
        dp[0][j] = INT_MAX -100;
    }

    if(coins[0]<=V)
    {
        dp[0][coins[0]] = 1;
    }

    for(int i =1;i<idx;i++)
    {
        for(int j = 1 ; j<V+1;j++)
        {
            int nottake = dp[i-1][j];

            int take = INT_MAX-100;

            if(j>= coins[i])
            {
                take = 1+ dp[i][j-coins[i]];
            }

            dp[i][j] = min(take,nottake);
        }
    }

    return dp[idx-1][V];

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

    vector<vector<int>> dp(n, vector<int>(Change + 1, 0));

    cout << "minimum coins required : " << solve(coins, n, Change, dp);
}