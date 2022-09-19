#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &dp)
{
    if (row == 0 && col == 0)
    {
        return grid[0][0];
    }

    if (row < 0 || col < 0)
    {
        return INT_MAX - 10000;
    }

    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }

    int up = grid[row][col] + solve(grid, row - 1, col, dp);
    int left = grid[row][col] + solve(grid, row, col - 1, dp);

    return dp[row][col] = min(up, left);
}

int main()
{
    int n, m;
    cin >> n>> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid.size(); j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    cout << solve(grid, n - 1, m - 1, dp);

    return 0;
}