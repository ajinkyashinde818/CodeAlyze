#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m,Px[N],Py[N],Pr[N];
double f[N];
bool vis[N];
inline long long sqr(int x){return 1ll*x*x;}
inline double dis(int x,int y){return sqrt(sqr(Px[x]-Px[y])+sqr(Py[x]-Py[y]));}
inline double Dij(int s,int t){
	for (int i=1;i<=n;++i) f[i]=1e15,vis[i]=0;f[s]=0;
	for (int tim=n;tim--;){
		int nd=0;double nf=1e15;
		for (int i=1;i<=n;++i) if (!vis[i]&&f[i]<nf) nd=i,nf=f[i];
		vis[nd]=1;
		for (int nv=1;nv<=n;++nv) f[nv]=min(f[nv],nf+max(double(0),dis(nv,nd)-Pr[nv]-Pr[nd]));
	}
	return f[t];
}
int main(){
	scanf("%d%d%d%d%d",Px+1,Py+1,Px+2,Py+2,&n);
	n+=2;
	for (int i=3;i<=n;++i) scanf("%d%d%d",Px+i,Py+i,Pr+i);
	printf("%.10lf",Dij(1,2));
	return 0;
}
