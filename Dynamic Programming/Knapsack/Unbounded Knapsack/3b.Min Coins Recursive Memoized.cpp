#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

int coinCount(int cs[], int amt, int size, int curr)
{
    if (amt == 0)
    {
        return 0;
    }
    if (amt < 0 || curr >= size)
    {
        return INT_MAX - 1;
    }

    int res = -1;
    string x = to_string(amt) + "_" + to_string(curr);

    if (mp.count(x) != 0)
    {
        return mp[x];
    }

    if (cs[curr] <= amt)
    {
        res = min(1 + coinCount(cs, amt - cs[curr], size, curr), coinCount(cs, amt, size, curr + 1));
    }
    else if (cs[curr] > amt)
    {
        res = coinCount(cs, amt, size, curr + 1);
    }

    return res;
}

int main()
{
    int size, amt;
    cin >> size >> amt;

    int cs[size];
    for (int i = 0; i < size; i++)
    {
        cin >> cs[i];
    }

    int res = coinCount(cs, amt, size, 0);

    cout << "Req coins : " << res;

    return 0;
}

// int coinCount(int cs[], int amt, int size, int curr,	vector<vector<int>> &dp)
// {
//     if (amt == 0)
//     {
//         return 0;
//     }
//     if (amt < 0 || curr >= size)
//     {
//         return INT_MAX - 1;
//     }

//     if (dp[curr][amt]!=-1)
//     {
//       return dp[curr][amt] ;
//     }
    
//        int res = -1;
//     if (cs[curr] <= amt)
//     {
//         res = min(1 + coinCount(cs, amt - cs[curr], size, curr, dp), coinCount(cs, amt, size, curr + 1, dp));
//     }
//     else if (cs[curr] > amt)
//     {
//         res = coinCount(cs, amt, size, curr + 1, dp);
//     }

//     return dp[curr][amt] = res;
// }