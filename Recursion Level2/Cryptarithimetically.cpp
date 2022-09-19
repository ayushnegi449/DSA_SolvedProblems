#include <bits/stdc++.h>
using namespace std;

vector<string> s(3);
void decrypt();
void DFS(int characters[], bool isUsed[], int index, vector<int> &idxPos);
bool checkIfDecrypted(int characters[]);
void printConfig(int characters[]);

int main()
{
	cin >> s[0] >> s[1] >> s[2];
	decrypt();
	return 0;
}

void decrypt()
{
	int characters[26];
	vector<int> idxPos;
	fill(characters, characters + 26, INT_MIN);
	for (int i = 0; i < 3; i++)
		for (char c : s[i])
		{
			if (characters[c - 'a'] == INT_MIN)
			{
				characters[c - 'a'] = -1;
				idxPos.push_back(c - 'a');
			}
		}
	bool isUsed[10];
	fill(isUsed, isUsed + 10, false);
	DFS(characters, isUsed, 0, idxPos);
}

void DFS(int characters[], bool isUsed[], int index, vector<int> &idxPos)
{

	if (index >= idxPos.size())
	{
		if (checkIfDecrypted(characters))
			printConfig(characters);
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (!isUsed[i])
		{
			characters[idxPos[index]] = i;
			isUsed[i] = true;
			DFS(characters, isUsed, index + 1, idxPos);
			characters[idxPos[index]] = -1;
			isUsed[i] = false;
		}
	}
}

bool checkIfDecrypted(int characters[])
{
	string num1, num2, num3;

	for (char c : s[0])
		num1 += to_string(characters[c - 'a']);
	for (char c : s[1])
		num2 += to_string(characters[c - 'a']);
	for (char c : s[2])
		num3 += to_string(characters[c - 'a']);

	long long int n1 = stoul(num1), n2 = stoul(num2), n3 = stoul(num3);
	if (n1 + n2 == n3)
		return true;
	return false;
}

void printConfig(int characters[])
{
	char ch;
	for (int i = 0; i < 26; i++)
	{
		if (characters[i] >= 0)
		{
			ch = i + 'a';
			cout << ch << "-" << characters[i] << " ";
		}
	}
	cout << endl;
	return;
}