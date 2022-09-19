#include <bits/stdc++.h>
using namespace std;

void printMazePath(int sr, int sc, int dr, int dc, string ans)
{
    if (sr == dr && sc == dc)
    {
        cout << ans << " ";
        return;
    }

    for (int i = 1; i <= dr - sr; i++)
    {
        printMazePath(sr + i, sc, dr, dc, (ans + "v" + to_string(i)));
    }

    for (int i = 1; i <= dc - sc; i++)
    {
        printMazePath(sr, sc + i, dr, dc,(ans + "h" + to_string(i)));
    }

    for (int i = 1; i <= dr - sr && i <= dc - sc; i++)
    {
        printMazePath(sr + i, sc + i, dr, dc, (ans + "d" + to_string(i)));
    }
}

int main()
{
    int dc, dr;
    cout << "Source row and source column of destination\n";
    cin >> dc >> dr;

    cout << "[";
    printMazePath(1, 1, dr, dc, "");
    cout << "]";
    return 0;
}