#include <bits/stdc++.h>
using namespace std;

int getNum(string s, map<char, int> charIntMap)
{
    string num = "";
    for (int i = 0; i < s.size(); i++)
    {
        auto it = charIntMap.find(s.at(i));
        string conv = to_string((*it).second);
        num = num + conv;
    }

    int c = stoi(num);

    return c;
}

void solution(string unq, int idx, map<char, int> charIntMap, vector<bool> usedNum, string s1, string s2, string s3)
{
    if (idx == unq.size())
    {
        int num1 = getNum(s1, charIntMap);
        int num2 = getNum(s2, charIntMap);
        int num3 = getNum(s3, charIntMap);

        if (num1 + num2 == num3)
        {
            for (int i = 0; i < 26; i++)
            {
                char ch = 'a' + i;
                if (charIntMap.find(ch) != charIntMap.end())
                {
                    auto it = charIntMap.find(ch);
                    cout << it->first << "-" << it->second;
                }
            }
            cout << endl;
        }
    }

    char ch = unq.at(idx);

    for (int num = 0; num <= 9; num++)
    {
        if (usedNum[num] == false)
        {
            pair<char, int> pr = {ch, num};
            charIntMap.insert(pr);
            usedNum[num] = true;
            solution(unq, idx + 1, charIntMap, usedNum, s1, s2, s3);
            usedNum[num] = false;
            pair<char, int> pr1 = {ch, -1};
            charIntMap.insert(pr1);
        }
    }
}

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    map<char, int> charIntMap;
    string unq = "";

    for (int i = 0; i < s1.size(); i++)
    {
        pair<char, int> s = {s1.at(i), -1};

        if (charIntMap.find(s1.at(i)) == charIntMap.end())
        {
            charIntMap.insert(s);
            unq += s1.at(i);
        }
    }
    for (int i = 0; i < s2.size(); i++)
    {
        pair<char, int> S2 = {s2.at(i), -1};

        if (charIntMap.find(s2.at(i)) == charIntMap.end())
        {
            charIntMap.insert(S2);
            unq += s2.at(i);
        }
    }
    for (int i = 0; i < s3.size(); i++)
    {
        pair<char, int> S3 = {s3.at(i), -1};

        if (charIntMap.find(s3.at(i)) == charIntMap.end())
        {
            charIntMap.insert(S3);
            unq += s3.at(i);
        }
    }

    vector<bool> usedNumbers(10);
    solution(unq, 0, charIntMap, usedNumbers, s1, s2, s3);

    return 0;
}