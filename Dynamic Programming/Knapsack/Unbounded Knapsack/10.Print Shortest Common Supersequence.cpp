// Given two strings X and Y, print the shortest string that has both X and Y as subsequences. If multiple shortest supersequence exists, print any one of them.

// Examples:

// Input: X = "AGGTAB",  Y = "GXTXAYB"
// Output: "AGXGTXAYB" OR "AGGXTXAYB"
// OR Any string that represents shortest
// supersequence of X and Y

// Input: X = "HELLO",  Y = "GEEK"
// Output: "GEHEKLLO" OR "GHEEKLLO"
// OR Any string that represents shortest
// supersequence of X and

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(100, vector<int>(100, -1));

void SCSPrint(string x, string y, int n, int m)
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
            if (x.at(i - 1) == y.at(j - 1))
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = n, j = m;
    string s = "";
    while (i > 0 && j > 0)
    {
        if(x[i-1]==y[j-1])
        {
            s.push_back(x[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            s.push_back(x[i-1]);
            i--;
        }
        else
        {
            s.push_back(y[j-1]);
            j--;
        }
    }
    
    while (i>0)
    {
        s.push_back(x[i-1]);
        i--;
    }
    while (j>0)
    {
       s.push_back(y[j-1]);
       j--;
    }

    reverse(s.begin(),s.end());

    cout<<"Shortest common supersequence : "<<s<<" Length : "<<(m+n)-dp[n][m];

}

int main()
{
    string x,y;
    cin>>x>>y;

    SCSPrint(x,y,x.size(),y.size());

    return 0;
}