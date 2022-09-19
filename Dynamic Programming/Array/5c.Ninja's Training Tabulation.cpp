#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &points)
{
    int N = points.size();

    int taskDO = points[0].size();

    vector<vector<int>> dp(N + 1, vector<int>(taskDO + 1, -1));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max((points[0][0], points[0][1]), points[0][2]);

    for (int days = 1; days < N; days++) //? days  = i;
    {
        for (int last = 0; last < 4; last++) // picked index of day "i-1" ;  //? last = j
        {
            dp[days][last] = 0;

            for (int task = 0; task < points[0].size(); task++) // which task to perform on current day i
            {
                if (task != last)
                {
                    int point = points[days][task] + dp[days - 1][task];

                    dp[days][last] = max(dp[days][last],point);
                }
            }
        }
    }

    return dp[N-1][taskDO];
}

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> points(N, vector<int>(3, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> points[i][j];
        }
    }

    cout << solve(points);

    return 0;
}