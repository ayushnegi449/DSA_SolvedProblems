// 931. Minimum Falling Path Sum

// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right.
// Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

// Time Complexity: O(N*N)
// Reason: At max, there will be M*N calls of recursion to solve a new problem,

// Space Complexity: O(N) + O(N*M)
// Reason: We are using a recursion stack space: O(N), where N is the path length and an external DP Array of size ‘N*M’

#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &variablepath, int row, int col, vector<vector<int>> dp)
{
    if (col < 0 || col >= variablepath[0].size())
    {
        return INT_MAX - 10000;
    }
    if (row == 0)
    {
        return variablepath[row][col];
    }

    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }

    int left = variablepath[row][col] + solve(variablepath, row - 1, col - 1, dp);
    int up = variablepath[row][col] + solve(variablepath, row - 1, col, dp);
    int right = variablepath[row][col] + solve(variablepath, row - 1, col + 1, dp);

    return dp[row][col] = min(min(left, right), up);
}

int solveVariablePath(int n, int m, vector<vector<int>> &variablepath)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));

    int minval = INT_MAX;

    for (int j = 0; j < m; j++)
    {
        int val = solve(variablepath, n - 1, j, dp);

        minval = min(minval, val);
    }

    return minval;
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

    cout << solveVariablePath(n, m, variablepath);

    return 0;
}