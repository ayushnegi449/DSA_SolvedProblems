#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int i, int j)
{
    if (i == j)
    {
        return true;
    }
    if (i > j)
    {
        return true;
    }
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

vector<vector<int>> dp(100, vector<int>(100, -1));

int PP(string &s, int i, int j)
{
    if (i >= j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (isPalindrome(s, i, j))
    {
        return 0;
    }

    int ans = INT_MAX;

    for (int k = i; k <= j - 1; k++)
    {
        int left, right;
       
        if (dp[i][k] != -1)
        {
            left = dp[i][k];
        }
        else
        {
            left = PP(s, i, k);
            dp[i][k] = left;
        }

        if (dp[j][k + 1] != -1)
        {
            right = dp[k + 1][j];
        }
        else
        {
            right = PP(s, k + 1, j);
            dp[k + 1][j] = right;
        }

        int temp = left + right + 1;

        if (temp < ans)
        {
            ans = temp;
        }
    }

   
    // for (int k = i; k <= j - 1; k++)
    // {
    //     int temp = PP(s, i, k) + PP(s, k + 1, j) + 1;

    //     if(temp<ans)
    //     {
    //         ans=temp;
    //     }

    // }

    return dp[i][j] = ans;
}

int main()
{
    string s;
    cin >> s;

    int part = PP(s, 0, s.size() - 1);
    cout << "Palindromic Partitions : " << part;

    return 0;
}