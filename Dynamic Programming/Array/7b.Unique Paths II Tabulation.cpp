#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &grid)
{
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
            }
            else
            {
                int up = INT_MAX, left = INT_MAX;

                if (i > 0)
                {
                    up = grid[i][j] + dp[i - 1][j];
                }

                if (j > 0)
                {
                    left = grid[i][j] + dp[i][j - 1];
                }

                dp[i][j] = min(up, left);
            }
        }
    }

    return dp[grid.size() - 1][grid[0].size() - 1];
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << solve(grid);

    return 0;
}