#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
const int Maxn=1e5;

struct Trie {
	int son[2];
};
Trie t[Maxn+5];
int cnt=0;
void addstring(string tmp) {
	int rt=0;
	for(int i=0;i<(int)tmp.length();i++) {
		int ch=(int)tmp[i]-'0';
		if(!t[rt].son[ch])
			t[rt].son[ch]=++cnt;
		rt=t[rt].son[ch];
	}
}

int N;
ll L;
map<ll,int> g;
inline ll lowbit(ll x) {return x&(-x);}
void DFS(int rt,ll dep) {
	for(int i=0;i<2;i++) {
		if(t[rt].son[i]==0) {
			g[lowbit(L-dep+1)]^=1;
			continue;
		}
		DFS(t[rt].son[i],dep+1);
	}
}

int main() {
	#ifdef LOACL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d %lld",&N,&L);
	for(int i=1;i<=N;i++) {
		string s;
		cin>>s;
		addstring(s);
	}
	DFS(0,1);
	for(map<ll,int>::iterator it=g.begin();it!=g.end();it++) {
		int t=it->second;
		if(t) {
			puts("Alice");
			return 0;
		}
	}
	puts("Bob");
	return 0;
}
