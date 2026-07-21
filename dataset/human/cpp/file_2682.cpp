#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll inf = numeric_limits<ll>::max()/3;
const ll mod = 998244353;

ll a[100010];
int invlr[100010];
int invrl[100010];

int main(void){
  int n;
  cin >> n;
  ll sum = 0;
  bool find0 = false;
  for(int i = 0;i < n;++i){
    cin >> a[i];
    if(a[i] == 0)
      find0 = true;
    sum += (ll)abs(a[i]);
  }
  if(find0){
    cout << sum << endl;
    return 0;
  }
  int inv = 1;
  invlr[0] = 1;
  for(int i = 1;i < n;++i){
    if(a[i-1] * invlr[i-1] < 0){
      inv = -1;
    }else{
      inv = 1;
    }
    invlr[i] = inv;
  }
  inv = 1;
  invrl[n-1] = 1;
  for(int i = n-2;i >= 0;--i){
    if(a[i+1] * invrl[i+1] < 0){
      inv = -1;
    }else{
      inv = 1;
    }
    invrl[i] = inv;
  }
  
  ll res = 0;
  for(int i = 0;i < n;++i){
    ll calc = sum - (ll)abs(a[i]) + a[i] * invlr[i] * invrl[i];
    res = max(res, calc);
  }
  cout << res << endl;
  return 0;
}
