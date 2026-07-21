#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxN = 1e5 + 5;
int N, e;
ll L, ans;
char s[maxN];

struct DD{
	DD* x[2];
	ll dep, idx;
	void init() {
		x[0] = x[1] = 0; idx = e;
	}
}dd[maxN]; 

struct Trie{
	DD* root; 
	DD* alloc_() {dd[e].init(); return &dd[e++];}
	void init() {e = 0; root = alloc_(); root -> dep = L;}
	void insert() {
		int len = strlen(s); DD* p = root;
		for(int i = 0, d; i < len; ++i) {
			d = s[i] - '0';
			if(p -> x[d] == 0) p -> x[d] = alloc_(), p -> x[d] -> dep = p -> dep - 1;
			p = p -> x[d];
		}
	}
}trie;

ll lowbit(ll num) {
	return num & -(num);
}

void dfs(DD* p) {
	if((p -> x[0] == 0) && (p -> x[1] == 0)) return;
	if((p -> x[0] != 0) && (p -> x[1] != 0)) {
		dfs(p -> x[0]), dfs(p -> x[1]); return;
	}
	for(int i = 0; i < 2; ++i) {
		if(p -> x[i] != 0) dfs(p -> x[i]);
		else ans ^= lowbit(p -> dep);
		//cout << lowbit(p -> dep) << ' ' << p -> idx << ' ' << p -> dep << ' ' << L << endl;
	}
}

int main() {
	scanf("%d%lld", &N, &L); trie.init(); 
	for(int i = 1; i <= N; ++i) {
		scanf("%s", s); trie.insert();
	}
	dfs(trie.root);
	if(ans != 0) printf("Alice\n");
	else printf("Bob\n");
	//while(L % 2 == 0) L /= 2;
	//cout << L << endl;
	return 0;
}
