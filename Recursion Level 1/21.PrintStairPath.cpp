#include <bits/stdc++.h>
using namespace std;

void PrintStairPath(int n, string ans)
{
    if (n == 0)
    {
        cout << ans << ",";
    }

    if (n < 0)
    {
        return;
    }
    PrintStairPath(n - 1, ans + "1");
    PrintStairPath(n - 2, ans + "2");
    PrintStairPath(n - 3, ans + "3");
}

int main()
{
    int s;
    cout << "stairs:";
    cin >> s;
    cout << "[";
    PrintStairPath(s, "");
    cout << "]";
    return 0;
}
