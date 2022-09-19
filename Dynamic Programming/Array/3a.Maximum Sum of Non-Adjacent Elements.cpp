// LC 198 House Robber 1.
//* You are a professional robber planning to rob houses along a street.
//* Each house has a certain amount of money stashed, the only constraint stopping you from robbing
//* each of them is that adjacent houses have security systems connected and it will automatically contact
//* the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house,
// return the maximum amount of money you can rob tonight without alerting the police.

//? Example 1:
// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

#include <bits/stdc++.h>
using namespace std;

int solve(int house[], int n)
{
    if (n == 0)
    {
        return house[n];
    }
    if (n < 0)
    {
        return 0;
    }

    int pick = house[n] + solve(house, n - 2);
    int notpick = solve(house, n - 1);

    return max(pick, notpick);
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << solve(arr, n-1);

    return 0;
}
