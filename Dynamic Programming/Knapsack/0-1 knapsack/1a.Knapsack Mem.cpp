#include <bits/stdc++.h>
using namespace std;

int knapsack(int w[], int v[], int maxw, int n, int dp[][1002])
{
    if (n == 0 || maxw == 0)
    {
        return 0;
    }
    if (dp[n][maxw] != -1)
    {
        return dp[n][maxw]; // maxw can be w[n]
    }

    if (w[n-1] <= maxw)
    {
        return dp[n][maxw] = max((v[n-1] + knapsack(w, v, maxw - w[n-1], n - 1, dp)), knapsack(w, v, maxw, n - 1, dp));
    }
    else if (w[n-1] > maxw)
    {
        return dp[n][maxw] = knapsack(w, v, maxw, n - 1, dp);
    }
}

int main()
{
    int size, maxw;
    cout << "Enter size and max weight\n";
    cin >> size >> maxw;
    cout << "\nWEIGHT:\n";

    int *w = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> w[i];
    }

    cout << "\nVALUE:\n";
    int *v = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }

    int dp[101][1002];
    memset(dp, -1, sizeof(dp));
    cout << endl
         << "MAX Profit POSSIBLE : " << knapsack(w, v, maxw, size , dp) << endl;
    return 0;
}