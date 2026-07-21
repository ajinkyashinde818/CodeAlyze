#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Trie{
	int value;
	Trie *next[0x100];
	Trie(){ fill(next, next + 0x100, (Trie*)0); }
};
Trie *find(const string& t, Trie *r){
	for(int i = 0; t[i]; ++i){
		char c = t[i];
		if(!r->next[c]) r->next[c] = new Trie;
		r = r->next[c];
	}
	return r;
}
string s[100000];
Trie root;

ll L;
ll gr;
string state;

void dfs(Trie* node, int d){
	if(node == nullptr || d == L){
		if(node == nullptr){
			ll rem = L - d + 1;
			//cout << state << " " << rem << endl;
			gr ^= rem & (-rem);
			//cnt += rem % 4;
		}
		return;
	}
	//state += '0';
	dfs(node->next['0'], d + 1);
	//state.pop_back();
	//state += '1';
	dfs(node->next['1'], d + 1);
	//state.pop_back();
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	std::ifstream in("in");
	std::cin.rdbuf(in.rdbuf());
#endif


	int n;
	cin >> n >> L;
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	sort(s, s + n);
	for(int i = 0; i < n; i++){
		find(s[i], &root);
	}
	dfs(&root, 0);
	if(gr) cout << "Alice" << endl;
	else cout << "Bob" << endl;
}
