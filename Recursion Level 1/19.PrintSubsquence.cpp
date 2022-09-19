#include <bits/stdc++.h>
using namespace std;

void printSS(string ques, string ans)
{
    if (ques.size() == 0)
    {
        cout <<ans << ",";
        return;
    }

    string ch = ques.substr(0, 1);
    string rem = ques.substr(1);

    printSS(rem,ans+"");
    printSS(rem,ans+ch);
    return;
   
}


int main(){
    string str;
    cin >> str;
    cout<<"[";
    printSS(str, "");
    cout<<"]";
}