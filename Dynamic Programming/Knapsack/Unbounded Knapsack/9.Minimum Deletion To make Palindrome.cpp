// Minimum number of deletions to make a string palindrome
// Given a string of size ‘n’. The task is to remove or delete minimum number of characters from the string so that the resultant string is palindrome.
// Examples :

// Input : aebcbda
// Output : 2
// Remove characters 'e' and 'd'
// Resultant string will be 'abcba'
// which is a palindromic string

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(100, vector<int>(100, -1));

int LPSbottomUp(string x, string y, int n, int m)
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
            if(x[i-1]==y[j-1])
            {
                dp[i][j]= 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    // Return the size of LPS
    return dp[n][m];
}

// Driver code
int main()
{
    string a;
    cin >> a;
    string x = a;
    reverse(a.begin(),a.end());
    string y = a;

    int res = LPSbottomUp(x, y, x.size(), y.size());

    cout << "Min Deletions : "<<x.size()-res;

    return 0;
}