#include <bits/stdc++.h>
using namespace std;

vector<string> s = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "y"};

void PrintKPC(string blank, string toChange)
{
    if (toChange.size() == 0)
    {
        cout << blank << " ,";
        return;
    }

    char code = toChange.at(0);
    string rem = toChange.substr(1, toChange.size() - 1);

    int c = code - '0';
    string option = s.at(c);

    for (int i = 0; i < option.length(); i++)
    {
        char cho = option.at(i);
        PrintKPC(blank + cho, rem);
    }
}

int main()
{
  string str;
    cin >> str;
    cout << "[";
    PrintKPC("", str);
    cout << "]";
    return 0;
}