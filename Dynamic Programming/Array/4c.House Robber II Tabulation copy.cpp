#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &house, int n, int dp[])
{
    dp[0] = house[0];

    for (int i = 1; i <= n; i++)
    {
        int pick = house[i];

        if (i > 1)
        {
            pick += dp[i - 2];
        }

        int notpick = dp[i - 1];

        dp[i] = max(pick, notpick);
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    vector<int> house(n, 0), house1, house2;

    for (int i = 0; i < house.size(); i++)
    {
        cin >> house[i];

        if (i != 0)
        {
            house1.push_back(house[i]);
        }
        if (i != house.size() - 1)
        {
            house2.push_back(house[i]);
        }
    }

    int dp[n];

    memset(dp, -1, sizeof(dp));
    int l = solve(house1, n - 2, dp);

    memset(dp, -1, sizeof(dp)); // need to do memset after above function, which is already storing values in dp.
    int r = solve(house2, n - 2, dp);

    // return max(solve(vector<int>(nums.begin(),nums.end()-1)),solve(vector<int>(nums.begin()+1,nums.end()))); //shortcut

    cout << max(l, r);

    return 0;
}
