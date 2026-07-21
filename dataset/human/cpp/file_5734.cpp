#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <cstring>
#include <string>
#include <cctype>
#include <cassert>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(int i = 0; i < (n); i++)
#define repr(i,b,e) for(int i = (b); i <= (e); i++)
#define INF (1001001001)
#define EPS (1e-15)

#define pr(x) do{cerr << (#x) << " = " << (x) << endl;}while(0)
#define pri(x,i) do{cerr << (#x) << "[" << i << "] = " << (x[i]) << endl;}while(0)
#define pra(x) do{rep(__i,(x).size()) pri(x,__i);}while(0)
#define pran(x,n) do{rep(__i,n) pri(x,__i);}while(0)
#define pral(x) do{cerr << (#x) << " =";rep(__i,(x).size()) cerr<<" "<<(x[__i]);cerr<<endl;}while(0)
#define prar(x,b,e) do{repr(__i,b,e) pri(x,__i);}while(0)

typedef long long ll;
typedef pair<int, int> pint;
typedef vector<int> vint;
typedef vector<pint> vpint;

ll MOD = 1000000007;

int in() {
	int a;
	scanf("%d ", &a);
	return a;
}

vint grun(100010);

ll rmb(ll x) {
	return x & -x;
}

ll L;
struct Trie {
	Trie *ch[2];
	int value;
	bool terminal;
	int depth;
	Trie() {
		ch[0] = ch[1] = 0;
		terminal = false;
	}
	void add(int d, int v, const char *s) {
		value = v;
		depth = d;
		if (s[0] == 0) {
			terminal = true;
			return;
		}
		int chval = s[0] - '0';
		// pr(chval);
		if (ch[chval] == 0) ch[chval] = new Trie;
		ch[chval]->add(d + 1, chval, s + 1);
	}
	ll solve() {
		pr(value);
		pr(depth);
		if (terminal) return 0;
		ll ret;
		if (ch[0] == 0 && ch[1] == 0) {
			int *p = 0;
			*p = 42;
		}
		else if (ch[1] == 0) {
			ret = ch[0]->solve() ^ rmb(L - depth);
		}
		else if (ch[0] == 0) {
			ret = ch[1]->solve() ^ rmb(L - depth);
		}
		else {
			ret = ch[0]->solve() ^ ch[1]->solve();
		}
		pr(ret);
		return ret;
	}
} root;

int main() {
	// grun[0] = 0;
	// grun[1] = 1;
	// repr(i, 2, 100) {
	// 	vint app(102);
	// 	int t = 0;
	// 	for (int k = i - 1; k >= 0; k--) {
	// 		t ^= grun[k];
	// 		app[t] = 1;
	// 	}
	// 	int g = 1;
	// 	while (app[g]) g++;
	// 	grun[i] = g;
	// }
	// pran(grun, 100);
	// return 0;
	int N = in();
	scanf("%lld ", &L);
	vector<string> data(N);
	rep(i, N) {
		string s;
		cin >> s;
		data[i] = s;
	}
	// sort(data.begin(), data.end());
	rep(i, N) root.add(0, -1, data[i].c_str());
	ll ans = root.solve();
	pr(ans);
	cout << (ans == 0 ? "Bob" : "Alice") << endl;
	return 0;
}
