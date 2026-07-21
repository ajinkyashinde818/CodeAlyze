#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>
#include <tuple>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e5 * 2 + 10, INF = 1e9 * 1e9, MOD = 1e9 + 7;

struct node {
	node *l = 0, *r = 0;
	ll sumL = 0, sumR = 0, s = 0, sum = 0;
	node() {};
};

ll dpth[60];

node *root = new node();

void add(string& s, int ind, node* v) {
	if (ind == -1) {
		v->s++;
		v->sum++;
		return;
	}
	if (s[ind] == '0') {
		if (!v->l) {
			auto k = new node();
			v->l = k;
		}
		add(s, ind - 1, v->l);
	}
	else {
		if (!v->r) {
			auto k = new node();
			v->r = k;
		}
		add(s, ind - 1, v->r);
	}

	ll sm = v->s;
	if (v->l) sm += (v->l->sum);
	if (v->r) sm += (v->r->sum);
	v->sum = sm;
}

ll ans = 0;

void dfs(node* v, ll lnth) {
	if (!v->l) {
		if (lnth != 0) {
			for (ll j = 0; j <= 63; j++) {
				if ((lnth >> j) & 1) {
					ans ^= (1ll << j);
					break;
				}
			}
		}
	}
	else {
		dfs(v->l, lnth - 1);
	}

	if (!v->r) {
		if (lnth != 0) {
			for (ll j = 0; j <= 63; j++) {
				if ((lnth >> j) & 1) {
					ans ^= (1ll << j);
					break;
				}
			}
		}
	}
	else {
		dfs(v->r, lnth - 1);
	}
}

int main()
{
	fastInp;

	ll n, l;
	cin >> n >> l;

	dpth[0] = 1;
	for (int i = 1; i < 60; i++) {
		dpth[i] = (dpth[i - 1] ^ dpth[i - 1]);
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		add(s, s.size() - 1, root);
	}

	dfs(root, l);

	if (ans) {
		cout << "Alice";
	}
	else {
		cout << "Bob";
	}
	return 0;
}
