#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>

namespace SaoTi
{
	const int N=101000;
	bool cmp(int *s,int *t,int n)
	{
		static int A[N],B[N];
		memcpy(A+1,s+1,n*4),std::sort(A+1,A+n+1);
		memcpy(B+1,t+1,n*4),std::sort(B+1,B+n+1);
		for(int i=1;i<=n;i++)if(A[i]!=B[i])return 0;
		return 1;
	}
	std::map<int,int> id;
	int fa[N],sel[N];
	void reset(int n){for(int i=1;i<=n;i++)fa[i]=i;}
	int ask(int p){return p==fa[p]?p:fa[p]=ask(fa[p]);}
	void link(int u,int v){fa[ask(u)]=ask(v);}

	int A[N],B[N];
	int n,tot;
	void solve()
	{
		scanf("%d",&n);
		A[n+1]=0;
		for(int i=1;i<=n;i++)
			scanf("%d",A+i),A[n+1]^=A[i];
		B[n+1]=0;
		for(int i=1;i<=n;i++)
			scanf("%d",B+i),B[n+1]^=B[i];
		if(!cmp(A,B,n+1)){printf("-1\n");return ;}

		int ans=0;

		reset(n+1);
		for(int i=1,u,v;i<=n;i++)
			if(A[i]!=B[i])
			{
				ans++;
				if(!id.count(A[i]))id[A[i]]=++tot;
				if(!id.count(B[i]))id[B[i]]=++tot;
				u=id[A[i]],v=id[B[i]];
				link(u,v);
			}

		for(int i=1;i<=tot;i++)
			if(fa[i]==i)ans++;
		if(!id.count(A[n+1]))ans++;
		ans--;
		printf("%d\n",ans);
	}
}

int main()
{
	SaoTi::solve();
	return 0;
}
