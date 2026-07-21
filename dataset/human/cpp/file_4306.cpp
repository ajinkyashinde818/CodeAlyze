#include<iostream>
#include<stdio.h>
#include<string.h>
#include<map>
#include<set>
using namespace std;
int n,a[120000],b[120000];
int x,fa[120000],ans,tot,siz[120000];
map<int,int>p;
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),x^=a[i],p[a[i]]++;
	p[x]++;
	int flag=0;
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),p[b[i]]--,fa[i]=i,siz[i]=1,flag=max(flag,(int)(b[i]==x));
	for(int i=1;i<=n;i++)if(p[b[i]]<0){printf("-1\n");return 0;}
	ans=-flag;
	p.clear();
	for(int i=1;i<=n;i++){
		if(p[a[i]]==0)p[a[i]]=++tot;
		if(p[b[i]]==0)p[b[i]]=++tot;
		if(a[i]!=b[i])ans++;
		int x=find(p[a[i]]),y=find(p[b[i]]);
		if(x!=y)fa[x]=y,siz[y]+=siz[x],siz[x]=0;
	} 
	for(int i=1;i<=n;i++)if(siz[i]>1)ans++;
	ans=max(ans,0);
	printf("%d\n",ans);
}
