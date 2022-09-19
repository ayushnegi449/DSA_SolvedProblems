// Given an array Arr[] and a difference diff, find the number of subsets that array can be divided so that each the difference between the two subset is the given diff.

// Example1:
// Input:
// Arr[] : 1,1,2,3
// diff: 1
// Output: 3 . 

#include <bits/stdc++.h>
using namespace std;

int countDiffSubset(int arr[], int n, int sum, vector<vector<int>> dp)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            if (j == 0)
            {
                dp[i][j] = 1;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int main()
{
    int n, sumArr = 0, diff;
    cin >> n >> diff;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sumArr += arr[i];
    }

    int s1 = (diff + sumArr) / 2;

    vector<vector<int>> dp(n + 1, vector<int>(s1 + 1, -1));

    int counter = countDiffSubset(arr, n, s1, dp);
    cout << "Number of subsets with " << diff << " as difference bw two subsets = " << counter;
    return 0;
}