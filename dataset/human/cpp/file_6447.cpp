#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll mod=1e9+7;

int main(){
  int N;
  string s;
  cin>>N>>s;
  ll cnt(1);
  for (int i(0);i<2*N;i++){
    if (i%2==0) {
      if (s[i]=='W') s[i]='B';
      else if (s[i]=='B') s[i]='W';
    }
  }
  ll cw(0);
  for (int i(0);i<N*2;i++){
    if (s[i]=='W'){
      cw+=1;
    } else {
      cnt*=cw;
      cw--;
      cnt%=mod;
    }
  }
  if (cw!=0) {
    cout << 0 << endl;
    return 0;
  }
  //cout << cnt << endl;
  ll p(1);
  for (int i(1);i<=N;i++){
    p*=i;
    p%=mod;
  }
  cout << (cnt*p)%mod << endl;
  return 0;
}
