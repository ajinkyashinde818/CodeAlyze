#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>
#include <cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<tuple>
#include<sstream>
#include<functional>
#include<list>
#include<queue>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> p;
typedef pair<int, pair<int, pair<int, int>>> PP;
typedef vector<int> vec;
using Graph = vector<vector<int>>;
using graph = vector<vector<ll>>;

const long long INF = 1LL << 60;
const int inf = 1e9;
const long long MOD = 1e9+7;

int main() {
	int n;
	cin >> n;
	vec a(n + 1, 0), b(n + 1, 0), c(n), d(n);
	rep(i, n) {
		int k;
		cin >> k;
		a[k]++;
	}
	rep(i, n) {
		int k;
		cin >> k;
		c[i] = k;
		b[k]++;
	}
	rep(i, n) {
		a[i + 1] += a[i];
		b[i + 1] += b[i];
	}
	bool f = 0;
	rep(i, n) {
		if (a[i + 1] - a[i] + b[i + 1] - b[i] >= n + 1)f = 1;
	}
	if (f) {
		cout << "No" << endl;
		return 0;
	}
	int t = 0;
	repd(i,1, 1+n) {
		t = max(t, a[i] - b[i - 1]);
	}
	cout << "Yes" << endl;
	rep(i, n) {
		d[(i + t) % n] = c[i];
	}
	rep(i, n)cout << d[i] << " ";
	return 0;
}
