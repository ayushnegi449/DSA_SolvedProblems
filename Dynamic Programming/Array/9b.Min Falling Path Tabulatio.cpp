#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &matrix)
{

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Initializing first row - base condition
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            int up = matrix[i][j] + dp[i - 1][j];
            int rightDiagonal = matrix[i][j];
            int leftDiagonal = matrix[i][j];
            
            if (j - 1 >= 0)
            {
                leftDiagonal += dp[i - 1][j - 1];
            }
            else
            {
                leftDiagonal += INT_MAX - 1000;
            }

            if (j + 1 < m)
            {
                rightDiagonal += dp[i - 1][j + 1];
            }
            else
            {
                rightDiagonal += INT_MAX - 1000;
            }

            dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
        }
    }

    int mini = INT_MAX;

    for (int j = 0; j < m; j++)
    {
        mini = min(mini, dp[n - 1][j]);
    }

    return mini;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> variablepath(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> variablepath[i][j];
        }
    }

    cout << solve(variablepath);

    return 0;
}