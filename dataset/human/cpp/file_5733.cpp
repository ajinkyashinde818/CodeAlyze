#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long Int;

Int cnt[108000];
string s;
Int n, l;
vector<Int> trees;
Int grundy;
class Trie{
public: 
	Trie* child[2];
	Trie(){
		child[0] = child[1] = 0;
	}
};

Trie t;

void dfs(Trie *t, Int d){
	if(t == 0){
		trees.push_back(d);
	}
	else{
		dfs(t->child[0], d+1);
		dfs(t->child[1], d+1);
	}
}

int main(){
	cin >> n >> l;
	for(Int i = 0;i < n;i++){
		cin >> s;
		Trie *now = &t;
		for(Int j = 0;j < s.size();j++){
			Int nxt = s[j] - '0';
			if(now->child[nxt] == 0){
				now->child[nxt] = new Trie();
			}
			now = now->child[nxt];
		}
	}
	dfs(&t, 0);

	for(Int i = 0;i < trees.size();i++){
		if(trees[i] > l)continue;
		Int x = l - trees[i] + 1;
		grundy ^= x & -x;
	}
	if(grundy != 0)cout << "Alice" << endl;
	else cout << "Bob" << endl;
	return 0;
}
