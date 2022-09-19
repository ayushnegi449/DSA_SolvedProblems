#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int sum, int n)
{
    vector<int> prev(sum + 1, 0), curr(sum + 1, 0);

    prev[0] = curr[0] = true;

    if (sum >= arr[0])
    {
        prev[arr[0]] = true;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            bool nottake = prev[j];

            bool take = false;

            if (j >= arr[i])
            {
                take += prev[j - arr[i]];
            }

            curr[j] = nottake || take;
        }

        prev = curr;
    }

    int minval = INT_MAX;

    for (int j = 0; j <= sum / 2; j++)
    {
        if (prev[j] == true)
        {
            minval = min(minval, abs(sum - (2 * j)));
        }
    }

    return minval;
}

int main()
{
    int n, sum = 0;
    cin >> n;

    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    cout << "Min diff is : " << solve(arr, sum, n);

    return 0;
}