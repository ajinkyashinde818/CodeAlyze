#include <bits/stdc++.h>
const int N=1005;
typedef long double lb;
int vis[N],x[N],y[N],r[N],n;
lb dis[N];
lb Dis(int i,int j){
	lb res=sqrt((x[i]-x[j])*1.0*(x[i]-x[j])+1.0*(y[i]-y[j])*(y[i]-y[j]));
	return std::max((lb)0,res-r[i]-r[j]);
}
void dij(int s){
	for (int i=1;i<=n+1;i++) dis[i]=10000000000000;
	for (int i=1;i<=n+2;i++){
		int t=-1;
		for (int j=0;j<=n+1;j++)
			if ((dis[j]<dis[t] || t==-1) && !vis[j]) t=j;
		vis[t]=1;
		if (t==1) break;
		for (int j=0;j<=n+1;j++)
			if (dis[j]>dis[t]+Dis(j,t)) dis[j]=dis[t]+Dis(j,t);
	}
}
int main(){
	scanf("%d%d%d%d",&x[0],&y[0],&x[1],&y[1]);
	scanf("%d",&n);
	for (int i=2;i<=n+1;i++)
		scanf("%d%d%d",&x[i],&y[i],&r[i]);
	dij(0);
	printf("%.10Lf",dis[1]);
}
