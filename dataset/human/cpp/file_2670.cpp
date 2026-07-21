#include <bits/stdc++.h>
using namespace std;

int main() 
{
   long long N;
   cin >> N;

   vector<long long> A(N);
   for (long long i = 0; i < N; i++)
      cin >> A.at(i);
   
   long long count = 0;
   long long sum = 0;
   for (long long i = 0; i < N; i++)
   {
      if (A.at(i) <= 0)
      {
         count++;
         A.at(i) *= -1;
      }
      sum += A.at(i);
   }
   
   sort(A.begin(), A.end());

   if (count % 2 == 0)
      cout << sum << endl;
   else
      cout << sum - (2 * A.at(0)) << endl;
}
