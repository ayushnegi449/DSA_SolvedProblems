/*Example:
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
In  other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items  respectively. 
Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum  of the weights of this subset 
is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick  it (0-1 property).*/

#include <bits/stdc++.h>
using namespace std;

int knapsack(int w[], int v[], int maxw, int n)
{
    if (n == -1 || maxw == 0)
    {
        return 0;
    }

    if (w[n] <= maxw)
    {
        int res = max((v[n] + knapsack(w, v, maxw - w[n], n - 1)), knapsack(w, v, maxw, n - 1));
        return res;
    }
    else if (w[n] > maxw)
    {
        return knapsack(w, v, maxw, n - 1);
    }
}

int main()
{
    int size, maxw;
    cout << "Enter size and max weight\n";
    cin >> size >> maxw;
    cout << "\nWEIGHT:\n";

    int *w = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> w[i];
    }

    cout << "\nVALUE:\n";
    int *v = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }

    cout << endl
         << "MAX Profit POSSIBLE : " << knapsack(w, v, maxw, size - 1) << endl;
    return 0;
}