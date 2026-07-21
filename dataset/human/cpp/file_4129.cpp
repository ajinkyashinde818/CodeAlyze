#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef pair<ldb,ll> P;
typedef double db;


ll sx,sy,tx,ty,x[1002],y[1002],r[1002];
ll n;
ldb d[1002][1002];
ldb D[1002];
                     
int main()
{
	scanf("%lld%lld%lld%lld",&sx,&sy,&tx,&ty);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld%lld%lld",&x[i],&y[i],&r[i]);
		d[i][0]=d[0][i]=sqrt((x[i]-sx)*(x[i]-sx)+(y[i]-sy)*(y[i]-sy))-r[i];
		d[n+1][i]=d[i][n+1]=sqrt((x[i]-tx)*(x[i]-tx)+(y[i]-ty)*(y[i]-ty))-r[i];
		if(d[0][i]<0)d[0][i]=d[i][0]=0;
		if(d[n+1][i]<0)d[n+1][i]=d[i][n+1]=0;
	}
	d[0][n+1]=d[n+1][0]=sqrt((sx-tx)*(sx-tx)+(sy-ty)*(sy-ty));
	fill(D,D+1002,1000000000000);
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(i==j){
				d[i][j]=0;
				continue;
			}
			d[i][j]=sqrt( (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])) -r[i]-r[j] ;
			if(d[i][j]<0) d[i][j]=0;
		}
	}
	d[0][0]=d[n+1][n+1]=0;
	D[0]=0;
	priority_queue<P,vector<P>,greater<P> > q;
	q.push(P(0,0));
	while(!q.empty()){
		P p=q.top();
		q.pop();
		ll x=p.second;
		if(p.first>D[x]) continue;
		for(ll i=0;i<=n+1;i++){
			if(i==x) continue;
			if(D[i]>D[x]+d[x][i]){
				D[i]=D[x]+d[x][i];
				q.push(P(D[i],i));
			}
		}
	}
	//for(ll i=0;i<n+2;i++){
	//	for(ll j=0;j<n+2;j++){
	//	cout<<"d["<<i<<"]["<<j<<"]="<<d[i][j]<<endl;
	//	}
	//}
	printf("%.14Lf\n",D[n+1]);
}
