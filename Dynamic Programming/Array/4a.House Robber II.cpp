#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &house, int n)
{
    if (n == 0)
    {
        return house[n];
    }
    if (n < 0)
    {
        return 0;
    }

    int pick = house[n] + solve(house, n - 2);
    int notpick = solve(house, n - 1);

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

    int res = max(solve(house1, n-2), solve(house2, n-2));

    cout << res;

    return 0;
}

