#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &wt, vector<int> &price, int idx, int W, vector<vector<int>> &dp)
{
    for (int j = wt[0]; j <= W; j++)
    {
        dp[0][j] = price[0];
    }

    for (int i = 1; i < idx; i++)
    {
        for (int j = 1; j < W+1; j++)
        {
            int nottake = dp[i - 1][j];

            int take = 0;

            if (j >= wt[i])
            {
                take = price[i] + dp[i - 1][j - wt[i]];
            }

            dp[i][j] = max(take, nottake);
        }
    }

    return dp[idx - 1][W];
}

int main()
{
    int n, W;
    cin >> n >> W;

    vector<int> wt(n, 0), price(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> price[i];
    }

    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    cout << "max price :  " << solve(wt, price, n, W, dp);

    return 0;
}