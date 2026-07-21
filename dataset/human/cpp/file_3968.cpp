#include<cstdio>
#include<cmath>
#include<algorithm>
double a[1002][1002]={};
int n;
double d[1002];
bool used[1002];
void dijkstra(){
	for(int i=0;i<n+2;i++){
		d[i]=10000000000000;
	}
	for(int i=0;i<n+2;i++){
		used[i]=false;
	}
	d[0]=0;
	while(true){	
		int v=-1;
		for(int u=0;u<n+2;u++){
			if(!used[u] && (v==-1 || d[u]<d[v]))v=u;
		}
		if(v==-1)break;
		used[v]=true;
		for(int u=0;u<n+2;u++){
			d[u]=std::min(d[u],d[v]+a[v][u]);
		}
	}
}
int main(){
	long long int xs,ys,xt,yt;
	scanf("%lld%lld%lld%lld%d",&xs,&ys,&xt,&yt,&n);
	long long int x[n+2]={};
	long long int y[n+2]={};
	long long int r[n+2]={};
	x[0]=xs;
	y[0]=ys;
	x[n+1]=xt;
	y[n+1]=yt;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&x[i],&y[i],&r[i]);
	}
	for(int i=0;i<n+2;i++){
		for(int j=0;j<n+2;j++){
			a[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))-(r[i]+r[j]);
			if(a[i][j]<0)a[i][j]=0;
		}
	}
	dijkstra();
	printf("%.11e",d[n+1]);
	return 0;
}
