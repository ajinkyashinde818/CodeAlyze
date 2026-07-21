#include <bits/stdc++.h>
using namespace std;

int n;
long long maxlen;

struct Node {
	Node *ch[2]; // binary
	bool leaf;
	Node() { for (int i = 0; i < 2; ++i) ch[i] = NULL; leaf = false; }
	~Node() { for (int i = 0; i < 2; ++i) delete ch[i]; leaf = false; }
} *Trie = new Node();

void add(string &s) {
	Node *cur = Trie;
	for (int i = 0; i < s.size(); ++i) {
		int v = s[i] - '0';
		if (cur -> ch[v] == NULL) cur -> ch[v] = new Node();
		cur = cur -> ch[v];
	}
	cur -> leaf = true;
}

long long get(long long x) {
	return x & -x;
}

long long grundy(Node *cur, long long len) {
	if (cur -> leaf) return 0;
	long long x = 0;
	for (int i = 0; i < 2; ++i) {
		if (cur -> ch[i] == NULL) x ^= get(len);
		else x ^= grundy(cur -> ch[i], len - 1);
	}
	return x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> maxlen;
	for (int i = 1; i <= n; ++i) {
		string s; cin >> s;
		add(s);
	}
	long long x = grundy(Trie, maxlen);
	printf(x > 0 ? "Alice\n" : "Bob\n");
}
