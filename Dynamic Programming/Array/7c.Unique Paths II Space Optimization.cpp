#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &grid)
{
    vector<int> prev(grid[0].size(), 0);

    for (int i = 0; i < grid.size(); i++)
    {
        vector<int> curr(grid[0].size(), 0);

        for (int j = 0; j < grid[0].size(); j++)
        {
            if (i == 0 && j == 0)
            {
                curr[j] = grid[i][j];
            }
            else
            {
                int up = INT_MAX, left = INT_MAX;

                if (i > 0)
                {
                    up = grid[i][j] + prev[j];
                }

                if (j > 0)
                {
                    left = grid[i][j] + curr[j - 1];
                }

                curr[j] = min(up, left);
            }
        }

        prev = curr;
    }

    return prev[grid[0].size() - 1];
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