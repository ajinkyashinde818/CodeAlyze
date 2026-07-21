#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=100010<<2;
int n, val[maxn];
ll l;
char s[maxn];
int Max;
int e=1, ch[maxn][2];

ll calc(ll x){
	ll ret=1;
	while( !(x&1) && x>0 ) x>>=1, ret<<=1;
	return ret;
}
void insert(char *s){
	int o=1;
	for(int i=0;i<strlen(s);i++){
		int c=s[i]-'0';
		if(!ch[o][c]) ch[o][c]=++e;
		o=ch[o][c];
	}
	val[o]=1;
}

ll ans;
void dfs(int x,int dep){
	int cnt=(bool)ch[x][0]+(bool)ch[x][1];
	if(ch[x][0]) dfs(ch[x][0],dep+1); if(ch[x][1]) dfs(ch[x][1],dep+1);
	if(cnt==1){ ans^=calc(l-dep); return; }
}

int main(){

	scanf("%d%lld",&n,&l); l++;
	for(int i=1;i<=n;i++){
		scanf("%s",s); 
		insert(s);
	}
	dfs(1,1);
	printf("%s\n", ans?"Alice":"Bob");
	return 0;
}
