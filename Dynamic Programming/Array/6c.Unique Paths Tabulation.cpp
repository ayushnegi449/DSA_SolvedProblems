//! Time Complexity: O(M*N)
//? Reason: There are two nested loops

//! Space Complexity: O(M*N)
//? Reason: We are using an external array of size ‘M*N’’.

#include <bits/stdc++.h>
using namespace std;

int totalUniquePaths(int m, int n)
{
    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // base condition
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if (i > 0)
            {
                up = dp[i - 1][j];
            }
            if (j > 0)
            {
                left = dp[i][j - 1];
            }

            dp[i][j] = up + left;
        }
    }

    return dp[m - 1][n - 1];
}

int main()
{
    int m, n;
    cin >> m >> n;

    cout << totalUniquePaths(m, n);
}