#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;

int a[100010],b[100010],n;
map<int,int> mp,mp1;
int cnt,tot,fa[200010];
int sz;

int get(int x)
{
	int i=x,j;
	while(fa[x]!=x)	x=fa[x];
	while(fa[i]!=x)	j=fa[i],fa[i]=x,i=j;
	return x;
}

void merge(int x,int y)
{
	x=get(x),y=get(y);
	if(x!=y)	fa[x]=y;
}

int main()
{
	int i,j,k,x=0,ans=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)	scanf("%d",&a[i]),x^=a[i],mp[a[i]]++;
	mp[x]++;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		if(!mp[b[i]])	ans=0;
		else	mp[b[i]]--;
	}
	if(!ans)
	{
		printf("-1\n");
		return 0;
	}
	else
	{
		ans=0;
		for(i=1;i<=(n<<1)+1;i++)	fa[i]=i;
		for(i=1;i<=n;i++)
		{
			if(a[i]!=b[i])
			{
				ans++;
				if(!mp1[a[i]])	mp1[a[i]]=++cnt;
				if(!mp1[b[i]])	mp1[b[i]]=++cnt;
				merge(mp1[a[i]],mp1[b[i]]);
			}
		}
		if(!ans)
		{
			printf("0\n");
			return 0;
		}
		if(!mp1[x])	mp1[x]=++cnt;
		for(i=1;i<=cnt;i++)	if(get(i)==i)	ans++;
		printf("%d\n",ans-1);
	}
	return 0;
}
