#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<vector<int>> &points)
{

    vector<int> prev(4, 0);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {

        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;

            for (int task = 0; task <= 2; task++)
            {
                if (task != last)
                {
                    temp[last] = max(temp[last], points[day][task] + prev[task]);
                }
            }
        }

        prev = temp;
    }

    return prev[3];
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

    cout << solve(N,points);

    return 0;
}