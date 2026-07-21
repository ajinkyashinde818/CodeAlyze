#include <bits/stdc++.h>
using namespace std;

long long Q = 1000000007;

int main()
{
  int N;
  string S;
  cin >> N >> S;
  
  vector<char> A = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 
                   'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 
                   'z', 'x', 'c', 'v', 'b', 'n', 'm'};
  vector<int> B(30, 0);
  
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < 26; j++) 
    {
      if (S.at(i) == A.at(j)) B.at(j)++;
    }
  }
  
  long long ans = 1;
  for (int i = 0; i < 26; i++)
  {
    ans = ans * (B.at(i) + 1) % Q;
  }
  ans = (ans - 1) % Q;
  
  cout << ans << endl;
}
