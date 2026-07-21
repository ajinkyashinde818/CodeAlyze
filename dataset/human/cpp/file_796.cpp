#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = numeric_limits<ll>::max()/3;
const ll mod = 998244353;

int main(void){
  int r,g,b,n;
  cin >> r >> g >> b >> n;
  ll res = 0;
  for(int i = 0;i <= n;i += r){
    int rest = n - i;
    for(int j = 0;j <= rest;j += g){
      if((rest - j) % b == 0)
        ++res;
    }
  }
  cout << res << endl;
  return 0;
}
