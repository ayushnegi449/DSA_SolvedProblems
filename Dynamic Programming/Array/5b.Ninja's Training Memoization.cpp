#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> td, int days, int visited, vector<vector<int>> &dp)
{
    if (days == 0)
    {
        int maxval = 0;

        for (int i = 0; i < 3; i++)
        {
            if (visited != i)
            {
                maxval = max(maxval, td[0][i]);
            }
        }

        return maxval;
    }

    if (dp[days][visited] != -1)
    {
        return dp[days][visited];
    }

    int maxPoints = 0;  

    for (int last = 0; last < 3; last++)
    {
        int points = 0;

        if (visited != last)
        {
            points = td[days][last] + solve(td, days - 1, last, dp);
        }

        maxPoints = max(points, maxPoints);
    }

    return dp[days][visited] = maxPoints;
}

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> td(N, vector<int>(3, 0)); // training days - td;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> td[i][j];
        }
    }

    vector<vector<int>> dp(N + 1, vector<int>(4, -1));

    cout << solve(td, N - 1, 3, dp);

    return 0;
}