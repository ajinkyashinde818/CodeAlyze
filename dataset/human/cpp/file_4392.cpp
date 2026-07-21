#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
map<int,int> num;
int a[101010],b[101010];
int rt[101010];
bool mk[101010];
int getr(int x)
{
	if(x==rt[x])
		return x;
	rt[x]=getr(rt[x]);
	return rt[x];
}
int main()
{
	int n,cnt=0,ans=0,an,bn;
	scanf("%d",&n);
	n++;
	a[n]=b[n]=0;
	num.clear();
	for(int i=1;i<n;i++)
	{
		scanf("%d",&a[i]);
		a[n]^=a[i];
		if(!num.count(a[i]))
			num[a[i]]=++cnt;
	}
	if(!num.count(a[n]))
		num[a[n]]=++cnt;
	for(int i=0;i<=cnt;i++)
		rt[i]=i;
	for(int i=1;i<n;i++)
	{
		scanf("%d",&b[i]);
		b[n]^=b[i];
	}
	memset(mk,0,sizeof(mk));
	for(int i=1;i<n;i++)
		if(a[i]!=b[i])
		{
			ans++;
			an=num[a[i]];
			bn=num[b[i]];
			mk[an]=mk[bn]=true;
			rt[getr(an)]=getr(bn);
		}
	if(mk[num[a[n]]])
		ans--;
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++)
		if(a[i]!=b[i])
		{
			printf("-1");
			return 0;
		}
	for(int i=1;i<=cnt;i++)
		if(mk[i]&&rt[i]==i)
			ans++;
	printf("%d",ans);
	return 0;
}
