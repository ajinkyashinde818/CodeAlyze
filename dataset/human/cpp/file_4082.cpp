#include<iostream>
#include<queue>
#include<cmath>
#include<functional>
#include<vector>
#include<cstdio>
using namespace std;
double px,py,qx,qy,xx[1005],y[1005],r[1005],dist[1005];
int n;vector<pair<int,double> >x[1005];
long double dijkstra(){
	for(int i=0;i<=n+1;i++)dist[i]=9999999999.9l;dist[0]=0;
	priority_queue<pair<double,int>,vector<pair<double,int> >,greater<pair<double,int> > >Q;
	Q.push(make_pair(0.0l,0));
	while(!Q.empty()){
		int a2=Q.top().second;Q.pop();
		for(int i=0;i<(int)x[a2].size();i++){
			if(dist[x[a2][i].first]-(dist[a2]+x[a2][i].second)>=1e-6){
				dist[x[a2][i].first]=dist[a2]+x[a2][i].second;
				Q.push(make_pair(dist[x[a2][i].first],x[a2][i].first));
			}
		}
	}
	return dist[n+1];
}
int main(){
	cin>>xx[0]>>y[0]>>qx>>qy>>n;for(int i=1;i<=n;i++)cin>>xx[i]>>y[i]>>r[i];
	xx[n+1]=qx;y[n+1]=qy;
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=n+1;j++){
			if(i==j)continue;
			long double X1=(xx[i]-xx[j])*(xx[i]-xx[j]);
			long double Y1=(y[i]-y[j])*(y[i]-y[j]);
			long double J=max(0.0l,sqrtl(X1+Y1)-r[i]-r[j]);
			x[i].push_back(make_pair(j,J));
		}
	}
	printf("%.20Lf\n",dijkstra());
	return 0;
}
