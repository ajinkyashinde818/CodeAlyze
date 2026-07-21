#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
const int MAXN = 1e5 + 5, MAXM = 3e5 + 5, BOUND = 1e7, MOD = 1073741824, INF = 0x3f3f3f3f, base = 10000;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0), eps = 1e-9;
#define mid l + ((r-l)>>1)
#define lson o<<1,l,m
#define rson o<<1|1,m+1,r
#define lc(x) ch[x][0]
#define pii pair<int,int>
#define vi vector<int>
#define RR register int
#define rc(x) ch[x][1]
#define rep(i,a,b) for(RR i=(a);i<=(b);++i)
#define random(a,b) ((a)+rand()%((b)-(a)+1))

int n;
int a[MAXN];
ll sum;
int gcd(int a, int b) {
	return !b ? a : gcd(b, a%b);
}
int qpow(int a, int b) {
	int ans = 1;
	for (; b; b >>= 1, a *= a)if (b & 1)ans *= a;
	return ans;
}
ll f[MAXN][2];
int main() {
	cin >> n;
	rep(i, 1, n)cin >> a[i];
	memset(f, 0xcf, sizeof(f));
	f[0][0] = 0;
	rep(i, 1, n) {
		f[i][0] = max(f[i - 1][0] + a[i], f[i - 1][1] - a[i]);
		f[i][1] = max(f[i - 1][0] - a[i], f[i - 1][1] + a[i]);
	}
	cout << f[n][0] << '\n';
	return 0;
}
