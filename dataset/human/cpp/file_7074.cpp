#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> P;
typedef string str;
typedef vector<P> vp;
typedef vector<string> vs;
typedef vector<bool> vb;

const ll mod=1e9+7;
const ll inf=1e18;

#define rep(i,m,n) for(ll i=m;i<n;i++)
#define repr(i,m,n) for(ll i=m-1;i>=n;i--)
#define fi first
#define se second
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define eb(x) emplace_back(x)
#define pb(x) pop_back(x)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define sum(x) accumulate(all(x),0)
#define pc(x) __builtin_popcount(x)
#define gll greater<ll>()

void solve(){
  ll n;
  cin >> n;
  vll a(n),b(n);
  rep(i,0,n) cin >> a[i];
  rep(i,0,n) cin >> b[i];
  
  ll j=0,now=-1;
  rep(i,0,n){
   if(now!=a[i]) j=0;
   if(a[i]==b[i]){ 
    for(;j<n;j++){
     if(a[j]!=a[i]&&b[j]!=a[i]){
      swap(b[i],b[j]);
      break;
     }
    }
    if(a[i]==b[i]){
     cout << "No" << endl;
      return;
    }
   }
    now=a[i];
  }
  
  cout << "Yes" << endl;
  rep(i,0,n) {
    cout << b[i];
    if(i!=n-1) cout << " ";
  }
  cout << endl;
  
}
int main(){
   cin.tie(nullptr);
  ios::sync_with_stdio(false);
  solve();
}
