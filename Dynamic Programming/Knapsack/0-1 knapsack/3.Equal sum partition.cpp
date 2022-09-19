#include <bits/stdc++.h>
using namespace std;

bool subsetSolution(int wt[], bool dp[][1000], int n, int W)
{
    for (int i = 0; i < n + 1; i++)
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

    for (int i = 1; i < n + 1; i++)
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
    int n;
    cin >> n ;

    int *arr = new int[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    bool dp[100][1000];
    memset(dp, false, sizeof(dp));

    if (sum % 2 == 0)
    {
        bool res = subsetSolution(arr, dp, n, sum/2);
        if(res)
        {
            cout<<"Equal sum subset is present \n";
        }
    }
    else
    {
        cout << "Equal sum subset does not exist for given array and sum \n";
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