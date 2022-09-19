// Rod Cutting Problem
//  Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the  maximum value obtainable by cutting up the rod and selling the pieces. 
// Example: 
// if length of the rod is 8 and the values of different pieces are given as following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)


// length   | 1   2   3   4   5   6   7   8  
// --------------------------------------------
// price    | 1   5   8   9  10  17  17  20

#include <bits/stdc++.h>
using namespace std;

int UnboundedRodProfit(int n, int l, vector<int> pieces, vector<int> prices, vector<vector<int>> dp)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < l + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        
        }
    }    

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < l + 1; j++)
        {
            if (pieces[i - 1] <= j)
            {
                dp[i][j] = max(prices[i - 1] + dp[i][j - pieces[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][l];
}
int main()
{
    int n, Length;
    cin >> n >> Length;

    vector<int> pieces(n);
    vector<int> prices(n);
    cout << "Enter pieces of rod - followed by prices :\n";
    for (int i = 0; i < n; i++)
    {
        cin >> pieces[i] >> prices[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(Length + 1, -1));

    int maxprofit = UnboundedRodProfit(n, Length, pieces, prices, dp);
    cout << "Max Profit : " << maxprofit;
    return 0;
}