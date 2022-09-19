#include <bits/stdc++.h>
using namespace std;
void printEncode(string ques, string ans)
{
    if (ques.length() == 0)
    {
        cout << ans << " ";
        return;
    }

    int oneDigit = ques.at(0) - '0';
    char atOne = char('a' + oneDigit - 1);

    int twodigit = stoi(ques.substr(0, 2));
    char atTwo = char('a' + twodigit - 1);

    if (oneDigit != 0)
    {
        printEncode(ques.substr(1), ans + atOne);
    }
    if (twodigit >= 10 && twodigit <= 26)
    {
        printEncode(ques.substr(2), ans + atTwo);
    }
}

int main()
{
    string s;
    cin >> s;
    cout << "[";
    printEncode(s, "");
    cout << "]";
}

