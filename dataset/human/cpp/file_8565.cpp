#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using vii = vector<vi>;

const long long int llinf = 1LL << 62;
const int inf = 99999999;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

#define Endl endl
#define pr(x) cout << x << endl
#define FOR(i,a,b) for(int i = a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define pb(a) push_back(a);
#define mp(a,b) make_pair(a,b)
#define atcoder int(1e9) +7;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
#define all(x) x.begin,x.end();

char cn[100][100],cm[100][100];

int main() {

	int n, m;
	cin >> n >> m;

	rep(i, n) rep(j, n) cin >> cn[i][j];

	rep(i, m) rep(j, m) cin >> cm[i][j];

	rep(i, n - m+1) {
		rep(j, n - m+1) {
			bool flag = true;
			rep(k, m) {
				rep(l, m) {
					if (cn[i + k][j + l] != cm[k][l])flag = false;
				}
			}
			if (flag) {
				pr("Yes");
				return 0;
			}
		}
	}

	pr("No");
	return 0;
}
