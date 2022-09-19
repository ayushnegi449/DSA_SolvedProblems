// Longest Common Substring(Dynamic Programming)
// Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.
// Examples:

// Input : X = “GeeksforGeeks”, y = “GeeksQuiz”
// Output : 5
// The longest common substring is “Geeks” and is of length 5.

// Recursive Code
#include <bits/stdc++.h>
using namespace std;

int ans(string s1, string s2, int n, int m, int len)
{

    if (n == 0 || m == 0)
    {
        return len;
    }

    int counter = len;

    if (s1[n - 1] == s2[m - 1])
    {
        counter = ans(s1, s2, n - 1, m - 1, len + 1);
    }

    int len1 = ans(s1, s2, n - 1, m, 0);
    int len2 = ans(s1, s2, n, m - 1, 0);

    return max({counter, len1, len2});
}

int main()
{

    string s1, s2;
    cin >> s1>>s2;

    cout << ans(s1, s2, s1.size(), s2.size(), 0) << endl;

    return 0;
}