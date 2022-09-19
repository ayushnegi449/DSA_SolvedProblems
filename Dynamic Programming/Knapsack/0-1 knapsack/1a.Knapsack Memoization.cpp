#include <bits/stdc++.h>
using namespace std;

int knapSackrecur(int W, int N, vector<int> &v, vector<int> &w, vector<vector<int>> &dp)
{
    /* Base case 0 items left or knapsack is full */
    if (N == 0 || W == 0)
        return 0;

    /* Checking if the result exists in DP */

    if (dp[N - 1][W] != -1)
        return dp[N - 1][W];

    /* if weight of current element is less than or equal to capacity we can
    either include or exclude the item and store it to DP. */
    if (w[N - 1] <= W)
    {
        return dp[N - 1][W] = max(v[N - 1] + knapSackrecur(W - w[N - 1], N - 1, v, w, dp), knapSackrecur(W, N - 1, v, w, dp));
    }
    /* if weight of current element is greater than the capacity we will
    not include it thus returning just the ignoring part and storing it to DP. */
    return dp[N - 1][W] = knapSackrecur(W, N - 1, v, w, dp);
}

// int knapsack01(int W, int N, vector<int> &v, vector<int> &w)
// {
//     Defining Dp and initializing with -1.
//     vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));
//     return knapSackrecur(W, N - 1, v, w, dp);
// }



int main()
{
    int size, maxw;
    cout << "Enter size and max weight\n";
    cin >> size >> maxw;
    cout << "\nWEIGHT:\n";

    // int *w = new int[size];
    vector<int> w(size);
    for (int i = 0; i < size; i++)
    {
        cin >> w[i];
    }

    cout << "\nVALUE:\n";
    // int *v = new int[size];
    vector<int> v(size);
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> dp(size + 1, vector<int>(maxw + 1, -1));

    cout << endl
         << "MAX Profit POSSIBLE : " << knapSackrecur(maxw, size, v, w, dp) << endl;
    return 0;
}
