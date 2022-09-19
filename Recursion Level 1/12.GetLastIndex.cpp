#include <bits/stdc++.h>
using namespace std;

int arrIndex(int arr[], int index, int size, int search)
{

    if (index >= size)
    {
        return -1;
    }

    int r = arrIndex(arr, index + 1, size, search);

    if (r == -1)
    {
        if (arr[index] == search)
        {
            return index;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return r;
    }

}

int main()
{
    int arr[5] = {101, 40, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int search;
    cout << "Search value : ";
    cin >> search;
    if (arrIndex(arr, 0, size, search) == -1)
    {
        cout << "No index found with value : " << search;
    }
    else
    {
        cout << "value found at index : " << arrIndex(arr, 0, size, search);
    }
    return 0;
}