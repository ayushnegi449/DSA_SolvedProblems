#include <bits/stdc++.h>
using namespace std;

void printSS(string ques, string ans)
{
    if (ques.size() == 0)
    {
        cout << ans << ",";
        return;
    }

    for (int i = 0; i < ques.length(); i++)
    {
        char ch = ques.at(i);
        string left = ques.substr(0, i);
        string right = ques.substr(i + 1);
        string total = left + right;
        printSS(total, ans + ch);
    }
}

int main()
{
    string str;
    cin >> str;
    cout << "[";
    printSS(str, "");
    cout << "]";
}