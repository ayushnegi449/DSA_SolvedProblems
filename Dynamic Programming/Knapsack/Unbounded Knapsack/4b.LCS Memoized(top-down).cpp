// Longest Common Subsequence Problem solution using recursion
// Given two sequences, find the length of longest subsequence present in both of them.
// A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.

// For example, “abc”,  “abg”, “bdf”, “aeg”,  ‘”acefg”, .. etc are subsequences of “abcdefg”.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(100, vector<int>(100, -1));

int LCS(string x, string y, int xIndex, int yIndex)
{
    if (xIndex == 0 || yIndex == 0)
    {
        return dp[xIndex][yIndex] = 0;
    }

    if (dp[xIndex][yIndex] != -1)
    {
        return dp[xIndex][yIndex];
    }


    if (x.at(xIndex - 1) == y.at(yIndex - 1))
    {
        return dp[xIndex][yIndex] = 1 + LCS(x, y, xIndex - 1, yIndex - 1);
    }
    else
    {
        return dp[xIndex][yIndex] = max(LCS(x, y, xIndex - 1, yIndex), LCS(x, y, xIndex, yIndex - 1));
    }
}

int main()
{
    string x, y;
    cin >> x >> y;

    int res = LCS(x, y, x.size(), y.size());

    cout << "length of longest subsequence present in " << x << " and " << y << " is : " << res;

    return 0;
}
