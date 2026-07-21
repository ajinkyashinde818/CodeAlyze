#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N;
vector<int>G[1<<17];
int d[1<<17];
int parent[20][1<<17];
main()
{
	cin>>N;
	parent[0][0]=-1;
	for(int i=1;i<N;i++)
	{
		int p;cin>>p;p--;
		parent[0][i]=p;
		G[p].push_back(i);
	}
	for(int k=0;k<19;k++)
	{
		for(int i=0;i<N;i++)if(parent[k][i]>=0)parent[k+1][i]=parent[k][parent[k][i]];
	}
	vector<int>a;
	queue<int>P;
	P.push(0);
	d[0]=0;
	while(!P.empty())
	{
		int u=P.front();
		P.pop();
		a.push_back(u);
		for(int i=0;i<G[u].size();i++)
		{
			d[G[u][i]]=d[u]+1;
			P.push(G[u][i]);
		}
	}
	long ans=0;
	for(int i=1;i<a.size();i++)
	{
		int x=a[i-1],y=a[i];
		if(d[x]>d[y])x^=y^=x^=y;
		ans+=d[x]+d[y];
		for(int k=20;k--;)
		{
			if(d[y]-d[x]>>k&1)y=parent[k][y];
		}
		for(int k=20;k--;)
		{
			if(parent[k][x]!=parent[k][y])
			{
				x=parent[k][x];
				y=parent[k][y];
			}
		}
		if(x!=y)x=parent[0][x];
		ans-=2*d[x];
	}
	cout<<ans<<endl;
}
