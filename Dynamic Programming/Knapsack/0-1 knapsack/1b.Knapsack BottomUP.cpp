#include <bits/stdc++.h>
using namespace std;

int bottomUpDPKnapsack(int wt[], int vl[], int w, int n, int dp[][1001])
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(vl[i - 1] + dp[i-1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][w];
}

int main()
{
    int n, w;
    cin >> n >> w;

    int *wt = new int[n];
    int *vl = new int[n];

    cout << "Enter weight followed by it's value i.e 30(kg) 120(rs):\n";
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> vl[i];
    }

    int dp[101][1001];
    memset(dp, -1, sizeof(dp));

    int max = bottomUpDPKnapsack(wt, vl, w, n, dp);
    cout << "\nMax Profit : " << max << endl;


    return 0;
}