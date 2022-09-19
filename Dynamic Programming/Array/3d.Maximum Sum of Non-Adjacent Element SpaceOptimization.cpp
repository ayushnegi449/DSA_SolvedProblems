#include <bits/stdc++.h>
using namespace std;

int solve(int house[], int n)
{
    int prev = house[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int pick = house[i];
        if (i > 1)
        {
            pick += prev2;
        }
        int notpick = prev;

        int curr = max(pick, notpick);

        prev2 = prev;
        prev = curr;
    }

    return prev;
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
    cout << solve(arr, n);

    return 0;
}
