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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = (ll)(1e+9) + 7;
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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
vector<int> v[1000];
int main() {
	int n; cin >> n;
	int c = 1; bool f = false;
	for (int i = 1; i < (1 << 17); i += c) {
		if (i == n) {
			f = true; break;
		}
		c++;
	}
	if (!f)cout << "No" << endl;
	else {
		cout << "Yes" << endl;
		cout << c + 1 << endl;
		int now = 1;
		int id = 0;
		per1(i, c) {
			Rep(j, now, now+i) {
				v[id].push_back(j);
				v[id + 1 + j - now].push_back(j);
			}
			now += i;
			id++;
		}
		rep(i, c + 1) {
			cout << v[i].size();
			rep(j, (int)v[i].size()) {
				cout << " " << v[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
