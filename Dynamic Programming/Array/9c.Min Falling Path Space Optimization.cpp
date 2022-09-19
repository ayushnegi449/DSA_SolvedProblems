// Time Complexity: O(N*M)
// Reason: There are two nested loops

// Space Complexity: O(M)
// Reason: We are using an external array of size ‘M’ to store only one row.

#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &variablepath)
{
    int n = variablepath.size();
    int m = variablepath[0].size();

    vector<int> prev(m, 0), curr(m, 0);

    for (int j = 0; j < m; j++)
    {
        prev[j] = variablepath[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = variablepath[i][j] + prev[j];
            int left = variablepath[i][j];
            int right = variablepath[i][j];

            if (j > 0)
            {
                left += prev[j - 1];
            }
            else
            {
                left += INT_MAX - 1000;
            }

            if (j + 1 < m)
            {
                right += prev[j + 1];
            }
            else
            {
                right += INT_MAX - 1000;
            }

            curr[j] = min(min(left, right), up);
        }

        prev = curr;
    }

    int minval = INT_MAX;

    for (int j = 0; j < m; j++)
    {
        minval = min(minval, prev[j]);
    }

    return minval;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> variablepath(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> variablepath[i][j];
        }
    }

    cout << solve(variablepath);

    return 0;
}


