#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define rep(i,a,n) for(int i=a;i<n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
const ll mod=1000000007; // 998244353 = (119<<23)+1
ll powmod(ll a,ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
// head
const int nax=1e5+7;
ll s[nax];
int n;
int main() {
	  ios::sync_with_stdio(false);
  	cin.tie(0);
		cin>>n;
		rep(i,0,n) cin>>s[i];
		ll ans=0;
		ll count=0;
		ll m=1e18;
		rep(i,0,n) {
			ans+=llabs(s[i]);
			m=min(m,llabs(s[i]));
			if(s[i]<0) count++;
		}
		if(count%2==0) cout<<ans;
		else cout<<ans-m*2LL;
		return 0;
}
