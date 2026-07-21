#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <cassert>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<P,int> T;
typedef pair<T,int> F;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
struct edge
{
	int to,cost;
	edge(int to,int cost):to(to),cost(cost){}
};
int N,M,K;
int t[100100];
int day[100100],dist[100100];
int x[100100],d[100100],p[100100];
int par[100100][20];
vector<edge> G[100100];
bool used[100100];
priority_queue<F,vector<F>,greater<F> > q;
int ascend(int v,int k)
{
	for(int i=19;i>=0;i--)
	{
		if(k&(1<<i))v=par[v][i];
	}
	return v;
}
int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)scanf("%d",&t[i]);
	for(int i=0;i<M;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		a--;b--;
		G[a].pb(edge(b,c));
		G[b].pb(edge(a,c));
	}
	scanf("%d",&K);
	for(int i=0;i<K;i++)
	{
		scanf("%d %d %d",&x[i],&d[i],&p[i]);
		x[i]--;
	}
	memset(used,false,sizeof(used));
	for(int i=0;i<N;i++)day[i]=INF,dist[i]=INF;
	day[0]=0;dist[0]=0;
	q.push(F(T(P(0,0),t[0]),0));
	par[0][0]=-1;
	while(!q.empty())
	{
		F a = q.top();
		q.pop();
		int v = a.sec;
		int date = a.fi.fi.sec;
		int dis = a.fi.fi.fi;
		for(int i=0;i<G[v].size();i++)
		{
			edge e = G[v][i];
			if(dist[e.to]>dis+e.cost){
				day[e.to]=date+1;
				dist[e.to]=dis+e.cost;
				par[e.to][0]=v;
				q.push(F(T(P(dist[e.to],day[e.to]),t[e.to]),e.to));
				continue;
			}
			if(dist[e.to]==dis+e.cost&&day[e.to]>date+1){
				day[e.to]=date+1;
				dist[e.to]=dis+e.cost;
				par[e.to][0]=v;
				q.push(F(T(P(dist[e.to],day[e.to]),t[e.to]),e.to));
				continue;
			}
			if(dist[e.to]==dis+e.cost&&day[e.to]==date+1&&t[par[e.to][0]]>t[v]){
				day[e.to]=date+1;
				dist[e.to]=dis+e.cost;
				par[e.to][0]=v;
				q.push(F(T(P(dist[e.to],day[e.to]),t[e.to]),e.to));
				continue;
			}
		}
	}
	/*for(int i=0;i<N;i++)
	{
		printf("%d %d %d\n",day[i],dist[i],par[i][0]);
	}*/
	for(int i=0;i<19;i++)
	{
		for(int v=0;v<N;v++)
		{
			if(par[v][i]==-1)par[v][i+1]=-1;
			else par[v][i+1]=par[par[v][i]][i];
		}
	}
	for(int i=0;i<K;i++)
	{
		if(day[x[i]]<=d[i])printf("%d\n",max(0,dist[x[i]]-p[i]));
		else
		{
			int k = day[x[i]]-d[i];
			assert(k<=day[x[i]]);
			int y = ascend(x[i],k);
			//printf("y %d\n",y);
			if(dist[y]<=p[i])printf("%d\n",dist[x[i]]-dist[y]);
			else printf("%d\n",dist[x[i]]-p[i]);
		}
	}
	return 0;
}
