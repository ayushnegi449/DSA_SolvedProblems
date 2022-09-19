#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &triangle)
{
    int n = triangle.size();

    vector<int> next(n, 0);

    for (int j = 0; j < n; j++)
    {
        next[j] = triangle[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> curr(i + 1, 0);

        for (int j = 0; j < i + 1; j++)
        {
            int down = triangle[i][j] + next[j];

            int diagonal = triangle[i][j] + next[j + 1];

            curr[j] = min(down, diagonal);
        }

        next = curr;
    }

    return next[0];
}

int main()
{
    int m;
    cin >> m;

    vector<vector<int>> triangle(m, vector<int>(m, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cin >> triangle[i][j];
        }
    }

    cout << solve(triangle);

    return 0;
}