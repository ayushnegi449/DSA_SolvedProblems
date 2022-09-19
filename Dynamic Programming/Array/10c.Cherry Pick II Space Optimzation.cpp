// Time Complexity: O(N*M*M)*9
// Reason: The outer nested loops run for (N*M*M) times and the inner two nested loops run for 9 times.

// Space Complexity: O(M*M)
// Reason: We are using an external array of size ‘M*M’.

#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> next(m, vector<int>(m, 0)), curr(m, vector<int>(m, 0));

    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
            {
                next[j1][j2] = grid[n - 1][j1];
            }
            else
            {
                next[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxval = 0;

                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        int ans = 0;

                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];

                        if (j1 + x < 0 || j2 + y < 0 || j1 + x == grid[0].size() || j2 + y == grid[0].size())
                        {
                            ans += 0;
                        }
                        else
                        {
                            ans += next[j1 + x][j2 + y];
                        }

                        maxval = max(maxval, ans);
                    }
                }

                curr[j1][j2] = maxval;
            }
        }

        next = curr;
    }
    return next[0][m - 1];
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

    cout << solve(grid);

    return 0;
}
