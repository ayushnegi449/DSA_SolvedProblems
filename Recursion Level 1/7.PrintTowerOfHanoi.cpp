#include <bits/stdc++.h>
using namespace std;

void toh(string source, string dest, string helper, int disks)
{
    if (disks == 0)
    {
        return;
    }
    toh(source, helper, dest, (disks - 1));
    cout << disks << "-->(" << source << "," << dest << ")" << endl;
    toh(helper, dest, source, (disks - 1));
}

int main()
{
    int disks;

    cout << "Enter the number of disks :";
    cin >> disks;
    cout << "Instructions :\n";
    toh("A", "B", "C", disks);
    return 0;
}