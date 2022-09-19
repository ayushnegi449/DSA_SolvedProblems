#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &house, int n,int dp[])
{
    if (n == 0)
    {
        return house[n];
    }
    if (n < 0)
    {
        return 0;
    }

    int pick = house[n] + solve(house, n - 2,dp);
    int notpick = solve(house, n - 1,dp);

    return max(pick, notpick);
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
        if (i != house.size()-1)
        {
            house2.push_back(house[i]);
        }
    }

    int dp[n];

    memset(dp,-1,sizeof(dp));
    int l= solve(house1, n-2,dp);

    memset(dp,-1,sizeof(dp)); //need to do memset after above function, which is already storing values in dp.
    int r=  solve(house2, n-2,dp);

    cout << max(l,r);

    return 0;
}


