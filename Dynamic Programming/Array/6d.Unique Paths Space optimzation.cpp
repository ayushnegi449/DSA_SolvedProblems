#include <bits/stdc++.h>
using namespace std;

int solve(int m, int n)
{
    vector<int> prev(n, 0);

    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n, 0);

        for (int j = 0; j < n; j++)
        {
            int up = 0, left = 0;

            if (i == 0 && j == 0)
            {
                curr[j] = 1;
                // continue;
            }
            else
            {
                if (i > 0)
                {
                    up = prev[j];
                }
                if (j > 0)
                {
                    left = curr[j - 1];
                }

                curr[j] = left + up;
            }
        }

        prev = curr;
    }

    return prev[n - 1];
}

int main()
{
    int m, n;
    cin >> m >> n;

    cout << solve(m, n);
}