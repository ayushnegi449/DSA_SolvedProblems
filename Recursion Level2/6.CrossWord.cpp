#include <bits/stdc++.h>
using namespace std;

void printCrossword(vector<vector<char>> &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = 0; j < array.size(); j++)
        {
            cout << array[i][j];
        }
        cout << endl;
    }
}

bool canPlaceHorizontally(vector<vector<char>> &array, string word, int i, int j)
{
    if (j - 1 >= 0 && array[i][j - 1] != '+')
    {
        return false;
    }
    if (j + word.size() < array[i].size() && array[i][j + word.size()] != '+')
    {
        return false;
    }

    for (int k = 0; k < word.size(); k++)
    {
        if (j + k >= array[i].size())
        {
            return false;
        }

        char ch = word.at(k);
        if (array[i][j + k] == '-' || array[i][j + k] == ch)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool canPlaceVertically(vector<vector<char>> &array, string word, int i, int j)
{
    if (i - 1 >= 0 && array[i - 1][j] != '+')
    {
        return false;
    }
    if (i + word.size() < array.size() && array[i + word.size()][j] != '+')
    {
        return false;
    }

    for (int k = 0; k < word.size(); k++)
    {
        if (i + k >= array.size())
        {
            return false;
        }

        char ch = word.at(k);
        if (array[i + k][j] == '-' || array[i + k][j] == ch)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

vector<bool> placeHorizontal(vector<vector<char>> &array, string word, int i, int j)
{
    vector<bool> placed(word.size(), false);
    for (int h = 0; h < word.size(); h++)
    {
        if (array[i][j + h] == '-')
        {
            array[i][j + h] = word.at(h);
            placed[h] = true;
        }
    }

    return placed;
}

vector<bool> placeVertical(vector<vector<char>> &array, string word, int i, int j)
{
    vector<bool> placed(word.size(), false);
    for (int h = 0; h < word.size(); h++)
    {
        if (array[i + h][j] == '-')
        {
            array[i + h][j] = word.at(h);
            placed[h] = true;
        }
    }

    return placed;
}

void UnplaceHorizontal(vector<vector<char>> &array, vector<bool> &placed, int i, int j)
{
    for (int h = 0; h < placed.size(); h++)
    {
        if (placed[h] == true)
        {
            array[i][j + h] = '-';
        }
    }
}

void UnplaceVertical(vector<vector<char>> &array, vector<bool> &placed, int i, int j)
{
    for (int v = 0; v < placed.size(); v++)
    {
        if (placed[v] == true)
        {
            array[i + v][j] = '-';
        }
    }
}

void solveCrossword(vector<vector<char>> &array, vector<string> &words, int sIndex)
{
    if (sIndex == words.size())
    {
        printCrossword(array);
        return;
    }

    string word = words.at(sIndex);

    for (int i = 0; i < array.size(); i++)
    {
        for (int j = 0; j < array[0].size(); j++)
        {
            if (array[i][j] == '-' || array[i][j] == word.at(0))
            {
                if (canPlaceHorizontally(array, word, i, j))
                {
                    vector<bool> h = placeHorizontal(array, word, i, j);
                    solveCrossword(array, words, sIndex + 1);
                    UnplaceHorizontal(array, h, i, j);
                }

                if (canPlaceVertically(array, word, i, j))
                {
                    vector<bool> v = placeVertical(array, word, i, j);
                    solveCrossword(array, words, sIndex + 1);
                    UnplaceVertical(array, v, i, j);
                }
            }
        }
    }
}

int main()
{
    int row = 10, col = 10;
    vector<vector<char>> chararray(row, vector<char>(col));
    for (int i = 0; i < chararray.size(); i++)
    {
        for (int j = 0; j < chararray.at(0).size(); j++)
        {
            // string str;
            // cin >> str;
            // for (int s = 0; s < str.length(); s++)
            // {
            //     chararray[i][j] = str.at(s);
            // }
            cin >> chararray[i][j];
        }
    }

    int n;
    cin >> n;

    vector<string> words(n, "");

    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    solveCrossword(chararray, words, 0);

    return 0;
}