#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &wt, vector<int> &price, int idx, int W)
{
    vector<int> prev(W+1,0), curr(W+1);
    for (int j = wt[0]; j <= W; j++)
    {
        prev[j] = price[0];
    }

    for (int i = 1; i < idx; i++)
    {
        for (int j = 1; j < W+1; j++)
        {
            int nottake = prev[j];

            int take = 0;

            if (j >= wt[i])
            {
                take = price[i] + prev[j - wt[i]];
            }

           curr[j] = max(take, nottake);
        }

        prev = curr;
    }

    return prev[W];
}

int main()
{
    int n, W;
    cin >> n >> W;

    vector<int> wt(n, 0), price(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> price[i];
    }

    cout << "max price :  " << solve(wt, price, n, W);

    return 0;
}