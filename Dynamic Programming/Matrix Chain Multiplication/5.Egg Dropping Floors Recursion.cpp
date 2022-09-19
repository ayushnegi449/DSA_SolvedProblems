//* Egg Dropping using Recursion
//* Problem statement: You are given N floor and K eggs. You have to minimize the number of times you have to drop the eggs to find the critical floor where critical floor means the floor beyond which eggs start to break. Assumptions of the problem:

//* If egg breaks at ith floor then it also breaks at all greater floors.
//* If egg does not break at ith floor then it does not break at all lower floors.
//* Unbroken egg can be used again.
//* Note: You have to find minimum trials required to find the critical floor not the critical floor.

//* Example:
//* Input:
//*     4
//*     2

//*     Output:
//*     Number of trials when number of eggs is 2 and number of floors is 4: 3
#include <bits/stdc++.h>
using namespace std;

int EDFsolve(int e, int f)
{
    if (f == 0 || f == 1)
        return f;

    if (e == 1)
        return f;

    if (e == 0)
        return 0;

    int minVal = INT_MAX;

    for (int k = 1; k <= f; k++)
    {
        int temp = 1 + max(EDFsolve(e - 1, k - 1), EDFsolve(e, f - k)); // 1 attempt taken so 1+ and Max of (egg breaks , egg not breaks)

        if (temp < minVal)
            minVal = temp; // Min of the worst attemps.
    }

    return minVal;
}

int main()
{
    int e, f;
    cin >> e >> f;

    int res = EDFsolve(e, f);

    cout << "Minimum attempts to break egg : " << res;

    return 0;
}