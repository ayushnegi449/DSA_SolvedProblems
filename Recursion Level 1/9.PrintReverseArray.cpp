#include <bits/stdc++.h>
using namespace std;

void arrReverse(int arr[], int index, int size)
{
    if (index >= size)
    {
        return;
    }
    arrReverse(arr, index + 1, size);
    cout << arr[index] << " ";
}

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Printing array recursively :\n";
    arrReverse(arr, 0, size);
    return 0;
}