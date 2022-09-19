#include <bits/stdc++.h>
using namespace std;

void bfs(int start, int number)
{
    if (start > number)
    {
        return;
    }
    cout << start << " ";
    for (int i = 0; i < 10; i++)
    {
        bfs(10 * start + i, number);
    }

    return;
}

int main()
{
    int number;
    cin >> number;
    for (int i = 1; i < 10; i++)
    {
        bfs(i, number);
        cout << endl;
    }
    return 0;
}