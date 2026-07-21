#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define mod 998244353

using namespace std;
typedef pair<llint, llint> P;

struct Trie{
	struct TrieNode{
		int num, next[2];
		TrieNode(){
			num = 0;
			for(int i = 0; i < 2; i++) next[i] = -1;
		}
	};
	vector<TrieNode> vec;
	Trie(){
		init();
	}
	void init(){
		vec.clear();
		vec.push_back(TrieNode());
	}
	int seek(string &s)
	{
		int p = 0;
		for(int i = 0; i < s.size(); i++){
			int c = s[i]-'0';
			if(vec[p].next[c] == -1){
				vec.push_back(TrieNode());
				vec[p].next[c] = (int)vec.size()-1;
			}
			p = vec[p].next[c];
		}
		return p;
	}
	void insert(string &s, int x = 1)
	{
		int p = seek(s);
		vec[p].num += x;
	}
	void erase(string &s, int x = 1)
	{
		int p = seek(s);
		vec[p].num = max(0, vec[p].num - x);
	}
	int count(string &s)
	{
		int p = seek(s);
		return vec[p].num;
	}
};

llint n, L;
string s[100005];
Trie trie;
vector<llint> vec;

void dfs(int v, int d)
{
	if(trie.vec[v].next[0] == -1 && trie.vec[v].next[1] == -1) return;
	for(int i = 0; i < 2; i++){
		if(trie.vec[v].next[i] == -1) vec.push_back(L-d-1);
		else dfs(trie.vec[v].next[i], d+1);
	}
}

llint get(llint x)
{
	x++;
	llint ret = 1;
	while(x%2==0) x/=2, ret*=2;
	return ret;
}

int main(void)
{
	cin >> n >> L;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
		trie.insert(s[i]);
	}
	dfs(0, 0);
	
	llint ans = 0;
	for(int i = 0; i < vec.size(); i++) ans ^= get(vec[i]);
	if(ans == 0) cout << "Bob" << endl;
	else cout << "Alice" << endl;
	
	return 0;
}
