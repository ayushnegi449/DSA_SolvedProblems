// Time Complexity: O(N*M*M)*9
// Reason: The outer nested loops run for (N*M*M) times and the inner two nested loops run for 9 times.

// Space Complexity: O(N*M*M)
// Reason: We are using an external array of size ‘N*M*M’. The stack space will be eliminated.

#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    for (int j = 0; j < m; j++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j == j2)
            {
                dp[n - 1][j][j2] = grid[n - 1][j];
            }
            else
            {
                dp[n - 1][j][j2] = grid[n - 1][j] + grid[n - 1][j2];
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
                            ans += dp[i + 1][j1 + x][j2 + y];
                        }

                        maxval = max(maxval, ans);
                    }
                }

                dp[i][j1][j2] = maxval;
            }
        }
    }

    return dp[0][0][m - 1];
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


// class Solution //faster cause of no -1 to 1 for loops.
// {
// public:
//     int cherryPickup(vector<vector<int>> &grid)
//     {
//         int n = grid.size(), m = grid[0].size();
//         int dp[n][m][m];
//         for (int i = 0; i < n; i++)
//             for (int j = 0; j < m; j++)
//                 for (int k = 0; k < m; k++)
//                     dp[i][j][k] = 0;
//         dp[0][0][m - 1] = 0 == m - 1 ? grid[0][0] : grid[0][0] + grid[0][m - 1];

//         for (int i = 1; i < n; i++)
//         {
//             for (int j = 0; j < min(m, i + 1); j++)
//             {
//                 for (int k = max(0, m - 1 - i); k < m; k++)
//                 {
//                     int mx = INT_MIN;
//                     if (j - 1 >= 0 and k - 1 >= 0)
//                         mx = max(mx, dp[i - 1][j - 1][k - 1]);
//                     if (j - 1 >= 0 and k + 1 < m)
//                         mx = max(mx, dp[i - 1][j - 1][k + 1]);
//                     if (k - 1 >= 0)
//                         mx = max(mx, dp[i - 1][j][k - 1]);
//                     if (j - 1 >= 0)
//                         mx = max(mx, dp[i - 1][j - 1][k]);
//                     mx = max(mx, dp[i - 1][j][k]);
//                     if (k + 1 < m)
//                         mx = max(mx, dp[i - 1][j][k + 1]);
//                     if (j + 1 < m and k - 1 >= 0)
//                         mx = max(mx, dp[i - 1][j + 1][k - 1]);
//                     if (j + 1 < m and k + 1 < m)
//                         mx = max(mx, dp[i - 1][j + 1][k + 1]);
//                     if (j + 1 < m)
//                         mx = max(mx, dp[i - 1][j + 1][k]);

//                     if (j == k)
//                         dp[i][j][k] = mx + grid[i][j];
//                     else
//                         dp[i][j][k] = mx + grid[i][j] + grid[i][k];
//                 }
//             }
//         }

//         int ans = 0;
//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 ans = max(ans, dp[n - 1][i][j]);
//             }
//         }
//         return ans;
//     }
// };