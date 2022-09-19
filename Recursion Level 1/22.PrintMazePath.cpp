#include <bits/stdc++.h>
using namespace std;

void printMazePath(int sr, int sc, int dr, int dc, string ans)
{
    if (sr == dr && sc == dc)
    {
        cout << ans << " ";
        return;
    }
    if (sr < dr)
    {
        printMazePath(sr + 1, sc, dr, dc, ans + "v");
    }
    if (sc < dc)
    {
        printMazePath(sr, sc + 1, dr, dc, ans + "h");
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