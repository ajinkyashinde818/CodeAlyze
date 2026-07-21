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
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;

char trans(char t) {
	if (t == 'W')return 'B';
	else return 'W';
}
void solve() {
	ll ans = 1;
	int n; cin >> n;
	string s; cin >> s;
	if (s[0] == 'W') {
		cout << 0 << endl; return;
	}
	ll num = 1;
	for (int i = 1; i < 2 * n; i++) {
		char memo = s[i];
		if (num % 2)memo = trans(memo);
		if (memo == 'B') {
			num++;
		}
		else {
			if (num < 0) {
				cout << 0 << endl; return;
			}
			else {
				ans = ans * num%mod; num--;
			}
		}
	}
	if (num > 0) {
		cout << 0 << endl; return;
	}
	rep1(i, n) {
		ans = ans * i%mod;
	}
	cout << ans << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(5);
	//init();
	solve();

	//cout << "finish" << endl;
	//stop
	return 0;
}
