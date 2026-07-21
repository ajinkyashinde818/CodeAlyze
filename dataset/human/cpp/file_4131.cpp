#include<bits/stdc++.h>
using namespace std;

double edge[1002][1002];
double x[1002],y[1002],r[1002];

double dist[1002];
bool visit[1002];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>x[0]>>y[0]>>x[1]>>y[1];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i+1]>>y[i+1]>>r[i+1];
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++)
			edge[i][j]=max(0.0,sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))-r[i]-r[j]);
	dist[0]=0;
	for(int i=1;i<=1001;i++)
		dist[i]=1e20;
	int last;
	while(true){
		last=-1;
		for(int i=0;i<=n+1;i++)
			if(!visit[i])
				if(last==-1||dist[last]>dist[i])
					last=i;
		visit[last]=true;
		for(int i=0;i<=n+1;i++)
			dist[i]=min(dist[i],dist[last]+edge[i][last]);
		if(last==1)	break;
	}
	cout<<fixed<<setprecision(12)<<dist[1]<<endl;
}
