#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long N;
  string S;
  cin >> N >> S;
  
  vector<long long> c(26,1);
  long long k;
  for (long long i=0;i<N;i++) {
    k=S.at(i)-'a';
    c.at(k)++;
  }
  
  long long m=1;
  for (long long i=0;i<26;i++) {
    m *= c.at(i);
    m = m % 1000000007;
  }
  
  if (m==0) {
    m = 1000000007;
  }
  
  cout << m-1 << endl;
}
