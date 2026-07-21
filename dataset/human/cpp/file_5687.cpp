#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ALPHA = 2;
const int MAX = 2*100005;

int trie[MAX][ALPHA+5];
ll d[MAX];
bool child[MAX];
int ct = 2;
void insert(string s) {
	int cur = 1;
	for (char i : s) {
		if (trie[cur][i-'0'] != 0) {
			cur = trie[cur][i-'0'];
		}
		else {
			child[cur] = true;
			trie[cur][i-'0'] = ct;
			d[ct] = d[cur] + 1;
			cur = ct;
			ct++;
		}
	}
}

ll nim(ll n) {
	ll i = 1;
	while (n%(2*i) == 0) {
		i *= 2;
	}
	return i;
}

int main() {
	// freopen("a.in", "r", stdin);
	int n; ll l; cin >> n >> l;
	for (int i=0; i<n; i++) {
		string s; cin >> s;
		insert(s);
	}
	vector<ll> depths;
	for (int i=1; i<=ct; i++) {
		for (int j=0; j<ALPHA; j++) {
			if (child[i] && trie[i][j] == 0) {
				depths.push_back(l-d[i]);
			}
		}
	}
	ll nimber = 0;
	for (ll i : depths) { nimber ^= nim(i); }
	cout << ((nimber == 0) ? "Bob" : "Alice");
}
