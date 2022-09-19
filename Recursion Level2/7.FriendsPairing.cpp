#include <bits/stdc++.h>
using namespace std;

int counter = 1;

void solution(int i, int n, vector<bool> &used, string asf)
{
    if (i > n)
    {
        cout << to_string(counter) + "." + asf << endl;
        counter++;
        return;
    }
    if (used[i])
    {
        solution(i + 1, n, used, asf);
    }
    else
    {
        used[i] = true;
        solution(i + 1, n, used, asf + "(" + to_string(i) + ") ");
        for (int j = i + 1; j <= n; j++)
        {
            if (used[j] == false)
            {
                used[j] = true;
                solution(i + 1, n, used, asf + "(" + to_string(i) + "," + to_string(j) + ") ");
                used[j] = false;
            }
        }
        used[i] = false;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<bool> used(n + 1);

    solution(1, n, used, "");

    return 0;
}