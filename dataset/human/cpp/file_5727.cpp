#include <iostream>
#include <string>

using namespace std;

typedef long long lli;

lli res, L;

class p {
public:
	p* nxt[2];
	lli h;
	p() {
		nxt[0] = nxt[1] = NULL;
	}
	void ins(string& s, int k) {
		h = k;
		if (k == s.size()) return;
		if (nxt[s[k] - '0'] == NULL) nxt[s[k] - '0'] = new p();
		nxt[s[k] - '0']->ins(s, k + 1);
	}
	void dfs() {
		int cnt = 0;
		if (nxt[0] != NULL) {
			cnt++; nxt[0]->dfs();
		}
		if (nxt[1] != NULL) {
			cnt++; nxt[1]->dfs();
		}
		if (cnt == 1) {
			lli add = 1;
			lli w = L - h;
			while (w % 2 == 0) {
				w /= 2; add *= 2;
			}
			res ^= add;
		}
	}
};

p* root;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> L;
	root = new p();
	while (n--) {
		cin >> s;
		root->ins(s, 0);
	}
	root->dfs();
	if (res) cout << "Alice\n";
	else cout << "Bob\n";
	return 0;
}
