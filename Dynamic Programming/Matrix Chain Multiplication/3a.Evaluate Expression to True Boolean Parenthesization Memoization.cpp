#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

int solution(string &s, int i, int j, bool isTrue)
{
    if (i > j)
    {
        return false;
    }
    if (i == j)
    {
        if (isTrue)
        {
            return s[i] == 'T';
        }
        else
        {
            return s[i] == 'F';
        }
    }

    string keyVal = to_string(i) + "_" + to_string(j) + "_" + to_string(isTrue);

    if (mp.count(keyVal) != 0)
    {
        return mp[keyVal];
    }

    int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int LT = solution(s, i, k - 1, true);
        int LF = solution(s, i, k - 1, false);
        int RT = solution(s, k + 1, j, true);
        int RF = solution(s, k + 1, j, false);

        if (s[k] == '&')
        {
            if (isTrue)
            {
                ans += LT * RT;
            }
            else
            {
                ans += LF * RT + RF * LT + LF * RF;
            }
        }
        else if (s[k] == '|')
        {
            if (isTrue)
            {
                ans += LT * RT + LT * RF + LF * RT;
            }
            else
            {
                ans += LF * RF;
            }
        }
        else if (s[k] == '^')
        {
            if (isTrue)
            {
                ans += LT * RF + LF * RT;
            }
            else
            {
                ans += LT * RT + LF * RF;
            }
        }
    }

    return mp[keyVal] = ans;
}

int main()
{
    string s;
    cin >> s;

    int res = solution(s, 0, s.size() - 1, true);

    cout << res;

    return 0;
}