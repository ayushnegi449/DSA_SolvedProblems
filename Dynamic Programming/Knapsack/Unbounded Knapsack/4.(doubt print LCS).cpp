#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(100, vector<int>(100, -1));

int LCS(vector<char> &v, string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
    {
        dp[n][m] = 0;
        return dp[n][m];
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    if (x.at(n - 1) == y.at(m - 1))
    {
        bool flag = false;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == x[n - 1])
            {
                flag = true;
            }
        }
        if (flag == false)
        {
            v.push_back(x.at(n - 1));
        }
        return dp[n][m] = 1 + LCS(v, x, y, n - 1, m - 1);
    }
    else
    {
        return dp[n][m] = max(LCS(v, x, y, n - 1, m), LCS(v, x, y, n, m - 1));
    }
}

int main()
{
    string x, y;
    cin >> x >> y;
    vector<char> vals;
    int res = LCS(vals, x, y, x.size(), y.size());

    string c = "";
    for (auto i : vals)
    {
        c += i;
    }

    cout << c << "  length : " << res;
    // cout << "length of longest subsequence present in :" << x << " and " << y << " is : " << res;

    return 0;
}