#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &wt, vector<int> &price, int idx, int W, vector<vector<int>> &dp)
{
    if (W == 0)
    {
        return 0;
    }
    if (idx == 0)
    {
        if (W >= wt[idx]) // idx = 0 here.
        {
            return price[0];
        }

        else
            return 0;
    }

    if (dp[idx][W] != -1)
    {
        return dp[idx][W];
    }

    int nottake = solve(wt, price, idx - 1, W, dp);

    int take = INT_MIN;

    if (W >= wt[idx])
    {
        take = price[idx] + solve(wt, price, idx - 1, W - wt[idx], dp);
    }

    return dp[idx][W] = max(take, nottake);
}

int main()
{
    int n, W;
    cin >> n>>W;

    vector<int> wt(n, 0), price(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> price[i];
    }

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));

    cout << "max price :  " << solve(wt, price, n - 1, W, dp);

    return 0;
}