#include<cstdio>
#include<algorithm>
using namespace std;

int n,a[300012],b[300012],h[300012],cnt=0,now,ans,num[300012];
int fa[300012],vis[300012];

int find(int x){
	if (fa[x]==x)
	  return x;
	return fa[x]=find(fa[x]);
}

int main(){
//	freopen("duliu.in","r",stdin);
//	freopen("duliu.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	  scanf("%d",&a[i]),now^=a[i],h[++cnt]=a[i],a[n+1]^=a[i];
	for (int i=1;i<=n;i++)
	  scanf("%d",&b[i]),h[++cnt]=b[i],b[n+1]^=b[i];
	h[++cnt]=now;
	h[++cnt]=a[n+1];
	h[++cnt]=b[n+1];
	sort(h+1,h+1+cnt);
	cnt=unique(h+1,h+1+cnt)-h-1;
	for (int i=1;i<=n+1;i++)
	  a[i]=lower_bound(h+1,h+1+cnt,a[i])-h;
	for (int i=1;i<=n+1;i++)
	  b[i]=lower_bound(h+1,h+1+cnt,b[i])-h;
	now=lower_bound(h+1,h+1+cnt,now)-h;
	for (int i=1;i<=cnt;i++)
	  fa[i]=i;
	for (int i=1;i<=n+1;i++)
	  if (a[i]!=b[i])
	  {
	    ans++;
		fa[find(a[i])]=find(b[i]);
	  }
	if (ans==0)
	{
	  printf("%d\n",ans);
	  return 0;
	}
	for (int i=1;i<=n+1;i++)
	  if (a[i]!=b[i])
	    vis[find(a[i])]=1;
	for (int i=1;i<=cnt;i++)
	  ans+=vis[i];
	if (a[n+1]!=b[n+1])
	  ans--;
	if (vis[find(a[n+1])])
	  ans--;
	
	for (int i=1;i<=n;i++)
	  num[a[i]]++;
	num[now]++;
	for (int i=1;i<=n;i++)
	{
	  num[b[i]]--;
	  if (num[b[i]]<0)
	  {
	    ans=-1;
		break;
	  }
	}
	printf("%d\n",ans);
	return 0;
}
