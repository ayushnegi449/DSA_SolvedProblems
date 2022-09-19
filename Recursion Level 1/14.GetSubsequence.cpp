#include <bits/stdc++.h>
using namespace std;

vector<string> gss(string s)
{
    if (s.size() == 0)
    {
        vector<string> str;
        str.push_back("");
        return str;
    }
    string s1 = s.substr(0, 1); // a

    string str = s.substr(1, s.size()); // bc

    vector<string> result = gss(str); // faith : -c,b-,bc,--

    vector<string> tot;

    for (string substr : result)
    {
        tot.push_back("" + substr);
    }

    for (string substr : result)
    {
        tot.push_back(s1 + substr);
    }

    return tot;
}

int main()
{
    string str1;
    cout << "Enter your string :";
    cin >> str1;
    vector<string> str = gss(str1);
    cout << "[";
    for (auto it = str.begin(); it != str.end(); it++)
    {
       if(*it==str.at(str.size()-1))
       {
        cout<<*it;
       }
       else
       {
        cout<<*it<<", ";
       }
    }
    cout << "]";

    return 0;
}
