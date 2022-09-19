#include <bits/stdc++.h>
using namespace std;

void parrRecursive(int arr[], int index, int size)
{
    if (index >= size)
    {
        return;
    }
    cout << arr[index] << " ";
    parrRecursive(arr, index + 1,size);
}

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "Printing array recursively :\n";
    parrRecursive(arr, 0,size);
    return 0;
}