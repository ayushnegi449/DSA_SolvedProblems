// Target Sum Problem
// Given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

// Find out how many ways to assign symbols to make sum of integers equal to target S.

// Example 1:
// Input: nums is [1, 1, 1, 1, 1], S is 3. 
// Output: 5
// Explanation: 

// -1+1+1+1+1 = 3
// +1-1+1+1+1 = 3
// +1+1-1+1+1 = 3
// +1+1+1-1+1 = 3
// +1+1+1+1-1 = 3

// There are 5 ways to assign symbols to make the sum of nums be target 3.


#include <bits/stdc++.h>
// #include<math.h>
using namespace std;

int countDiffSubset(vector<int> &arr, int n, int sum, vector<vector<int>> dp)
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
        for (int j = 0; j < sum + 1; j++)
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

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sumArr += arr[i];
    }

    if ((diff + sumArr) % 2 != 0 || abs(diff) > sumArr)
        return 0;

    // sort(arr.begin(),arr.end());
    int s1 = (diff + sumArr) / 2;

    vector<vector<int>> dp(n + 1, vector<int>(s1 + 1, -1));

    int counter = countDiffSubset(arr, n, s1, dp);
    cout << "Number of subsets with " << diff << " as difference bw two subsets = " << counter;
    return 0;
}