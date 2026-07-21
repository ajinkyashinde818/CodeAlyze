#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef double db;
const int MAXN = 1e5 + 5, MAXM = 2e6 + 5, BOUND = 2e5, MOD = 1e9 + 7, INF = 0x3f3f3f3f, inv2 = 500000004;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0), eps = 1e-6;
#define mid l + ((r-l)>>1)
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define lc(x) c[x][0]
#define PII pair<int,int>
#define rc(x) c[x][1]
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
char gdffsaw;
#define G gdffsaw=getchar()
#define GO G;while(gdffsaw<'-')G
#define in(z) GO;z=gdffsaw&15;G;while(gdffsaw>'-')z*=10,z+=gdffsaw&15,G
int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
	while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n, cnt[MAXN];
char str[MAXN];
ll qPwo(ll a, ll b) {
	ll ans = 1;
	for (; b; b >>= 1, a = a * a%MOD)if (b & 1)ans = ans * a%MOD;
	return ans;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> (str + 1);
	ll ans = 0, temp;
	rep(i, 1, n) {
		temp = 1;
		rep(j, 'a', 'z') {
			if (j == str[i])continue;
			temp = temp * (cnt[j] + 1) % MOD;
		}
		ans = (ans + temp) % MOD;
		cnt[str[i]]++;
	}
	cout << ans << '\n';
	return 0;
}
