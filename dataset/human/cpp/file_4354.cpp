#include<bits/stdc++.h>
using namespace std;

int n,ans,col;
int a[200010],b[200010],c[200010],d[200010],fa[200010],used[200010];
int sa[200010];

int find(int i)
{return fa[i]==i?i:fa[i]=find(fa[i]);
}

int main()
{int i,j,k,p,s,x,y,fx,fy,flag;
 
 scanf("%d",&n);
 for(i=1;i<=n;i++) scanf("%d",&a[i]);
 for(i=1;i<=n;i++) scanf("%d",&b[i]);
 for(i=1;i<=n;i++) a[n+1]^=a[i];
 for(i=1;i<=n;i++) b[n+1]^=b[i];
 
 flag=1;
 for(i=1;i<=n;i++)
 	if(a[i]!=b[i])
 	{	flag=0;
 		break;
 	}
 if(flag)
 {	printf("%d\n",0);
 	return 0;
 }
 
 for(i=1;i<=n+1;i++) c[i]=a[i];
 for(i=1;i<=n+1;i++) d[i]=b[i];
 sort(c+1,c+n+2);
 sort(d+1,d+n+2);
 flag=1;
 for(i=1;i<=n+1;i++)
 	if(c[i]!=d[i])
 	{	printf("%d\n",-1);
 		return 0;
 	}
 
 for(i=1;i<=n+1;i++) sa[i]=c[i];
 
 for(i=1;i<=n+1;i++) fa[i]=i;
 
 ans=n;
 for(i=1;i<=n;i++)
 	if(a[i]==b[i])
 		ans--;
 	else
 	{	x=lower_bound(sa+1,sa+n+2,a[i])-sa;
 		y=lower_bound(sa+1,sa+n+2,b[i])-sa;
 		fx=find(x);
 		fy=find(y);
 		if(fx!=fy) fa[fx]=fy;
 	}
 for(i=1;i<=n;i++)
 	if(a[i]!=b[i])
	{	x=lower_bound(sa+1,sa+n+2,a[i])-sa;
		x=find(x);
		if(used[x]==0)
		{	used[x]=1;
			ans++;
		}
	}
 x=lower_bound(sa+1,sa+n+2,a[n+1])-sa;
 x=find(x);
 if(used[x]==1) ans--;

 printf("%d\n",ans);
 return 0;
}
