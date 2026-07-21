#include <bits/stdc++.h>
using namespace std;

long long n,c,x[100001],v[100001],ni[100001],cur;
long long res=0,ji,nv[100001],book,ans,qian[100001],hou[100001];
struct node
{
    int r,l;
    long long mx;
}tr[800001];
void build1(int rt,int l,int r)
{
    tr[rt].l=l,tr[rt].r=r;
    if(l==r)
    {
        tr[rt].mx=hou[l];
        return;
    }
    int mid=(l+r)>>1;
    build1(rt<<1,l,mid);
    build1(rt<<1|1,mid+1,r);
    tr[rt].mx=max(tr[rt<<1].mx,tr[rt<<1|1].mx);
}
void build2(int rt,int l,int r)
{
    tr[rt].l=l,tr[rt].r=r;
    if(l==r)
    {
        tr[rt].mx=qian[l];
        return;
    }
    int mid=(l+r)>>1;
    build2(rt<<1,l,mid);
    build2(rt<<1|1,mid+1,r);
    tr[rt].mx=max(tr[rt<<1].mx,tr[rt<<1|1].mx);
}
long long query(int rt,int L,int R)
{
    int l=tr[rt].l,r=tr[rt].r;
    if(L<=l&&r<=R)
    {
        return tr[rt].mx;
    }
    long long ret=0;
    int mid=(l+r)>>1;
    if(L<=mid)
    ret=max(ret,query(rt<<1,L,R));
    if(R>mid)
    ret=max(ret,query(rt<<1|1,L,R));
    return ret;
}  
int main()
{
	scanf("%lld%lld",&n,&c);
	for(int i=1;i<=n;i++)
	scanf("%lld%lld",&x[i],&v[i]);
	for(int i=1;i<=n;i++)
	{
		ni[i]=c-x[n-i+1];
		nv[i]=v[n-i+1];
		qian[i]=qian[i-1]+v[i];
		hou[i]=hou[i-1]+nv[i];
	}
	for(int i=1;i<=n;i++)
	{
		qian[i]-=x[i];
		hou[i]-=ni[i];
	}
	build1(1,1,n);	
	for(int i=1;i<=n;i++)
	{
		res=max(res,qian[i]);
//		cout<<res<<" ";
		cur=qian[i];
		book=0;
		ji=0;
		if(n-i>0)
		ji=query(1,1,n-i);
//		cout<<ji<<" ";
		res=max(res,cur+ji-x[i]);
//		cout<<res<<endl;
	}
	build2(1,1,n);
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,hou[i]);
		cur=hou[i];
		book=0;
		ji=0;
/*		for(int j=1;j<=n-i;j++)
		{
			if(qian[j]>ji)
			{
				ji=qian[j];
				book=j;
			}
		}*/
		if(n-i>0)
		ji=query(1,1,n-i);
		ans=max(ans,cur+ji-ni[i]);
	}
	res=max(res,ans);
	printf("%lld\n",res);
	return 0;
}
