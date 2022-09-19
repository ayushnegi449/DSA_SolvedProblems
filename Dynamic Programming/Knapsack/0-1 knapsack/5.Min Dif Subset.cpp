#include <bits/stdc++.h>
using namespace std;

int minimum_difference(int r, int range, bool DP[][100])
{
    int c;
    if (range % 2 == 0)
    {
        c = range / 2;
    }
    else
    {
        c = range / 2 + 1;
    }

    vector<int> sumArray;

    for (int i = 0; i < c; i++)
    {
        if (DP[r][i] == true)
        {
            sumArray.push_back(i);
        }
    }

    int min_diff = INT_MAX;

    for (int i = 0; i < sumArray.size(); i++)
    {
        int x = range - (2 * sumArray[i]);

        if (x < min_diff)
        {
            min_diff = x;
        }
    }
    return min_diff;
}

int SubsetSum(int arr[], int n, int range, bool DP[][100])
{
    for (int i = 0; i < (n + 1); i++)
    {
        for (int j = 0; j < (range + 1); j++)
        {
            if (i == 0)
            {
                DP[i][j] = false;
            }
            if (j == 0)
            {
                DP[i][j] = true;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < range + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                DP[i][j] = DP[i - 1][j - arr[i - 1]] || DP[i - 1][j];
            }
            else
            {
                DP[i][j] = DP[i - 1][j];
            }
        }
    }
    return minimum_difference(n, range, DP);
}

int main()
{
    int n, sum=0;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    bool DP[n + 1][100];
    memset(DP, 1, sizeof(DP));

    int min_diff = SubsetSum(arr, n, sum, DP);

    cout << "MIn val: " << min_diff;
    return 0;
}
