// Type II: Infinite transactions are allowed

// Given an array price[] of length N, representing the prices of the stocks on different days, the task is to find the maximum profit possible for buying and selling the stocks on different days using transactions where any number of transactions are allowed.

// Examples:

// Input: prices[] = {7, 1, 5, 3, 6, 4}
// Output: 7
// Explanation:
// Purchase on 2nd day. Price = 1.
// Sell on 3rd day. Price = 5.
// Therefore, profit = 5 – 1 = 4.
// Purchase on 4th day. Price = 3.
// Sell on 5th day. Price = 6.
// Therefore, profit = 4 + (6 – 3) = 7.

// Input: prices = {1, 2, 3, 4, 5}
// Output: 4
// Explanation:
// Purchase on 1st day. Price = 1.
// Sell on 5th day. Price = 5.
// Therefore, profit = 5 – 1 = 4.

#include <bits/stdc++.h>
using namespace std;

int solve(int prices[], int size, int idx, bool buy, int dp[][2])
{
    if (idx >= size)
        return 0;

    if (dp[idx][buy] != -1)
    {
        return dp[idx][buy];
    }
    int profit = 0;
    if (buy)
    {
        profit = max(-prices[idx] + solve(prices, size, idx + 1, false,dp), solve(prices, size, idx + 1, true,dp));
    }
    else
    {
        profit = max(prices[idx] + solve(prices, size, idx + 1, true,dp), solve(prices, size, idx + 1, false,dp));
    }

    return dp[idx][buy] = profit;
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

    int dp[size + 1][2];
    memset(dp, -1, sizeof(dp));

    int c = solve(arr, size, 0, true, dp);
    if (c == 0)
    {
        cout << "no profit possible i.e. = 0";
    }
    else
    {
        cout << "Max profit : " << c;
    }
}

// int solve(int prices[], int size, int idx, bool buy, int dp[][2])
// {
//     if (idx >= size)
//         return 0;

//     if (dp[idx][buy] != -1)
//     {
//         return dp[idx][buy];
//     }

//     int profit = 0;

//     if (buy)
//     {
//         int b, nb;
//         if (dp[idx + 1][false] != -1)
//         {
//             b = dp[idx + 1][false];
//         }
//         else
//         {
//             b = -prices[idx] + solve(prices, size, idx + 1, false, dp);
//             dp[idx + 1][false] = b;
//         }
//         if (dp[idx + 1][true] != -1)
//         {
//             nb = dp[idx + 1][true];
//         }
//         else
//         {
//             nb = solve(prices, size, idx + 1, true, dp);
//             dp[idx + 1][true] = nb;
//         }

//         profit = max(b, nb);
//     }
//     else
//     {
//         int b, nb;
//         if (dp[idx + 1][1] != -1)
//         {
//             b = dp[idx + 1][1];
//         }
//         else
//         {
//             b = prices[idx] + solve(prices, size, idx + 1, true, dp);
//             dp[idx + 1][1] = b;
//         }
//         if (dp[idx + 1][0] != -1)
//         {
//             nb = dp[idx + 1][0];
//         }
//         else
//         {
//             nb = solve(prices, size, idx + 1, false, dp);
//             dp[idx + 1][0] = nb;
//         }

//         profit = max(b, nb);
//     }

//     return dp[idx][buy] = profit;
// }