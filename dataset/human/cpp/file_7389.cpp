#include <bits/stdc++.h>
#include<algorithm>
#include<math.h>
using namespace std;
 
template <class T> using V = vector<T>;
 
using ll = long long;
using db = double;
using st = string;
using ch = char;
using vll = V<ll>;
using vpll =V<pair<ll,ll>>;
using vst = V<st>;
using vdb = V<db>;
using vch = V<ch>;
 
 
#define FOR(i,a,b) for(ll i=(a);i<(ll)(b);i++)
#define rFOR(i,a,b) for(ll i=(a);i>(ll)(b);i--)
#define oFOR(i,a,b) for(ll i=(a);i<(ll)(b);i+=2)
#define bgn begin()
#define en end()
#define SORT(a) sort((a).bgn,(a).en)
#define REV(a) reverse((a).bgn,(a).en)
#define M(a,b) max(a,b)
#define rM(a,b) min(a,b)
#define fi first
#define se second
#define sz size()
#define gcd(a,b) __gcd(a,b)
#define co(a) cout<<a<<endl;
#define ci(a) cin>>a;
 
 
ll sum(ll n) {
  ll m=0;
  FOR(i,0,20){
    m+=n%10;
    n/=10;
    if(n==0){
      break;
    }
  }
  return m;
}
 
 
ll combi(ll n,ll m) {
  ll ans=1;
  rFOR(i,n,n-m){
    ans*=i;
  }
  FOR(i,1,m+1){
    ans/=i;
  }
  return ans;
}
 
 
ll lcm(ll a,ll b){
  ll n;
  n=a/gcd(a,b)*b;
  return n;
}
 
 
/****************************************\
| Thank you for viewing my code:)        |
| Written by RedSpica a.k.a. RanseMirage |
| Twitter:@asakaakasaka                  | 
\****************************************/
 
 
signed main() {
  ll n;
  ci(n)
  vll A(n);
  vll B(n-1);
  ci(A[0])
  ll s=A[0];
  FOR(i,1,n){
    ll a;
    ci(a)
      s+=a;
    A[i]+=s;
  }
  
  FOR(i,0,n-1){
    B[i]=abs(s-A[i]-A[i]);
  }
  SORT(B);
  co(B[0])
}
