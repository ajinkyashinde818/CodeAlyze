#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;
ll MOD = 1e9+7;
//LLONG_MIN

//WA

int main(void){
	ll N,xs,ys,xt,yt,x[1010],y[1010],r[1010];
	double d[1010],dist[1010][1010];
	scanf("%lld%lld%lld%lld",&xs,&ys,&xt,&yt);
	scanf("%lld",&N);
	reg(i,1,N)scanf("%lld%lld%lld",&x[i],&y[i],&r[i]);
	x[0]=xs; y[0]=ys; r[0]=0;
	x[N+1]=xt; y[N+1]=yt; r[N+1]=0;
	rep(i,N+2){
		reg(j,0,i){
			double c=0,l=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			if(l-r[i]-r[j]>0)c=l-r[i]-r[j];
			dist[i][j]=c;
			dist[j][i]=c;
		}
	}
	rep(i,N+2)d[i]=1e16;
	queue<ll> Q;
	d[0]=0;
	Q.push(0);
	while(!Q.empty()){
		ll p = Q.front();Q.pop();
		rep(i,N+2){
			if(d[i]>d[p]+dist[i][p]){
				d[i]=d[p]+dist[i][p];
				Q.push(i);
			}
		}
	}
	cout.precision(15);
	cout<<d[N+1]<<endl;
	return 0;
}
