// Evaluate Expression To True-Boolean Parenthesization Memoized
// Given a boolean expression with following symbols.
// Symbols
//     'T' --- true
//     'F' --- false
// And following operators filled between symbols
// Operators
//     &   --- boolean AND
//     |   --- boolean OR
//     ^   --- boolean XOR
// Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.
// Example:
// Input: symbol[]    = {T, F, T}
//        operator[]  = {^, &}
// Output: 2
// The given expression is "T ^ F & T", it evaluates true
// in two ways "((T ^ F) & T)" and "(T ^ (F & T))"

#include <bits/stdc++.h>
using namespace std;

int solution(string &s, int i, int j, bool isTrue)
{
    if (i > j)
    {
        return false;
    }
    if (i == j)
    {
        if (isTrue)
        {
            return s[i] == 'T';
        }
        else
        {
            return s[i] == 'F';
        }
    }
    

    int ans = 0;

    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int LT = solution(s, i, k - 1, true);
        int LF = solution(s, i, k - 1, false);
        int RT = solution(s, k + 1, j, true);
        int RF = solution(s, k + 1, j, false);

        if (s[k] == '&')
        {
            if (isTrue)
            {
                ans += LT * RT;
            }
            else
            {
                ans += LF * RT + RF * LT + LF * RF;
            }
        }
        else if (s[k] == '|')
        {
            if (isTrue)
            {
                ans += LT * RT + LT * RF + LF * RT;
            }
            else
            {
                ans += LF * RF;
            }
        }
        else if (s[k] == '^')
        {
            if (isTrue)
            {
                ans += LT * RF + LF * RT;
            }
            else
            {
                ans += LT * RT + LF * RF;
            }
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;

    int res = solution(s, 0, s.size() - 1, true);

    cout << res;

    return 0;
}