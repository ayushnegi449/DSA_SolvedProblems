#include <bits/stdc++.h>
using namespace std;

vector<string> getStairPath(int n)
{
    if (n == 0)
    {
        vector<string> s;
        s.push_back("");
        return s;
    }
    else if (n < 0)
    {
        vector<string> s;
        return s;
    }

    vector<string> path1 = getStairPath(n - 1);
    vector<string> path2 = getStairPath(n - 2);
    vector<string> path3 = getStairPath(n - 3);

    vector<string> paths;

    for (string p : path1)
    {
        paths.push_back("1" + p);
    }
    for (string p : path2)
    {
        paths.push_back("2" + p);
    }
    for (string p : path3)
    {
        paths.push_back("3" + p);
    }

    return paths;
}
int main()
{
    int s;
    cout << "stairs:";
    cin >> s;
    vector<string> ans = getStairPath(s);

    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans.at(i) == ans.at(ans.size() - 1))
        {
            cout << ans.at(i);
        }
        else
        {
            cout << ans.at(i) << ", ";
        }
    }
    cout << "]";
    return 0;
}
