// Eliminating space consumed / used by dp array , o(n). Making the space used = O(1).
#include <bits/stdc++.h>
using namespace std;

int solve(int jump[], int n)
{
    int prev2 = 0, prev = 0; // initially stores jump[i-2] where i will be 1 initially , (for loop below); so 1-2 = -1 which doesnt exists => prev2 =0;

    for (int i = 1; i < n; i++)
    {
        int jump1 = prev + abs(jump[i] - jump[i - 1]);

        int jump2 = INT_MAX;

        if (i > 1)
        {
            jump2 = prev2 + abs(jump[i] - jump[i - 2]);
        }

        int curIdx = min(jump1,jump2);

        prev2 = prev;
        prev = curIdx; 
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