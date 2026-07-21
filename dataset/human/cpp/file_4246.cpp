#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;const int N=1e5+10;int n;map <int,int> mp;
int a[N];int b[N];int c[N];int d[N];int S;int ans;
struct bcj
{
	int fa[N];int siz[N];
	inline void ih(){for(int i=1;i<=S;i++)fa[i]=i;for(int i=1;i<=S;i++)siz[i]=1;}
	inline int f(const int& x){return fa[x]=(x==fa[x])?x:f(fa[x]);}
	inline void u(int x,int y)
	{x=f(x);y=f(y);
	//printf("u %d %d\n",x,y);
	if(x==y)return;
	
	ans--;siz[y]+=siz[x];fa[x]=y;}
	inline int getsiz(int x){return siz[f(x)];}
}s;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)a[n+1]^=a[i];for(int i=1;i<=n;i++)b[n+1]^=b[i];
	for(int i=1;i<=n+1;i++)c[i]=a[i];for(int i=1;i<=n+1;i++)d[i]=b[i];
	sort(c+1,c+n+2);sort(d+1,d+n+2);
	for(int i=1;i<=n+1;i++)if(c[i]!=d[i]){printf("-1");return 0;}
	for(int i=1;i<=n+1;i++)if(a[i]!=b[i]||i==n+1){mp[a[i]]=1;mp[b[i]]=1;}
	map <int,int> :: iterator it,it1;S=mp.size();
	if(S==0){printf("0");return 0;}
	for(it=mp.begin(),it1=it,++it1;it1!=mp.end();++it,++it1)it1->second+=it->second;
	ans=S;s.ih();ans--;//printf("%d ",ans);
	for(int i=1;i<=n+1;i++)a[i]=mp[a[i]];
	for(int i=1;i<=n+1;i++)b[i]=mp[b[i]];
	for(int i=1;i<=n+1;i++)if(a[i]!=b[i]){ans++;s.u(a[i],b[i]);}
	if(a[n+1]!=b[n+1]){ans--;}printf("%d",ans);return 0;
}
