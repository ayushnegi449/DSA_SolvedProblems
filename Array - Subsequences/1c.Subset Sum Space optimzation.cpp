// Time Complexity: O(N*K)
// Reason: There are three nested loops

// Space Complexity: O(K)
// Reason: We are using an external array of size ‘K+1’ to store only one row

#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> arr, int target)
{
    int n = arr.size();

    vector<bool> prev(target + 1, false), curr(target + 1, false);

    prev[0] = curr[0] = true; // since at the 0th column ie 0 target , the value is true.

    if (arr[0] <= target)
    {
        prev[arr[0]] = true;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < target + 1; j++)
        {
            bool nottake = prev[j];

            bool take = false;

            if (j >= arr[i])
            {
                take = prev[j - arr[i]];
            }

            curr[j] = take || nottake;
        }

        prev = curr;
    }

    return prev[target];
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