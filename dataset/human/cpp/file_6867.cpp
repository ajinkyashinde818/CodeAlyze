#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
// #pragma GCC optimize("O2")
typedef long long int ll;
typedef long double ld;
typedef map <ll,ll> mm;
typedef vector <ll> mv;
typedef pair <ll,ll> mp;
typedef set <ll> ms;
typedef multiset <ll> mms;
typedef queue <ll> mq;
typedef deque <ll> mdq;
typedef stack <ll> mst;
typedef priority_queue <ll> mpq;
typedef priority_queue <ll, vector<ll>, greater<ll> > mmh;
typedef complex<double> cd;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define flush cout.flush();
#define all(v) v.begin(),v.end()
#define deb(x) cout << #x << " " << x << endl;
#define ff first
#define ss second
#define pb(v) push_back(v)
#define lb(v) lower_bound(v)
#define ub(v) upper_bound(v)
#define cn continue
#define forl(i,n) for(ll i=0;i<n;i++)
#define forlr(i,n) for(ll i=n-1;i>=0;i--)
#define rev(s) reverse(s.begin(),s.end())
void swap(ll &a,ll &b) {
	ll tmp=a;
	a=b;
	b=tmp;
}
ll atoistring(string s) {
	stringstream lol(s);
	ll x;
	lol>>x;
	return x;
}
void pv(mv v) {
	forl(i,v.size()) cout<<v[i]<<" ";
	cout<<"\n";
}
void pa(ll *v, ll size) {
	forl(i,size) cout<<v[i]<<" ";
	cout<<"\n";
}
void removeDups(mv &v) {
	sort(all(v));
	mv::iterator it = unique(v.begin(), v.end());
	v.resize(distance(v.begin(), it));
}
inline ld kthRoot(ld n, ll k) {
	return pow(k, (1.0 / k) * (log(n) / log(k)));
}
ll power(ll x, ll y, ll p) {
	ll res=1;
	x=x%p;
	while(y>0) {
		if(y&1) res = (res*x)%p;
		y=y>>1;
		x=(x*x)%p;
	}
	return res;
}
void checkmod(ll &x, ll mod) {
	if(x>=mod) x%=mod;
}

ll mod = 1e9 + 7;

ll arr1[200005], arr2[200005];
void thisIsMain() {
	ll n;
	cin>>n;
	forl(i,n) cin>>arr1[i];
	forl(i,n) cin>>arr2[i];
	sort(arr2, arr2 + n, greater < ll > ());
	// pa(arr1, n);
	// pa(arr2, n);
	ll i = 0, j = n - 1;
	forl(k,n) {
		if(arr1[k]  == arr2[k]) {
			if(arr1[i] != arr2[k] && arr2[i] != arr2[k]) {
				swap(arr2[i], arr2[k]);
				i ++ ;
			} else {
				if(arr1[j] != arr2[k] && arr2[j] != arr2[k]) {
					swap(arr2[j], arr2[k]);
					j -- ;
				} else {
					cout<<"No\n";
					return ;
				}
			}
		}
	}
	forl(i,n) if(arr1[i] == arr2[i]) {
		cout<<"No\n";
		return ;
	}
	cout<<"Yes\n";
	pa(arr2, n);
}

int main(void)
{
	fastio
	ll t = 1;
	// cin>>t;
	while(t--) thisIsMain();
	return 0;
}
