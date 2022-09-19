// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally,
// if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 
// Example 1:
// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).


#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &triangle, int row, int col, vector<vector<int>> &dp)
{
    if (row == triangle.size() - 1)
    {
        return triangle[row][col];
    }

    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }

    int down = triangle[row][col] + solve(triangle, row + 1, col, dp);
    int diagonal = triangle[row][col] + solve(triangle, row + 1, col + 1, dp);

    return dp[row][col] = min(down, diagonal);
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

    cout << solve(triangle, 0, 0, dp);

    return 0;
}