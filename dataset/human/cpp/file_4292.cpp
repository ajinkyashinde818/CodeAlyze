#include<bits/stdc++.h>

int a[100005],b[100005],n,x;

int q[200005],bkt[200005],c;

int f[100005];
int anc(int x){return f[x]?f[x]=anc(f[x]):x;}
void uni(int x,int y){if((x=anc(x))!=(y=anc(y)))f[x]=y,--c;}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
	scanf("%d",&a[i]),x^=a[i],q[++c]=a[i];
    for(int i=1;i<=n;++i)
	scanf("%d",&b[i]),q[++c]=b[i];

    q[++c]=x;
    std::sort(q+1,q+c+1);
    c=std::unique(q+1,q+c+1)-q-1;

    ++bkt[x=std::lower_bound(q+1,q+c+1,x)-q];
    for(int i=1;i<=n;++i)
    {
	a[i]=std::lower_bound(q+1,q+c+1,a[i])-q;
	b[i]=std::lower_bound(q+1,q+c+1,b[i])-q;

	++bkt[a[i]],--bkt[b[i]];
    }

    for(int i=1;i<=c;++i)
	if(bkt[i]<0)return puts("-1"),0;

    c=0,bkt[x]=978978;
    for(int i=1;i<=n;++i)
	if(a[i]!=b[i])
	{
	    if(bkt[a[i]]!=978978)++c,bkt[a[i]]=978978;
	    if(bkt[b[i]]!=978978)++c,bkt[b[i]]=978978;
	    uni(b[i],a[i]),++c;
	}
    
    printf("%d\n",c);
    
    return 0;
}
