#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(100, vector<int>(100, -1));

int LCSbottomUp(string x, string y, int n, int m)
{
    string s;

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

    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            s += x[i - 1];
            i--;
            j--;
        }
        else if (dp[i][j - 1] > dp[i - 1][j])
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    reverse(s.begin(), s.end());
    cout<<"LCS : "<<s<<"  ";
    return dp[n][m];
}

// Driver code
int main()
{
    string x, y;
    cin >> x >> y;

    int res = LCSbottomUp(x, y, x.size(), y.size());

    cout << "SIZE: " << res;

    return 0;
}

// 	        0	1	2	3	4	5	6	7
//          Ø	M	Z	J	A	W	X	U
// 0	Ø	0	0	0	0	0	0	0	0
// 1	X	0	0	0	0	0	0	1	1
// 2	M	0	1	1	1	1	1	1	1
// 3	J	0	1	1	2	2	2	2	2
// 4	Y	0	1	1	2	2	2	2	2
// 5	A	0	1	1	2	3	3	3	3
// 6	U	0	1	1	2	3	3	3	4
// 7	Z	0	1	2	2	3	3	3	4