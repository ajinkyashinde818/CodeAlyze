#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
  ll n;
  cin >> n;
  vl a(n);
  ll sum=0;
  vl sum2(n,0);
  rep(i,n){
    cin >> a[i];
    sum +=a[i];
  }
  sum2[0]=a[0];
  FOR(i,1,n){
    sum2[i]=sum2[i-1]+a[i];
  }
  ll ans=INF;
  rep(i,n-1){
    ans=min(ans,abs(sum-2*sum2[i]));
  }
  cout << ans << endl;
}
