#include <bits/stdc++.h>
using namespace std;

int solve(int jump[], int ind)
{
    if (ind == 0)
        return 0;

    int minval = INT_MAX;

    for (int k = 1; k <= ind; k++)
    {
        int l = 0;
        if (ind - k >= 0)
        {
            l = solve(jump, ind - k) + abs(jump[ind] - jump[ind - k]);
            
            if (l < minval)
            {
                minval = l;
            }
        }
    }

    return minval;
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