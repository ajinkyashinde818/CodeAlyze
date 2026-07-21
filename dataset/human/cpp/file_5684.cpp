#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> v;
string S;

ll grundy(ll x){
	if (x == -1) return 0;
	ll b = 1;
	while (1){
		if (x%b!=0) break;
		b *= 2;
	}
	b /= 2;
	return b;
}

struct trie{
	ll sz;
	trie *left = nullptr, *right = nullptr;
	trie(ll s){
		sz = s;
	}
	void dfs(int idx){
		if (idx == S.size()) return;
		if (S[idx] == '0'){
			if (left == nullptr) left = new trie(sz-1);
			left->dfs(idx+1);
		}
		else{
			if (right == nullptr) right = new trie(sz-1);
			right->dfs(idx+1);
		}
	}
	void cnts(){
		if (left == nullptr && right == nullptr) return;
		if (left == nullptr || right == nullptr) v.push_back(grundy(sz-1));
		if (left != nullptr) left->cnts();
		if (right != nullptr) right->cnts();
	}
} *root;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, L;
	cin >> N >> L;
	root = new trie(L+1);
	for (int i = 1; i <= N; ++i){
		cin >> S;
		root->dfs(0);
	}
	root->cnts();
	ll k = 0;
	for (int i = 0; i < v.size(); ++i){
		k ^= v[i];
	}
	if (k == 0){
		cout << "Bob\n";
	}
	else cout << "Alice\n";
	cout << flush;
	//for (int i = 0; i < 1e9; ++i){for (int j = 0; j < 1e9; ++j){}}
}
