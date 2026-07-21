#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
const int N=2e5+10;
int a[N],b[N],c[N],d[N],f[N],n;
map<int,int> t;
int get(int x)
{
	if (f[x]==x) return x;
	return f[x]=get(f[x]);
}
int main()
{
	scanf("%d",&n);
	int x=0;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++)x=x^a[i];
	a[n+1]=x;
	int y=0;
	for (int i=1;i<=n;i++) y=y^b[i];
	b[n+1]=y;
	for (int i=1;i<=n+1;i++)
	{
		c[i]=a[i];
		d[i]=b[i];
	}
	n++;
	sort(c+1,c+n+1);
	sort(d+1,d+n+1);
	for (int i=1;i<=n+1;i++)
	{
		if (c[i]!=d[i]) 
		{
			if (i<=n) 
			{
				puts("-1");
				return 0;
			}
			break;
		}
	}
	int ans=0,num=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]!=b[i]||i==n)
		{
			if (i<n) ans++;
			if (!t[a[i]]) num++,t[a[i]]=num;
			if (!t[b[i]]) num++,t[b[i]]=num;
		}
	}
	if (ans==0)
	{
		puts("0");
		return 0;
	}
	for (int i=1;i<=num;i++) f[i]=i;
	for (int i=1;i<=n;i++) if (a[i]!=b[i]) f[get(t[a[i]])]=get(t[b[i]]);
	for (int i=1;i<=num;i++) if (f[i]==i) ans++;
	printf("%d\n",ans-1); 
}
