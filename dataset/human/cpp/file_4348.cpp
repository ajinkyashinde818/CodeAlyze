#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

int n, a[100010], b[100010];
int ta[100010], tb[100010];
int p[100010], z[1000010];
int Find(int x){return p[x] == x ? x : p[x] = Find(p[x]);}

void solve() {
	scanf("%d", &n);
	rep(i, n) scanf("%d", a+i);
	rep(i, n) scanf("%d", b+i);
	rep(i, n) ta[i] = a[i], tb[i] = b[i];
	rep(i, n) ta[n] ^= ta[i], tb[n] ^= tb[i];
	a[n] = ta[n], b[n] = tb[n];
	sort(ta, ta+1+n);
	sort(tb, tb+1+n);
	rep(i, n+1) if(ta[i] != tb[i]) {
		puts("-1");
		return;
	}
	vector <int> xs;
	rep(i, n+1) xs.pb(ta[i]);
	sort(all(xs));
	xs.resize(unique(all(xs)) - xs.begin());
	rep(i, n+1) a[i] = (int)(lower_bound(all(xs), a[i]) - xs.begin() + 1);
	rep(i, n+1) b[i] = (int)(lower_bound(all(xs), b[i]) - xs.begin() + 1);
	int ans = 0;
	rep(i, n+5) p[i] = i, z[i] = 1;
	rep(i, n+1) if(a[i] != b[i]) {
		int x = Find(a[i]), y = Find(b[i]);
		if(x != y) {
			p[x] = y;
			z[y] += z[x];
		}
		++ans;
	}
	for(int i=1;i<=sz(xs);i++) {
		if(z[i] > 1 && p[i] == i) {
			if(Find(a[n]) == i) {
				if(a[n] != b[n]) ans--;
			}
			else ++ans;
		}
	}
	printf("%d\n", ans);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
};
