#include <bits/stdc++.h>
using namespace std;

void printSubsets(int arr[], int target, int sum, int index, string ans, int size)
{
    if (index == size)
    {
        if (sum == target)
        {
            cout << "{" << ans << "},";
        }

        return;
    }

    printSubsets(arr, target, arr[index] + sum, index + 1, ans + to_string(arr[index]) + " ", size);
    printSubsets(arr, target, sum, index + 1, ans, size);
}

int main()
{
    int size, target;
    cout << "Enter size of array and target :\n";
    cin >> size >> target;
    int *arr = new int[size];
    cout << "Enter the elements in array : \n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "{";
    printSubsets(arr, target, 0, 0, "", size);
    cout << "}";

    return 0;
}