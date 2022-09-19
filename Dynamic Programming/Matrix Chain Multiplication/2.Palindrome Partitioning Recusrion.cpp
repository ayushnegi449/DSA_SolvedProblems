// Palindrome Partitioning using Recursion
// Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. 
// Example:
//   “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”.

#include <bits/stdc++.h>
using namespace std;

auto start = chrono::steady_clock::now();

bool isPalindrome(string s, int i, int j)
{
    // MY METHOD :
    // while (x[i] == x[j])
    // {
    //     if(i==j || j-i==1)
    //     {
    //         return true;
    //     }
    //     i++;
    //     j--;
    // }

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

// vector<vector<int>> dp(100, vector<int>(100, -1));

int PP(string s, int i, int j)
{
    if (i >= j)
    {
        return 0;
    }

    // if (dp[i][j] != -1)
    // {
    //     return dp[i][j];
    // }

    if (isPalindrome(s, i, j))
    {
        return 0;
    }

    int ans = INT_MAX;

    for (int k = i; k <= j - 1; k++)
    {
        int temp = PP(s, i, k) + PP(s, k + 1, j) + 1;

        if (temp < ans)
        {
            ans = temp;
        }
    }
    return  ans;
}

int main()
{
    string s;
    cin >> s;

    int part = PP(s, 0, s.size() - 1);
    cout << "Palindromic Partitions : " << part;
    cout << "\n";

    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double,milli>(diff).count() << " ms" << endl;

    // isPalindrome(s, 0, s.size() - 1);
    return 0;
}