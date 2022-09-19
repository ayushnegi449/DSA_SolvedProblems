#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(100, vector<int>(100, -1));

int MCM(int arr[], int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int minval = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = MCM(arr, i, k) + MCM(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        if (temp < minval)
        {
            minval = temp;
        }
    }

    return dp[i][j] = minval;
}

int main()
{
    int size;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int minCost = MCM(arr, 1, size - 1);

    cout << "Min Cost of MCM : " << minCost;
    return 0;
}