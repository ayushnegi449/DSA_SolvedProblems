/*Scramble String using Recursion
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
Below is one possible representation of A = “great”:
 great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node “gr” and swap its two children, it produces a scrambled string “rgeat”.

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that “rgeat” is a scrambled string of “great”.

Similarly, if we continue to swap the children of nodes “eat” and “at”, it produces a scrambled string “rgtae”.

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that “rgtae” is a scrambled string of “great”.*/

#include <bits/stdc++.h>
using namespace std;

bool solve(string x, string y)
{
    // base condition
    if (x.compare(y) == 0)
        return true;

    if (x.size() <= 1)
        return false;

    int n = x.size();
    bool flag = false;
    for (int i = 1; i <= n - 1; i++)
    {
        bool condition1 = solve(x.substr(0, i), y.substr(0, i)) && solve(x.substr(i, n - i), y.substr(i, n - i));
        bool condition2 = solve(x.substr(0, i), y.substr(n - i, i)) && solve(x.substr(i, n - i), y.substr(0, n - i));
        if (condition1 || condition2)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

int main()
{
    string x, y;
    cin >> x >> y;

    if (x.size() != y.size())
    {
        cout << "Invalid size\n";
        return 0;
    }
    else if (x == "" && y == "")
    {
        cout << "empty strings \n";
        return 0;
    }

    

    if (solve(x, y))
    {
        cout << "Strings are scrambled!\n";
    }
    else
    {
        cout << "Strings are not scrambled!\n";
    }
    return 0;
}