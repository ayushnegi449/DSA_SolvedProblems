// Time Complexity: O(N*K)
// Reason: There are three nested loops

// Space Complexity: O(K)
// Reason: We are using an external array of size ‘K+1’ to store only one row.

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int sum, vector<vector<int>> dp)
{
    int n = arr.size();

    vector<int> prev(sum + 1, 0), curr(sum + 1, 0);

    if (arr[0] == 0)
    {
        prev[0] = 2;
    }
    else
    {
        prev[0] = 1;
    }

    //   if (arr[1] == 0)
    //     {
    //         curr[0] = 2;
    //     }
    //     else
    //     {
    //         curr[0] = 1;
    //     }

    if (sum >= arr[0] && arr[0] != 0)
    {
        prev[arr[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            int nottake = prev[j];
            int take = 0;

            if (j >= arr[i])
            {
                take = prev[j - arr[i]];
            }

            curr[j] = take + nottake;
        }

        prev = curr;
    }

    return prev[sum];
}

int main()
{
    int n, diff, sum = 0;
    cin >> n >> diff;

    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    int target = sum - diff;

    if ((target % 2 == 0) && sum >= diff)
    {
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        cout << solve(arr, target / 2, dp);
    }
    else
    {
        cout << "0 subsets possible";
    }

    return 0;
}