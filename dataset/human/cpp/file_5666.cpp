#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,go[N][2],top;
char s[N];
ll L,sg;
void dfs(int x,ll dep){
	int cnt=0;
	if (go[x][0]) dfs(go[x][0],dep-1),cnt++;
	if (go[x][1]) dfs(go[x][1],dep-1),cnt++;
	if (cnt==1) sg^=dep&-dep;
}
int main()
{
	scanf("%d%lld",&n,&L);
	top=1;
	for (int i=1;i<=n;i++){
		scanf("%s",s);
		int l=strlen(s);
		for (int i=0,p=1;i<l;i++){
			int w=s[i]-'0';
			if (!go[p][w]) go[p][w]=++top;
			p=go[p][w];
		}
	}
	dfs(1,L);
	puts(sg?"Alice":"Bob");
	return 0;
}
