#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#include<tuple>
#include<bitset>
#include<iomanip>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-15
#define mp(a1,a2) make_pair(a1,a2)
typedef long long ll;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
int N;
vector<pair<int,double> > adj[1002];
double d[1002];
int color[1002],p[1002];
void dijkstra(int s){
	priority_queue<pair<double,int> > PQ;
	rep(i,N){
		d[i]=INFl;
		color[i]=0;
		p[i]=-1;
	}
	d[s]=0;
	color[s]=1;
	PQ.push(mp(0,s));
	while(!PQ.empty()){
		pair<double,int> f=PQ.top();
		PQ.pop();
		int u=f.second;
		color[u]=2;
		if(d[u]< -f.first) continue;
		rep(j,adj[u].size()){
			int v=adj[u][j].first;
			if(color[v]==2) continue;
			if(d[v]>d[u]+adj[u][j].second){
				d[v]=d[u]+adj[u][j].second;
				PQ.push(mp(-d[v],v));
				color[v]=1;
				p[v]=u;
			}
		}
	}
}
int main(){
	pint st,go;
	pint x[1002];
	int r[1002];
	int bnum;
	scan(st.first);scan(st.second);scan(go.first);scan(go.second);
	scan(bnum);
	N=bnum+2;
	x[0]=st,x[bnum+1]=go,r[0]=0,r[bnum+1]=0;
	rep1(i,bnum){
		scan(x[i].first);scan(x[i].second);scan(r[i]);
	}
	rep(i,bnum+1){
		for(int j=i+1;j<=bnum+1;j++){
			double nobarrier=sqrt(pow(x[i].first-x[j].first,2)+pow(x[i].second-x[j].second,2))-(r[i]+r[j]);
			nobarrier=max(nobarrier,0.0);
			adj[j].push_back(mp(i,nobarrier));
			adj[i].push_back(mp(j,nobarrier));
		}
	}
	dijkstra(0);
	prin(setprecision(10)<<d[N-1]);
	return 0;
}
