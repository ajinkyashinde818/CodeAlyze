#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-2;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

int n;
int a[1 << 17], b[1 << 17];

int comp[1 << 17];
int num[1 << 17];
struct uf {
private:
	vector<int> par, ran;
public:
	void init(int n) {
		par.resize(n, 0);
		ran.resize(n, 0);
		rep(i, n) {
			par[i] = i;
			comp[i] = 1, num[i] = 0;
		}
	}
	int find(int x) {
		if (par[x] == x)return x;
		else return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x), y = find(y);
		num[x]++;
		if (x == y)return;
		if (ran[x] < ran[y]) {
			par[x] = y; num[y] += num[x]; comp[y] += comp[x];
		}
		else {
			par[y] = x; num[x] += num[y]; comp[x] += comp[y];
			if (ran[x] == ran[y])ran[x]++;
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};
map<int, int> mp;

bool used[1 << 17];
int main() {
	cin >> n;
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n) {
		cin >> b[i];
	}
	vector<int> va, vb;
	int sa=0, sb=0;
	rep(i, n) {
		va.push_back(a[i]); sa ^= a[i];
		vb.push_back(b[i]); sb ^= b[i];
	}
	va.push_back(sa); vb.push_back(sb);
	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());
	if (va != vb) {
		cout << -1 << endl;
	}
	else {
		int cnt = 1;
		rep(i, n) {
			if (mp[a[i]] == 0) {
				mp[a[i]] = cnt; cnt++;
			}
		}
		if (mp[sa] == 0) {
			mp[sa] = cnt; cnt++;
		}
		uf u; u.init(cnt);
		rep(i, n) {
			if (a[i] == b[i])continue;
			u.unite(mp[a[i]], mp[b[i]]);
		}
		int ans = 0;
		rep1(i, cnt-1) {
			if (used[i])continue;
			int p = u.find(i);
			if (used[p])continue;
			if (comp[p] == 1)continue;
			ans += num[p];
			if (!u.same(p, mp[sa]))ans++;
			used[p] = true;
		}
		cout << ans << endl;
	}
	//stop
	return 0;
}
