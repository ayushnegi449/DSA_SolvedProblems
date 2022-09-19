#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(100, vector<int>(100, -1));

int LCSubstring(string x, string y, int n, int m)
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

    int maxval = 0;

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
                dp[i][j] = 0;
            }

            if (dp[i][j] > maxval)
            {
                maxval = dp[i][j];
            }
        }
    }

    return maxval;
}

int main()
{
    string x, y;
    cin >> x >> y;

    int res = LCSubstring(x, y, x.size(), y.size());
    cout << "LC substring lenth :" << res;

    return 0;
}