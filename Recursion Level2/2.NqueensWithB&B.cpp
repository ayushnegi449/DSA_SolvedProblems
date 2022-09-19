#include <bits/stdc++.h>
using namespace std;

void nQueenBranchAndBoundAlgo(vector<vector<bool>> &array, int row, bool c[], bool d[], bool rd[], string ans)
{
    if (row == array.size())
    {
        cout << ans << ".\n";
        return;
    }
    for (int col = 0; col < array[0].size(); col++)
    {
        if (c[col] ==false&& d[row + col]==false && rd[(row - col) + (array.size() - 1)]==false && array[row][col]==false)
        {
            array[row][col] = true;
            c[col] = true;
            d[row + col] = true;
            rd[row - col + array.size() - 1] = true;
            nQueenBranchAndBoundAlgo(array, row + 1, c, d, rd, ans + to_string(row) + "-" + to_string(col) + ", ");
            array[row][col] = false;
            c[col] = false;
            d[row + col] = false;
            rd[row - col + array.size() - 1] = false;
        }
    }
}
int main()
{
    int size;
    cin >> size;
    vector<vector<bool>> v(size, vector<bool>(size, false));
    bool *c = new bool[size];
    bool *d = new bool[2 * size - 1];
    bool *rd = new bool[2 * size - 1];

    nQueenBranchAndBoundAlgo(v, 0, c, d, rd, "");
    return 0;
}