// Longest Repeating Subsequence
// Given a string, print the longest repeating subsequence such that the two subsequence don’t have same string character at same position,
// i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.
// Example:
// Input: str = "aab"
// Output: "a"
// The two subsequence are 'a'(first) and 'a' (second). Note that 'b' cannot be considered as part of subsequence as it would be at sameindex in both.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(1000, vector<int>(1000, -1));

int LRS(string x, string y, int n, int m)
{
    // Base case initialization :
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    // Flow Diagram code (recursive to dp)
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1] && i != j)
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Return the size of lCS
    return dp[n][m];
}

// Driver code
int main()
{
    string x, y;
    cin >> x;
    y = x;

    int res = LRS(x, y, x.size(), y.size());

    cout << "LRS : " << res;

    return 0;
}
