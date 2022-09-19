#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> mp;

bool solve(string x, string y)
{
    string keyVal = x + " " + y;

    if (mp.count(keyVal) != 0)
    {
        return mp[keyVal];
    }
    // base condition
    if (x.compare(y) == 0)
        return true;

    if (x.size() <= 1)
        return false;

    int n = x.size();
    bool flag = false;

    for (int i = 1; i <= n - 1; i++)
    {
        string firstSwapKey = x.substr(0, i) + "_" + y.substr(n - i, n);
        string secondSwapKey = x.substr(i, n) + "_" + y.substr(0, n - i);
        string firstNormalKey = x.substr(0, i) + "_" + y.substr(0, i);
        string secondNormalKey = x.substr(i, n) + "_" + y.substr(i, n);
        bool fsk, ssk, fnk, snk;
        
        if (mp.count(firstSwapKey) != 0)
        {
            fsk = mp[firstSwapKey];
        }
        else
        {
            fsk = solve(x.substr(0, i), y.substr(n - i, n));
            mp[firstSwapKey] = fsk;
        }
        if (mp.count(secondSwapKey) != 0)
        {
            ssk = mp[secondSwapKey];
        }
        else
        {
            ssk = solve(x.substr(i, n), y.substr(0, n - i));
            mp[secondSwapKey] = ssk;
        }
        if (mp.count(firstNormalKey) != 0)
        {
            fnk = mp[firstNormalKey];
        }
        else
        {
            fnk = solve(x.substr(0, i), y.substr(0, i));
            mp[firstNormalKey] = fnk;
        }
        if (mp.count(secondNormalKey) != 0)
        {
            snk = mp[secondNormalKey];
        }
        else
        {
            snk = solve(x.substr(i, n), y.substr(i, n));
            mp[secondNormalKey] = snk;
        }
        if ((fsk && ssk) || (fnk && snk))
        {
            flag = true;
            break;
        }
    }
    return mp[keyVal] = flag;
}

int main()
{
    string x, y;
    cin >> x >> y;

    if (x.size() != y.size())
    {
        cout << "Invalid size\n";
        return 0;
    }
    else if (x == "" && y == "")
    {
        cout << "empty strings \n";
        return 0;
    }

    bool res = solve(x, y);

    if (res)
    {
        cout << "Strings are scrambled!\n";
    }
    else
    {
        cout << "Strings are not scrambled!\n";
    }
    return 0;
}
