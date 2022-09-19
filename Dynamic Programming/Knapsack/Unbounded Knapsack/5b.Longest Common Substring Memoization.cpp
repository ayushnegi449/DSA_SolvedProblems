#include <bits/stdc++.h>
using namespace std;

pair<string,int> p;
unordered_map<string, int> store;

int ans(string s1, string s2, int n, int m, int len)
{
    if (n == 0 || m == 0)
    {
        return len;
    }

    string k = to_string(n)+to_string(m)+to_string(len);

    if(store.find(k)!=store.end())
    {
        auto it = store.find(k);
        return it->second;
    }

    int counter = len;

    if (s1[n - 1] == s2[m - 1])
    {
        counter = ans(s1, s2, n - 1, m - 1, len + 1);
    }

    int len1 = ans(s1, s2, n - 1, m, 0);
    int len2 = ans(s1, s2, n, m - 1, 0);

    int res = max({counter, len1, len2});

    p ={k,res};
    store.insert(p);

    return res;
}

int main()
{

    string s1, s2;
    cin >> s1 >> s2;
    cout << ans(s1, s2, s1.size(), s2.size(), 0) << endl;

    return 0;
}