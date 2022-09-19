/*Type I: At most one transaction is allowed

// Given an array prices[] of length N, representing the prices of the stocks on different days, 
// the task is to find the maximum profit possible for buying and selling the stocks on different days 
// using transactions where at most one transaction is allowed.

Note: Stock must be bought before being sold.

Examples:

Input: prices[] = {7, 1, 5, 3, 6, 4]
Output: 5
Explanation:
The lowest price of the stock is on the 2nd day, i.e. price = 1. Starting from the 2nd day, the highest price of the stock is witnessed on the 5th day, i.e. price = 6. 
Therefore, maximum possible profit = 6 – 1 = 5. 

Input: prices[] = {7, 6, 4, 3, 1} 
Output: 0
Explanation: Since the array is in decreasing order, no possible way exists to solve the problem.*/

#include <bits/stdc++.h>
using namespace std;

int solve(int prices[], int size)
{
    int maxprofit = 0;
    int minBuy = INT_MAX;

    for (int i = 0; i < size; i++)
    {
        minBuy = min(minBuy, prices[i]);
        maxprofit = max(maxprofit, prices[i] - minBuy);
    }

    return maxprofit;
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
    int c = solve(arr, size);
    if (c == 0)
    {
        cout << "no profit possible i.e. = 0";
    }
    else
    {
        cout << "Max profit : " <<c;
    }
}
