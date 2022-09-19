// Time Complexity: O(N*K)
// Reason: There are two nested loops

// Space Complexity: O(N*K)
// Reason: We are using an external array of size ‘N*K’. Stack Space is eliminated.

#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> arr, int target)
{
    int n = arr.size();

    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (arr[0] <= target)
    {
        dp[0][arr[0]] = true; // cause at 0th index only if target == arr[0] => true.
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < target + 1; j++)
        {
            bool nottake = dp[i - 1][j];

            bool take = false;

            if (j >= arr[i])
            {
                take = dp[i - 1][j - arr[i]];
            }

            dp[i][j] = take || nottake;
        }
    }

    return dp[n - 1][target];
}

int main()
{
    int n, target;
    cin >> n >> target;

    vector<int> val(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    if (solve(val, target))
    {
        cout << "subset sum possible\n";
    }
    else
    {
        cout << "Subset sum not possible";
    }

    return 0;
}