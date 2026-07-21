#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) ll((a).size())
#define out(a) cout<<(a)<<endl;
const int inf=INT_MAX;
const int MAX = 510000;
const ll MOD = 998244353;


int main(){
  ll r,g,b,n;cin>>r>>g>>b>>n;
  ll ans=0;
  rep(i,0,n/r+1){
    rep(j,0,(n-i*r)/g+1){
      if((n-i*r-j*g)%b==0){
        ans++;
      }
    }
  }
  cout<<ans<<endl;
}
