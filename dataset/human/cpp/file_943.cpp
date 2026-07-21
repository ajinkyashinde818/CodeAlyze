#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <functional>
#include <climits>
#include <cstring>

using namespace std;

#define int long long
#define rep(i, n) for (int i=0;i<(int)n;++i)
#define rep1(i, n) for (int i=1;i<=(int)n;++i)
#define unless(a) if(!(a))
#define all(a) begin(a),end(a)
#define fst first
#define scd second
#define PB emplace_back
#define PPB pop_back

using ll=long long;
using vi=vector<int>;
using pii=pair<int, int>;

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
bool chmin(int&a,int b){return a>b?(a=b,true):false;}
bool chmax(int&a,int b){return a<b?(a=b,true):false;}
ll read(){ll a;scanf("%lld",&a);return a;}

const int inf = 3 * TEN(18) + 10;
const int mod = 998244353;


signed main()
{
	vi a(3);
	rep(i, 3) cin >> a[i];
	int n; cin >> n;

	int ans = 0;
	rep(i, n + 1) rep(j, n + 1) {
		if (a[0]*i + a[1]*j > n) break;
		int zan = n - a[0] * i - a[1] * j;
		if (zan % a[2] == 0) ans++;
	}

	cout << ans << endl;
}
