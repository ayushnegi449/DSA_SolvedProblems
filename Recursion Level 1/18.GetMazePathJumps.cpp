#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> GetMazePathJumps(int sr, int sc, int dr, int dc)
{
    if (sr == dr && sc == dc)
    {
        vector<string> r;
        r.push_back("");
        return r;
    }

    vector<string> ans;

    for (int jump = 1; jump <= dc - sc; jump++)
    {
        vector<string> h_paths = GetMazePathJumps(sr, sc + jump, dr, dc);

        for (string str : h_paths)
        {
            ans.push_back("h" + to_string(jump) + str);
        }
    }

    for (int jump = 1; jump <= dr - sr; jump++)
    {
        vector<string> v_paths = GetMazePathJumps(sr + jump, sc, dr, dc);
        for (string str : v_paths)
        {
            ans.push_back("v" + to_string(jump) + str);
        }
    }

    for (int jump = 1; jump <= dr - sr && jump <= dc - sc; jump++)
    {
        vector<string> d_paths = GetMazePathJumps(sr + jump, sc + jump, dr, dc);
        for (string str : d_paths)
        {
            ans.push_back("d" + to_string(jump) + str);
        }
    }
    return ans;
}


int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> ans = GetMazePathJumps(1, 1, n, m);
    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i < ans.size() - 1)
            cout << ", ";
    }

    cout << "]" << endl;

    return 0;
}