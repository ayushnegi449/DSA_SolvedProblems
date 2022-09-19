// Given an array ‘ARR’, partition it into two subsets (possibly empty) such that their union is the original array. 
// Let the sum of the elements of these two subsets be ‘S1’ and ‘S2’.

// Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than or equal to ‘S2’ and the difference between ‘S1’ and ‘S2’ is equal to ‘D’.
//  Since the answer may be too large, return it modulo ‘10^9 + 7’.

// If ‘Pi_Sj’ denotes the Subset ‘j’ for Partition ‘i’. Then, two partitions P1 and P2 are considered different if:

// 1) P1_S1 != P2_S1 i.e, at least one of the elements of P1_S1 is different from P2_S2.
// 2) P1_S1 == P2_S2, but the indices set represented by P1_S1 is not equal to the indices set of P2_S2. Here, 
// the indices set of P1_S1 is formed by taking the indices of the elements from which the subset is formed.
// Refer to the example below for clarification.
// Note that the sum of the elements of an empty subset is 0.

// For Example :
// If N = 4, D = 3, ARR = {5, 2, 5, 1}
// There are only two possible partitions of this array.
// Partition 1: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
// Partition 2: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
// These two partitions are different because, in the 1st partition, S1 contains 5 from index 0, and in the 2nd partition, S1 contains 5 from index 2.


// Time Complexity: O(N*K)
// Reason: There are N*K states therefore at max ‘N*K’ new problems will be solved.

// Space Complexity: O(N*K) + O(N)
// Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*K)).

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int idx, int target, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        if (target == 0 && arr[idx] == 0)
        {
            return 2;
        }
        if (target == arr[idx])
        {
            return 1;
        }
        if (target == 0)
        {
            return 1;
        }

        return 0;
    }

    if (dp[idx][target] != -1)
    {
        return dp[idx][target];
    }

    int nottake = solve(arr, idx - 1, target, dp);

    int take = 0;

    if (target >= arr[idx])
    {
        take = solve(arr, idx - 1, target - arr[idx], dp);
    }

    return dp[idx][target] = take + nottake;
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
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        cout << solve(arr, n - 1, target / 2, dp);
    }
    else
    {
        cout << "0 subsets possible";
    }

    return 0;
}