// Subset Sum Problem(Dynamic Programming)
// Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
// Example:

// Input:  set[] = {3, 34, 4, 12, 5, 2}, sum = 9
// Output:  True  //There is a subset (4, 5) with sum 9.

#include <bits/stdc++.h>
using namespace std;

bool subsetSolution(int wt[], bool dp[][1000], int n, int W)
{
    for (int i = 0; i < n +1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = false;
            }
            if (j == 0)
            {
                dp[i][j] = true;
            }
        }
    }

    for (int i = 1; i < n +1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - wt[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][W];
}

int main()
{
    int n, sum;
    cin >> n >> sum;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bool dp[100][1000];
    memset(dp, false, sizeof(dp));

    bool res = subsetSolution(arr, dp, n, sum);
    if (res)
    {
        cout << "Subsets exists for given array and sum \n";
    }
    else
    {
        cout << "Subsets does not exist for given array and sum \n";
    }

    // for (int i = 0; i < n+1; i++)
    // {
    //     for (int j = 0; j < sum+1; j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}