#include <bits/stdc++.h>
using namespace std;

int counter = 1;

void solution(vector<vector<int>> &pairing, int s, int n, int pairs, int k)
{
   if (s == n + 1)
   {
      if (pairs == k)
      {
         cout << counter << ". ";
         // for (int i = 0; i < pairing.size(); i++)
         // {
         //    for (int j = 0; j < pairing[i].size(); j++)
         //    {
         //       if (pairing[i][j] == 0)
         //       {
         //          continue;
         //       }
         //       else
         //       {
         //          cout << pairing[i][j] << " ";
         //       }
         //    }
         //    cout << endl;
         // }

         for (vector<int> i : pairing)
         {
            for (int pr : i)
            {
               cout << "[" << pr << "] ";
            }
         }

         // for (auto &i : pairing)
         // {
         //    cout<<i<<" ";
         // }

         cout << endl;
         counter++;
      }

      return;
   }

   for (int i = 0; i < k; i++)
   {
      if (pairing[i].size() > 0)
      {
         pairing[i].push_back(s);
         solution(pairing, s + 1, n, pairs, k);
         pairing[i].pop_back();
      }
      else
      {
         pairing[i].push_back(s);
         solution(pairing, s + 1, n, pairs + 1, k);
         pairing[i].pop_back();
         break;
      }
   }
}

int main()
{
   int num, k;
   cout << "num + k : \n";
   cin >> num >> k;

   vector<vector<int>> pairing(k);

   solution(pairing, 1, num, 0, k);

   return 0;
}