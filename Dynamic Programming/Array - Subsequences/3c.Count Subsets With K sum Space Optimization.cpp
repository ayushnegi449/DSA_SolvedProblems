#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int sum)
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
    int n, sum;
    cin >> n >> sum;

    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << solve(arr, sum);

    return 0;
}