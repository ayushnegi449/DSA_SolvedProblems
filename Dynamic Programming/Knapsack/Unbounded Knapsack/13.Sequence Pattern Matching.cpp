// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

// Example 1:
// Input: s = "abc", t = "ahbgdc"
// Output: true

// Example 2:
// Input: s = "axc", t = "ahbgdc"
// Output: false

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(100, vector<int>(100, -1));

int LCSbottomUp(string x, string y, int n, int m)
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
            if (x[i - 1] == y[j - 1])
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
    cin >> x >> y;

    int res = LCSbottomUp(x, y, x.size(), y.size());
    int m = min(x.size(), y.size());
    if (res == m)
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }

    return 0;
}

/*  Two pointer approach

    bool isSubsequence(string s, string t) {

        int m = s.size();

        int n = t.size();

        int i = 0, j = 0;

        while(i < m && j < n) {

            if(s[i] == t[j]) {

                i++;

            }

            j++;

        }

        return i == m ? 1 : 0;

    }

};*/