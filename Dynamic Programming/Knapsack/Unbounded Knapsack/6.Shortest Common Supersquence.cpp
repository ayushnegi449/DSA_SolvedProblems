// Shortest Common SuperSequence
// Given two strings str1 and str2, find the shortest string that has both str1 and str2 as subsequences.
// Examples:

// Input:   str1 = "geek",  str2 = "eke"
// Output: "geeke"

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(100, vector<int>(100, -1));

int SCS(string x, string y, int n, int m)
{
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
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if(x[i-1]==y[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return (n+m)-dp[n][m];
}

int main()
{
    string x, y;
    cin >> x >> y;
     cout<<x;
    int res = SCS(x, y, x.size(), y.size());

    cout << "Length of shortest common supersequence : " << res;

    return 0;
}