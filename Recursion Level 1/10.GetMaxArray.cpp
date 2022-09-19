#include <bits/stdc++.h>
using namespace std;

int maxarr(int arr[], int index, int size)
{
    if (index == size-1)
    {
        return arr[index];
    }
    int r = maxarr(arr, index + 1, size);
    if (arr[index] > r)
    {
        return arr[index];
    }

    return r;
}

int main()
{
    int arr[5] = {101, 220, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Max value in array is : " << maxarr(arr, 0, size);
    return 0;
}