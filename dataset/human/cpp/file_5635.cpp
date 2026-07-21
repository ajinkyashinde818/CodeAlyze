#include <bits/stdc++.h>
using namespace std;
int ch[100005][2],n,k,m,t,f[100005];
long long M,ans; char S[100005];
void dfs(int x,long long m){
	if (!ch[x][0]&&!ch[x][1]) return;
	if (!ch[x][0]||!ch[x][1])
	ans^=m&-m,dfs(ch[x][0]+ch[x][1],m-1);
	else dfs(ch[x][0],m-1),dfs(ch[x][1],m-1);
}
int main(){
	scanf("%d%lld",&n,&M);
	for (int i=1;i<=n;++i){
		scanf("%s",S); k=0; m=strlen(S);
		for (int j=0;j<m;++j){
			if (!ch[k][S[j]-'0']) ch[k][S[j]-'0']=++t;
			k=ch[k][S[j]-'0'];
		}
	}
	dfs(0,M);
	if (ans) puts("Alice"); else puts("Bob");
	return 0;
}
