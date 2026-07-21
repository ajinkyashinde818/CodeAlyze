#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#include <iomanip>
#include <complex>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define SIZE 200005

using namespace std;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
typedef pair<int,ll> pill; typedef pair<ll,int> plli; 
typedef pair<double, int> pdi;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
typedef complex<double> P;

double dist[1010][1010];
double d[1010];
int N;
void dijkstra(int start){
	priority_queue<pdi, vector<pdi>,greater<pdi> > que;
	for(int i=0;i<N+2;i++)d[i]=10000000000.0;
	d[start] = 0.0;
	que.push( mp(0.0,start) );//cost,ver
	
	while(!que.empty()){
		pdi p=que.top();
		que.pop();
		
		int v=p.second;
		if(d[v]<p.first)continue;
		
		for(int i=0;i<N+2;i++){
			double e=dist[v][i];
			if(d[i]>d[v]+e){
				d[i]=d[v]+e;
				que.push(mp(d[i],i));
			}
		}
	}
	
}
int main(){
	double x,y,r;
	vector<pair<pair<double,double>,double> > data;
	cin>>x>>y;
	data.pb( mp(mp(x,y),0.0) );
	cin>>x>>y;
	data.pb( mp(mp(x,y),0.0) );
	cin>>N;
	
	for(int i=0;i<N;i++){
		cin>>x>>y>>r;
		data.pb( mp(mp(x,y),r) );
	}
	for(int i=0;i<N+2;i++){
		double x1=data[i].first.first,y1=data[i].first.second,r1=data[i].second;
		for(int j=i;j<N+2;j++){
			double x2=data[j].first.first,y2=data[j].first.second,r2=data[j].second;
			dist[i][j]=max(0.0,sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))-r1-r2);
			dist[j][i]=dist[i][j];
		}
	}
	dijkstra(0);
	printf("%.10f\n",d[1]);
}
