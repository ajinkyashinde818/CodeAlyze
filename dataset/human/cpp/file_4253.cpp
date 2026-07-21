#include<cstdio>
#include<algorithm>
inline void read(int&r)
{
	register char c;r=0;
	do c=getchar();while(c<'0'||c>'9');
	do r=r*10+c-'0',c=getchar();while(c>='0'&&c<='9');
}

int a[100000],b[100000],c[100001],d[100000];
int fa[100001];bool vis[100001];
int find(int x){ return x==fa[x]?x:fa[x]=find(fa[x]); }
#define id(x) std::lower_bound(c,c+m,x)-c

int main()
{
	int i,j,n,m;read(n);
	for(i=0;i<n;i++)read(a[i]),c[i]=a[i],c[n]^=a[i];
	for(i=0;i<n;i++)read(b[i]),d[i]=b[i];
	int x=c[n];
	std::sort(c,c+n+1);
	std::sort(d,d+n);
	for(i=j=0;j<n;i++,j++)while(c[i]!=d[j])if(i==j)i++;else return puts("-1"),0;
	for(i=j=0;i<n;i++)j+=a[i]!=b[i];
	if(!j)return puts("0"),0;
	m=std::unique(c,c+n+1)-c,j--;
	for(i=0;i<m;i++)fa[i]=i;
	for(i=0;i<n;i++)fa[find(id(a[i]))]=find(id(b[i]));
	for(i=0;i<n;i++)if(a[i]!=b[i]&&!vis[find(id(a[i]))])vis[fa[id(a[i])]]=true,j++;
	if(!vis[find(id(x))])vis[fa[id(x)]]=true,j++;

	printf("%d\n",j);
}
