//* There is a frog on the 1st step of an N stairs long staircase.The frog wants to reach the Nth stair.
//* HEIGHT[i] is the height of the(i + 1) th stair.
//* If Frog jumps from ith to jth stair, the energy lost in the jump is given by | HEIGHT[i - 1] - HEIGHT[j - 1] |.
//* In the Frog is on ith staircase, he can jump either to(i + 1) th stair or to(i + 2) th stair.
//* Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.

//? Input Format:
// The first line of the input contains an integer, 'T,’ denoting the number of test cases.
// The first line of each test case contains a single integer,' N’, denoting the number of stairs in the staircase,
// The next line contains ‘HEIGHT’ array.

//? Output Format:
// For each test case, return an integer corresponding to the minimum energy lost to reach the last stair.
// Note:
// You do not need to print anything. It has already been taken care of. Just implement the given function.

//? Constraints:
// 1 <= T <= 10
// 1 <= N <= 100000.
// 1 <= HEIGHTS[i] <= 1000 .

// Time limit: 1 sec

#include <bits/stdc++.h>
using namespace std;

int solve(int jumps[], int idx)
{
    if (idx == 0)
    {
        return 0;
    }

    int jump1 = solve(jumps, idx - 1) + abs(jumps[idx - 1] - jumps[idx]);

    int jump2 = INT_MAX;

    if (idx > 1)
    {
        jump2 = solve(jumps, idx - 2) + abs(jumps[idx - 2] - jumps[idx]);
    }

    return min(jump1, jump2);
}

int main()
{
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << solve(arr, size - 1);

    return 0;
}