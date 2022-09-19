#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    int n = triangle.size();

    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < i + 1; j++)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(down, diagonal);
        }
    }

    return dp[0][0];
}

int main()
{
    int m;
    cin >> m;

    vector<vector<int>> triangle(m, vector<int>(m, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cin >> triangle[i][j];
        }
    }

    vector<vector<int>> dp(m, vector<int>(m, -1));

    cout << solve(triangle, dp);

    return 0;
}