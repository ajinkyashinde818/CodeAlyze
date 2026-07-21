#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;

mat dp(201,vec(201,-1));

ll rec(ll w,ll b) {
  if(dp[w][b]!=-1) return dp[w][b];
  set<ll> grundy;
  if(w>0) grundy.insert(rec(w-1,b));
  for(ll i=1;i<=w;i++) {
    if(b-i>-1) {
      grundy.insert(rec(w,b-i));
    }
  }
  if(b>0) {
    grundy.insert(rec(w+1,b-1));
  }
  ll res=0;
  while(grundy.count(res)) res++;
  return dp[w][b]=res;
}

int main() {
  ll n;
  cin >> n;
  ll grundy=0;
  for(ll i=0;i<n;i++) {
    ll w,b;
    cin >> w >> b;
    grundy^=rec(w,b);
  }
  if(grundy==0) {
    cout << 1 << endl;
  }
  else {
    cout << 0 << endl;
  }
}
