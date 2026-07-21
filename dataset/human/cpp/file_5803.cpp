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
typedef pair<int, int> pii;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

int Trie[100010][2], tz, leaf[100010];
int n;
char buf[100010];
ll L;

ll dfs(int x, int dep = 0) {
	if(leaf[x]) return 0;
	ll res = 0;
	rep(u, 2) {
		int nxt = Trie[x][u];
		if(nxt == 0) {
			ll tl = L - dep;
			res ^= (tl & -tl);
		}
		else res ^= dfs(nxt, dep + 1);
	}
	return res;
}

void solve() {
	scanf("%d%lld", &n, &L);
	rep(i, n) {
		scanf("%s", buf);
		int now = 0;
		for(int j=0;buf[j];j++) {
			int c = buf[j] - '0';
			if(Trie[now][c] == 0) Trie[now][c] = ++tz;
			now = Trie[now][c];
		}
		leaf[now] = 1;
	}
	printf("%s\n", dfs(0) == 0 ? "Bob" : "Alice");
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}
