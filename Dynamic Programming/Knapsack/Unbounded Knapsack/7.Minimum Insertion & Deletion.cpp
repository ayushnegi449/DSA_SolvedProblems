// Minimum number of deletions and insertions to transform one string into another
// Given two strings ‘str1’ and ‘str2’ of size m and n respectively. The task is to remove/delete and insert minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.
// Example:
// Input : str1 = "geeksforgeeks", str2 = "geeks"
// Output : Minimum Deletion = 8
//          Minimum Insertion = 0

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

    cout << "Deletion : " << x.size() - res << " Insertion : " << y.size() - res;

    return 0;
}
