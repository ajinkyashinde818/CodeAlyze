#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = numeric_limits<ll>::max()/3;
const ll mod = 1e9 + 7;

int main(void){
  ll n;
  string s;
  cin >> n >> s;
  ll res = 1LL;
  ll now = 0LL;
  for(int i = 0;i < 2*n;++i){
    if((s[i] == 'B' && now % 2 == 0)
       || s[i] == 'W' && now % 2 == 1){
      ++now;
    }else{
      res = (res * now) % mod;
      --now;
    }
  }
  if(now != 0){
    puts("0");
    return 0;
  }
  for(ll i = 1;i <= n;++i){
    res = (res * i) % mod;
  }
  cout << res << endl;
  return 0;
}
