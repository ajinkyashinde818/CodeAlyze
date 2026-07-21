#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int now,n,son[N][2],sc,dep[N];
char s[N];
ll L,ans;
void ins(char *s)
{
	now=0;int len=strlen(s);
	for (int i=0;i<len;i++)
	{
		int c=s[i]-'0';
		if (!son[now][c]) son[now][c]=++sc,dep[sc]=dep[now]+1;
		now=son[now][c];
	}
}
ll sg(ll x){return x&(-x);}

void dfs(int now)
{
	int cnt=0;
	if (son[now][0]){
		dfs(son[now][0]);
		cnt++;
	}
	if (son[now][1]){
		dfs(son[now][1]);
		cnt++;
	}
	if (cnt==1){//切下一半的子树
		ans^=sg(L-dep[now]); 
	} 
}

int main()
{
	scanf("%d%lld",&n,&L);
	for (int i=1;i<=n;i++){
		scanf("%s",s);
		ins(s);
	}
	dfs(0);
	puts(ans==0?"Bob":"Alice"); 
	return 0;
}
