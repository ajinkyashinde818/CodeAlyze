#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,double> ii;
const int N=2e6+20;
const double inf=2e15;
int n,inq[N];
double x[N],y[N],r[N],sx,sy,tx,ty;
vector<ii> e[N];
double dis(int i,int j)
{
	double D=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
	return max((double)0,D-(r[i]+r[j]));
}
queue<int> q;
double d[N];
void SPFA(int s,int t)
{
	for(int i=s;i<=t;i++)
		d[i]=inf,inq[i]=0;
	q.push(s);
	d[s]=0,inq[s]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop(),inq[u]=0;
		for(int i=0;i<e[u].size();i++)
		{
			int v=e[u][i].first;
			double w=e[u][i].second;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				if(!inq[v])
					q.push(v),inq[v]=1;
			}
		}
	}
	printf("%.10lf\n",d[t]);
}
int main()
{	
	while(cin>>x[0]>>y[0]>>tx>>ty)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
		n++;
		x[n]=tx,y[n]=ty;
		for(int i=0;i<=n;i++)
			e[i].clear();
		for(int i=0;i<=n;i++)
		{	
			for(int j=0;j<=n;j++)
			{
				if(i==j)	continue;
				e[i].push_back(ii(j,dis(i,j)));
			}
		}
		SPFA(0,n);
	}
    return 0;
}
