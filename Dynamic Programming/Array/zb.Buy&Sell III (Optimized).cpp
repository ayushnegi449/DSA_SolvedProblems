//* 123. Best Time to Buy and Sell Stock III

//* You are given an array prices where prices[i] is the price of a given stock on the ith day.

//* Find the maximum profit you can achieve. You may complete at most two transactions.

//* Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

#include <bits/stdc++.h>
using namespace std;

// TODO buy or sell stocks at max 2 transactions
//  ? Memoized Code

int solve(int prices[], int i, int k, int size, int dp[][2][3], bool buy)
{
    if (i == size || k == 0)
        return 0;

    if (dp[i][buy][k] != -1)
    {
        return dp[i][buy][k];
    }

    int profit = 0;
    if (buy)
    {
        int buy = solve(prices, i + 1, k, size, dp, false) - prices[i];
        int notbuy = solve(prices, i + 1, k, size, dp, true) - 0;

        profit = max(buy, notbuy);
    }

    else
    {
        int sell = solve(prices, i + 1, k - 1, size, dp, true) + prices[i];
        int notsell = solve(prices, i + 1, k, size, dp, false) + 0;

        profit = max(sell, notsell);
    }

    return dp[i][buy][k] = profit;
}

int main()
{
    int size;
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int dp[size + 1][2][3];
    memset(dp, -1, sizeof(dp));
    int res = solve(arr, 0, 2, size, dp, true);

    cout << res;

    return 0;
}

