#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(1000, vector<int>(1000, -1));

int EDFsolve(int e, int f)
{
    if (dp[e][f] != -1)
    {
        return dp[e][f];
    }
    if (f == 0 || f == 1)
    {
        return f;
    }
    if (e == 1)
    {
        return f;
    }
    if (e == 0)
    {
        return 0;
    }

    int minVal = INT_MAX;

    for (int k = 1; k <= f; k++)
    {
        int low = 0, high = 0;

        if (dp[e - 1][k - 1] != -1)
        {
            low = dp[e - 1][k - 1];
        }
        else
        {
            low = EDFsolve(e - 1, k - 1);
            dp[e - 1][k - 1] = low;
        }

        if (dp[e][f - k] != -1)
        {
            high = dp[e][f - k];
        }
        else
        {
            high = EDFsolve(e, f - k);
            dp[e][f - k] = high;
        }
        
        int temp = 1 + max(low, high); // 1 attempt taken so 1+ and Max of (egg breaks , egg not breaks)

        if (temp < minVal)
            minVal = temp; // Min of the worst attemps.
    }

    return dp[e][f] = minVal;
}

int main()
{
    int e, f;
    cin >> e >> f;

    int res = EDFsolve(e, f);

    cout << "Minimum attempts to break egg : " << res;

    return 0;
}