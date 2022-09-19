#include <bits/stdc++.h>
using namespace std;

vector<string> getMazePath(int sr, int sc, int dr, int dc)
{
    if (sr == dr && sc == dc)
    {
        vector<string> s;
        s.push_back("");
        return s;
    }

    vector<string> hpath;
    vector<string> vpath;

    if (sr < dr)
    {
        vpath = getMazePath(sr + 1, sc, dr, dc);
    }
    if (sc < dc)
    {
        hpath = getMazePath(sr, sc + 1, dr, dc);
    }

    vector<string> mpath;

    for (string path : hpath)
    {
        mpath.push_back("h" + path);
    }
    for (string path : vpath)
    {
        mpath.push_back("v" + path);
    }

    return mpath;
}
int main()
{
    int dc,dr;
    cout << "Source row and source column of destination\n";
    cin >> dc >> dr;
    vector<string> ans = getMazePath(1, 1, dr, dc);

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
