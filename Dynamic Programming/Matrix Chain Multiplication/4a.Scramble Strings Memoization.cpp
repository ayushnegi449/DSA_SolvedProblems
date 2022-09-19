#include <bits/stdc++.h>
using namespace std;

unordered_map<string,bool> mp;

bool solve(string x, string y)
{
    // base condition
    if (x.compare(y) == 0)
        return true;

    if (x.size() <= 1)
        return false;

    string keyVal = x+" "+y;

    if(mp.count(keyVal)!=0)
    {
        return mp[keyVal];
    }

    int n = x.size();
    bool flag = false;

    for (int i = 1; i <= n - 1; i++)
    {
        bool condition1 = solve(x.substr(0, i), y.substr(0, i)) && solve(x.substr(i, n - i), y.substr(i, n - i));
        bool condition2 = solve(x.substr(0, i), y.substr(n - i, i)) && solve(x.substr(i, n - i), y.substr(0, n - i));
        if (condition1 || condition2)
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