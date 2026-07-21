#include<bits/stdc++.h>
using namespace std;


typedef double ld;
const int N=1010;
int x[N],y[N],r[N],n,vis[N];
ld dis[N][N],d[N];


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>x[1]>>y[1]>>x[2]>>y[2]>>n;n+=2;
	for(int i=3;i<=n;++i)cin>>x[i]>>y[i]>>r[i];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)if(i!=j)dis[i][j]=max(0.,hypot(x[i]-x[j],y[i]-y[j])-r[i]-r[j]);
	for(int i=1;i<=n;++i)d[i]=INFINITY;d[1]=0;
	for(int i=1;i<=n;++i){
		ld mn=INFINITY;int id=0;
		for(int j=1;j<=n;++j)if(!vis[j]&&d[j]<mn)mn=d[j],id=j;
		if(id==2){
			cout<<fixed<<setprecision(10)<<mn<<'\n';
			return 0;
		}
		vis[id]=1;
		for(int j=1;j<=n;++j)if(j!=id)d[j]=min(d[j],mn+dis[id][j]);
	}
	return 0;
}
