// Cherry Pickup II
// You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

// You have two robots that can collect cherries for you:

// Robot #1 is located at the top-left corner (0, 0), and
// Robot #2 is located at the top-right corner (0, cols - 1).
// Return the maximum number of cherries collection using both robots by following the rules below:

// From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
// When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
// When both robots stay in the same cell, only one takes the cherries.
// Both robots cannot move outside of the grid at any moment.
// Both robots should reach the bottom row in grid.

// Example 1:
// Input : grid =
//  {[3, 1, 1],
// [ 2, 5, 1 ],
// [ 1, 5, 5 ],
// [ 2, 1, 1 ],};
// Output: 24
// Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
// Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
// Total of cherries: 12 + 12 = 24.
#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &grid, int row, int j1, int j2, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j2 < 0 || j1 == grid[0].size() || j2 == grid[0].size())
    {
        return 0;
    }
    if (row == grid.size() - 1)
    {
        if (j1 == j2)
        {
            return grid[row][j1];
        }
        else
        {
            return grid[row][j1] + grid[row][j2];
        }
    }
    if (dp[row][j1][j2] != -1)
    {
        return dp[row][j1][j2];
    }

    int maxval = 0;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int ans = 0;

            if (j1 == j2)
            {
                ans = grid[row][j1] + solve(grid, row + 1, j1 + i, j2 + j, dp);
            }
            else
            {
                ans = grid[row][j1] + grid[row][j2] + solve(grid, row + 1, j1 + i, j2 + j, dp);
            }

            maxval = max(ans, maxval);
        }
    }

    return dp[row][j1][j2] = maxval;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    cout << solve(grid, 0, 0, grid[0].size() - 1, dp);

    return 0;
}

