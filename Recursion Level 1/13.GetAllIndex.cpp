#include <iostream>
#include <vector>
using namespace std;

// vector<int> allIndex(vector<int> arr, int idx, int data, int count)
// {
//     if (idx == arr.size())
//     {
//         vector<int> base(count, 0);
//         return base;
//     }

//     if (arr[idx] == data)
//     {
//         count++;
//     }

//     vector<int> ans = allIndex(arr, idx + 1, data, count);

//     if (arr[idx] == data)
//     {
//         ans[count - 1] = idx;
//     }

//     return ans;
// }

vector<int> allIndex(vector<int> arr, int idx, int data, int count)
{
    if (idx == arr.size())
    {
        vector<int> base(count, 0);
        return base;
    }

    if (arr[idx] == data)
    {
        vector<int> ans = allIndex(arr, idx + 1, data, count + 1);
        ans[count] = idx;
        return ans;
    }

    else
    {
        vector<int> ans = allIndex(arr, idx + 1, data, count);
        return ans;
    }

}

int main()
{
    vector<int> arr;
    int n, d, data;
    cout << "Enter the size :";
    cin >> n;
    cout << "Enter the elements :\n";
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        arr.push_back(d);
    }
    cout << "Enter the element you want to search for:\n";
    cin >> data;
    vector<int> ans = allIndex(arr, 0, data, 0);
    if (ans.size() == 0)
    {
        cout << endl;
        return 0;
    }
    for (auto it = ans.begin(); it != ans.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}