/*input
4
1 1 2 3
1 2 3 3
*/

// Nihesh Anderson - knandy

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key
ll MOD=1000000007;

#define endl '\n'
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
ll INF = 2000000000000000001;
long double EPS = 1e-9;
ll power(ll a, ll n, ll md){if(n==0){return 1;}else{ll res=power(a,n/2,md);res=(res*res)%md;if(n%2!=0){res=(res*a)%md;}return res;}}
random_device rndm;
mt19937 grndm(rndm());
void mix(ll* a, ll* b){shuffle(a,b,grndm);}

const ll MX = 200005;
stack<ll> idx[MX];
ll f[MX];

int main(){
	fast_cin();
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
	ll n; cin >> n;
	vector<ll> a(n);
	vector<pair<ll, ll> > b(n);
	for(ll i = 0; i < n; i++) {
		cin >> a[i];
		f[a[i]]++;
		idx[a[i]].push(i);
	}
	set<ll> d;
	for(ll i = 0; i < n; i++) {
		cin >> b[i].first;
		b[i].second = i;
		d.insert(b[i].first);
	}
	vector<ll> dis;
	for(auto val: d) {
		dis.push_back(val);
	}
	sort(dis.begin(), dis.end(), [&](ll x, ll y) -> bool {
		if(f[x] == f[y]) return x < y;
		return f[x] > f[y];
	});	
	queue<ll> dist;
	for(ll i = 0; i < dis.size(); i++) {
		dist.push(dis[i]);
	}
	sort(b.begin(), b.end(), [&](pair<ll, ll> x, pair<ll, ll> y) -> bool {
		if(f[x.first] == f[y.first]) return x.second < y.second;
		return f[x.first] > f[y.first];
	});
	vector<ll> ans(n);
	deque<pair<ll, ll> > pending;
	bool fi = true;
	for(ll i = 0; i < n; i++) {
		if(dist.size() && b[i].first == dist.front()) dist.pop();
		while(dist.size() && !idx[dist.front()].size()) dist.pop();
		if(dist.size()) {
			ll pos = idx[dist.front()].top();
			idx[dist.front()].pop();
			ans[pos] = b[i].first;
		}
		else {
			if(fi) {
				fi = false;
				for(ll i = 1; i <= n; i++) {
					while(idx[i].size()) {
						pending.push_back({i, idx[i].top()});
						idx[i].pop();
					}
				}
			}
			if(b[i].first == pending.front().first) {
				ans[pending.back().second] = b[i].first;
				pending.pop_back();
			}
			else {
				ans[pending.front().second] = b[i].first;
				pending.pop_front();
			}
		}
	}
	bool ok = true;
	for(ll i = 0; i < n; i++) {
		ok &= (a[i] != ans[i]);
	}
	if(ok) {
		cout << "Yes" << endl;
		for(ll i = 0; i < n; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
