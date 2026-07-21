#include<bits/stdc++.h>
using namespace std;
using Int = long long;
using ll = long long;
template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b){if(a > b) a = b;}
template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b){if(a < b) a = b;}
#define F first
#define S second

signed solve(){
  ll t;
  cin>>t;
  ll ans=t;
  for(ll i=1;;i++){
    ll res=1,cnt=i+i;
    for(ll j=0,k=1;j<i;j++){
      k*=3;
      //res+=k*2;
      res+=k;
      if(j+1<i) res+=k;
      if(k>t) break;
    }
    if(res>t) break;
    ll tmp=t-res;
    ll num=i;
    while(tmp&&num){
      cnt+=tmp%3;
      tmp/=3;
      num--;
    }
    cnt+=tmp;
    //cout<<i<<":"<<t-res<<" "<<cnt<<endl;
    chmin(ans,cnt);
  }
  cout<<ans<<endl;
  return 0;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  solve();
  return 0;
}
