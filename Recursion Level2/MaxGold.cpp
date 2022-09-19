#include <bits/stdc++.h>
#include<math.h>
using namespace std;

int getMaximumGold(int[][] grid)
{
    final int row = grid.length;
    final int col = grid[0].length;
    final boolean[][] visited = new boolean[row][col];
    int maxGold = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] != 0 && !visited[i][j])
            {
                final int pathGold = fillBag(grid, visited, i, j, 0);
                maxGold = Math.max(maxGold, pathGold);
            }
        }
    return maxGold;
}

int fillBag(final int[][] arr, final boolean[][] visited, final int row, final int col, int pathGold)
{
    if (row < 0 || col < 0 || row >= arr.length || col >= arr[0].length || visited[row][col] || arr[row][col] == 0)
    {
        return pathGold;
    }
    
    visited[row][col] = true;
    int maxGold = pathGold;

    pathGold += arr[row][col];
    // move up
    maxGold = Math.max(maxGold, fillBag(arr, visited, row - 1, col, pathGold));
    // move down
    maxGold = Math.max(maxGold, fillBag(arr, visited, row + 1, col, pathGold));
    // move left
    maxGold = Math.max(maxGold, fillBag(arr, visited, row, col - 1, pathGold));
    // move right
    maxGold = Math.max(maxGold, fillBag(arr, visited, row, col + 1, pathGold));
    visited[row][col] = false;
    return maxGold;
}


int main()
{
    int size;
    cin >> size;
    vector<vector<int>> v(size, vector<int>(size, 0));

int res = fillBag()

    return 0;
}