// Subset Sum Equal To K
// You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. 
// Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.

// Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.

// For Example :
// If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. Hence, return true.


// Time Complexity: O(N*K)
// Reason: There are N*K states therefore at max ‘N*K’ new problems will be solved.
// Space Complexity: O(N*K) + O(N)
// Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*K)).

#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> arr, int idx, int target, vector<vector<int>> dp)
{
    if (target == 0)
    {
        return true;
    }
    if (idx == 0)
    {
        if (arr[0] ==target)
        {
            return true;
        }

        return false;
    }

    if (dp[idx][target] != -1)
    {
        return dp[idx][target];
    }

    bool nottake = solve(arr, idx - 1, target, dp);

    bool take = false;

    if (target >= arr[idx])
    {
        take = solve(arr, idx - 1, target - arr[idx], dp);
    }

    return dp[idx][target] = take || nottake;
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

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    if (solve(val, n - 1, target, dp))
    {
        cout << "subset sum possible\n";
    }
    else
    {
        cout << "Subset sum not possible";
    }

    return 0;
}