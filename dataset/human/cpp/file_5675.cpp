#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define INF_LL (ll)1e18
#define INF (int)1e9
#define REP(i, n) for(int i = 0;i < (n);i++)
#define FOR(i, a, b) for(int i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
using ll = long long;
using PII = pair<int, int>;

const double eps = 1e-10;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

struct Node{
	ll ch[2];
	int cost;
	int h;

	Node(){
		memset(ch, -1, sizeof ch);
		cost = 0;
		h = 0;
	}
};

vector<Node> trie;

void add_str(int v, string &s, int i, int cost){
	if(s.size() == i){
		trie[v].cost = cost;
		return;
	}

	trie[v].h = i;
	if(trie[v].ch[s[i]-'0'] == -1){
		trie.push_back(Node());
		trie[v].ch[s[i]-'0'] = trie.size()-1;
	}

	add_str(trie[v].ch[s[i]-'0'], s, i+1, cost);
}

ll modpow(ll a, ll b){
	if(b < 0) return 0;
	if(b == 0) return 1;
	if(b % 2) return (a*modpow(a,b-1))%3;
	ll ret = modpow(a, b/2);
	return ret*ret%3;
}

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N, L;
	ll res = 0;
	cin >> N >> L;
	trie.push_back(Node());
	REP(i, N){
		string s;
		cin >> s;
		add_str(0, s, 0, 0);
	}
	REP(i, trie.size()){
		if(trie[i].ch[0] * trie[i].ch[1] < 0){
			res ^= (L-trie[i].h)&-(L-trie[i].h);
		}
	}
	if(res == 0){
		cout << "Bob" << endl;
	}else{
		cout << "Alice" << endl;
	}
}
