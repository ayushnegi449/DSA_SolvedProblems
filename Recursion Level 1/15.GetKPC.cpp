#include <bits/stdc++.h>
using namespace std;

vector<string> s = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "y"};

vector<string> getKPC(string input)
{
    if (input.size() == 0)
    {
        vector<string> s;
        s.push_back("");
        return s;
    }

    char ch = input.at(0);
    string str = input.substr(1);

    vector<string> ans = getKPC(str);

    vector<string> output;

    int number = ch - '0';

    for (int i = 0; i < s.at(number).size(); i++)
    {
        char newchar = s.at(number).at(i);
        for (string str : ans)
        {
            output.push_back(newchar + str);
        }
    }

    return output;
}

int main()
{
    string s;
    cout << "string:";
    cin >> s;
    vector<string> ans = getKPC(s);

    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans.at(i) == ans.at(ans.size() - 1))
        {
            cout << ans.at(i);
        }
        else
        {
            cout << ans.at(i) << ", ";
        }
    }
    cout << "]";
    return 0;
}


// LEETCODE SOLUTION
/*class Solution
{
public:
    vector<string> s = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> KPC(string ques, int idx)
    {

        if (ques.size() == 0 && idx > 0)
        {
            vector<string> base;
            base.push_back("");
            return base;
        }
        if (ques.size() == 0 && idx == 0)
        {
            vector<string> s;
            return s;
        }

        char x = ques.at(0);
        string y = ques.substr(1);

        vector<string> ans = KPC(y, idx + 1);

        vector<string> total;

        int size = x - 48;

        for (int i = 0; i < s.at(size).size(); i++)
        {
            char a = s.at(size).at(i);

            for (string val : ans)
            {
                total.push_back(a + val);
            }
        }

        return total;
    }

    vector<string> letterCombinations(string digits)
    {
        return KPC(digits, 0);
    }
};*/