#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
#include<iomanip>
#include<cmath>
#include<queue>
#include<limits>
#include<cassert>
#include<set>
#include<tuple>
#include<map>

#define PB push_back
#define ALL(a)  (a).begin(),(a).end()
#define DWN(a)  (a).begin(),(a).end(), greater<int>()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

using namespace std;
typedef long long ll;

int main()
{
	ll n;
	cin >> n;
	vector<ll> a(n);
	ll X = 0, x = 0, ans = 100000000000LL;
	REP(i, n) {
		cin >> a[i];
		X += a[i]; //カードの総数
	}
	REP(i, n) {
		x += a[i]; //取るカードの総数
		if(i + 1 < n) ans = min(ans, abs(X - 2 * x)); //最低一つは残す
	}
	cout << ans << endl;
	return 0;
}
