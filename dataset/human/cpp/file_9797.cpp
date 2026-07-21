#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int Q=1000000007;

int main(){
  int N;
  string S;
  cin >>N >> S;
  vector<ll> P(26,0);
  for(int i=0;i<N;i++){
    P[S[i]-'a'] ++;
  }
  sort(P.begin(),P.end());
  reverse(P.begin(),P.end());
  ll ans=0;
  for(int i=0;i<26;i++){
    ans = ans*((P[i]+1)%Q)%Q;
    ans = (ans+P[i])%Q;
  }
  cout << ans << endl;
}
