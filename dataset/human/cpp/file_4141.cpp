#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<double,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
double gr[1010][1010];
double x[1010],y[1010],r[1010];
double dp[1010];
bool sumi[1010];
priority_queue<pint> q;
void aedge(int x,double y){
	if(dp[x]<=y) return;
	q.push(mp(-y,x));dp[x]=y;
}
double sq(double a){return a*a;}
int main()
{
	int n;
	cin>>x[0]>>y[0]>>x[1]>>y[1];r[0]=r[1]=0;
	cin>>n;
	rep(i,n) cin>>x[2+i]>>y[2+i]>>r[2+i];
	rep(i,n+2) rep(j,n+2){
		double d=sqrt(sq(x[i]-x[j])+sq(y[i]-y[j]));
		gr[i][j]=max(0.0,d-r[i]-r[j]);
		//cout<<i<<' '<<j<<' '<<gr[i][j]<<endl;
	}
	memset(sumi,false,sizeof(sumi));
	rep(i,1005) dp[i]=1e11;
	aedge(0,0);
	while(!q.empty()){
		pint p=q.top();q.pop();
		int x=p.se;double y=-p.fi;
		//cout<<x<<' '<<y<<endl;
		if(sumi[x]) continue;
		sumi[x]=true;
		rep(i,n+2) aedge(i,y+gr[x][i]);
	}
	printf("%.12f\n",dp[1]);
}
