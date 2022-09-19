// Ninja’s Training

// Difficulty: Moderate
// PROBLEM STATEMENT
// Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities.
// (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day.
// As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days.
// Can you help Ninja find out the maximum merit points Ninja can earn?

// You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity.
// Your task is to calculate the maximum number of merit points that Ninja can earn.

// If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.

#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> td, int days, int visited)
{
    if (days == 0)
    {
        int maxval = 0;

        for (int i = 0; i < 3; i++)
        {
            int val = 0;

            if (visited != i)
            {
                val = td[0][i];
            }

            maxval = max(maxval, val);
        }

        return maxval;
    }

    int maxPoints = 0;

    for (int i = 0; i < 3; i++)
    {
        int points = 0;
        
        if (visited != i)
        {
            points = td[days][i] + solve(td, days - 1, i);
        }

        maxPoints = max(points, maxPoints);
    }

    return maxPoints;
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

    cout << solve(td, N - 1, 3);

    return 0;
}