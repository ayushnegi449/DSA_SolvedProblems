#include <bits/stdc++.h>
using namespace std;

void printabr(string ques, string ans, int count, int pos)
{
    if (pos == ques.length())
    {
        if (count == 0)
        {
            cout << ans << " ";
        }
        else if (count != 0)
        {
            cout << ans + to_string(count) << " ";
        }
        return;
    }

    if (count > 0)
    {
        printabr(ques, ans + to_string(count) + ques.at(pos), 0, pos + 1);
    }
    else
    {
        printabr(ques, ans + ques.at(pos), 0, pos + 1);
    }
    printabr(ques, ans, count + 1, pos + 1);
}

int main()
{
    string s;
    cout << "enter your STRING : \n";
    cin >> s;

    printabr(s, "", 0, 0);

    return 0;
}