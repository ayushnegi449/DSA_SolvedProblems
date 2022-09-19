#include <bits/stdc++.h>
using namespace std;

int CountsubsetSolution(int wt[], int dp[][1000], int n, int W)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            if (j == 0)
            {
                dp[i][j] = 1;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - wt[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][W];
}

int main()
{
    int n, sum;
    cin >> n >> sum;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int dp[100][1000];
    memset(dp, -1, sizeof(dp));

    int res = CountsubsetSolution(arr, dp, n, sum);
    cout << "Total Subsets : " << res;

    return 0;
}