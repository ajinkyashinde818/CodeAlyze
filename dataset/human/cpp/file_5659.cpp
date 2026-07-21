#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
long long n,m,i,j,ch[100005][2],cur,cnt=1;
string s;
long long dfs(long long x,long long dep)
{
	//if (!dep) return 0;
	long long ans=0,i;
	if (ch[x][0]+ch[x][1]!=0&&ch[x][0]*ch[x][1]==0) ans=(dep&(-dep));
	for (i=0;i<=1;i++) if (ch[x][i]) ans^=dfs(ch[x][i],dep-1);
	return ans;
}
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cur=1;
		cin>>s;
		for (j=0;j<s.size();j++)
		{
			if (!ch[cur][s[j]-'0']) ch[cur][s[j]-'0']=++cnt;
			cur=ch[cur][s[j]-'0'];
		}
	}
	if (dfs(1,m)) cout<<"Alice"; else cout<<"Bob";
	return 0;
}
