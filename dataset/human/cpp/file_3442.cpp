#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef vector<pair<ll,ll> > vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
const int MOD = 1000000007;
const int MAX = 510000;

int main(){
  ll n,ans=0,c=0;
  cin>>n;
  vll a(n),b(n);
  rep(i,0,n){
    cin>>a[i];
    if(a[i]<0){c++;}
    b[i]=abs(a[i]);
    ans+=b[i];
  }
  if(c%2==1){
    sort(b.begin(),b.end());
    ans-=b[0]*2;
  }
  cout<<ans<<endl;
}
