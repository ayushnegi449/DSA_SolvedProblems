//* 123. Best Time to Buy and Sell Stock III

//* You are given an array prices where prices[i] is the price of a given stock on the ith day.

//* Find the maximum profit you can achieve. You may complete at most two transactions.

//* Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


#include <bits/stdc++.h>
using namespace std;

//TODO buy or sell stocks at max 2 transactions
//! code gives TLE on leetcode

int solve(int prices[], int i, int k, int size, unordered_map<string, int> mp, bool buy)
{
    if (i == size || k == 0)
        return 0;

    string x = to_string(i) + " " + to_string(buy);

    if (mp.count(x) != 0)
    {
        return mp[x];
    }

    int profit = 0;
    if (buy)
    {
        int buy = solve(prices, i + 1, k, size, mp, false) - prices[i];
        int notbuy = solve(prices, i + 1, k, size, mp, true) - 0;

        profit = max(buy, notbuy);
    }

    else
    {
        int sell = solve(prices, i + 1, k-1, size, mp, true) + prices[i];
        int notsell = solve(prices, i + 1, k, size, mp, false) + 0;

        profit = max(sell, notsell);
    }

    return mp[x] = profit;
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

    unordered_map<string, int> mp;
    int res = solve(arr, 0, 2, size, mp,true);

    cout << res;

    return  0;
}