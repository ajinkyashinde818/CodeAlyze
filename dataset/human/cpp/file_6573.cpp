#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
using ll=long long;

ll fact(int n) {
  if(n == 1)
    return 1;
  else
    return n*fact(n-1) % mod;
}

int main() {
  int N,i,l,cL=0,cR=0;
  ll r=1;
  string S,d;
  cin >> N >> S;
  l = N*2;
  
  if(S[0]=='W' || S[l-1]=='W') {
    cout << 0 << endl;
    return 0;
  }
  
  d.push_back('L');
  for(i=1; i<l; i++) {
    if(S[i] == S[i-1]) {
      if(d[i-1] == 'L')
        d.push_back('R');
      else
        d.push_back('L');
    } else
      d.push_back(d[i-1]);
  }
  
  for(i=0; i<l; i++)
    if(d[i] == 'L')
      cL++;
  	else
      cR++;
  
  if(cL != cR) {
    cout << 0 << endl;
    return 0;
  }
  cL=0; cR=0;
  
  for(i=0; i<l; i++) {
    if(d[i] == 'R') {
      r *= cL-cR;
      r %= mod;
      cR++;
    } else
      cL++;
  }
  
  cout << r * fact(N) % mod << endl;
}
