#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
#include<iomanip>
#include<utility>
#include<cmath>
#include<set>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<set>
#include<cstring>
#include<iterator>
#include<bitset>
#include<assert.h>
using namespace std;
 
typedef long long ll;
//typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;
typedef vector<int> VI;
typedef vector<long long int> VL;
static const int MOD = 1000000007;
//static const int INF = 21474836470;
//static const long long INF = 9223372000000000000;
static const long long INF = 4000000000;
//static const int INF = 1000010000;
//int dx4[4] = {0,1,0,-1}, dy4[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define NP next_permutation
#define PQ priority_queue
#define UB upper_bound
#define LB lower_bound
#define ALL(x) (x).begin(),(x).end()
#define SZ(a) int((a).size())
#define LEN(a) int((a).length())
#define MAX(a,b,c) max((a),max((b),(c)))
#define MIN(a,b,c) min((a),min((b),(c)))
#define SORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REP1(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREP1(i,x) for(int i=((int)(x));i>0;i--)
#define int ll

struct edge {int to;double cost;};
typedef pair<double,int> P;

vector<edge> G[1145];
double d[1145];
int V; //dはKを始点とした最短距離を記録

void dijkstra(int s){   //dijkstraをしました
    PQ<P,vector<P>,greater<P> > que;
    fill(d,d+V,INF);
    d[s] = 0;
    que.push(P(0.0,s));

    while(!que.empty()){
        P p=que.top(); que.pop();
        int v = p.second;
        if(d[v]<p.first) continue;
        for(int i=0;i<G[v].size();i++){
            edge e = G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}

double pyth(int a, int b){  //直角三角形の斜辺を求める std::hypotは知らない
    return sqrt(a*a+b*b);
}

signed main(){
    int sx,sy,gx,gy;
    cin >> sx >> sy >> gx >> gy;
    int n;
    cin >> n;
    int a[1145],b[1145],c[1145];
    REP1(i,n) scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
    a[0] = sx, b[0] = sy, c[0] = 0;
    a[n+1] = gx, b[n+1] = gy, c[n+1] = 0;
    V = n + 2;
    REP(i,V){   //全点対間に辺を張る
        FOR(j,i+1,V){
            double dis = max(0.0,pyth(a[i]-a[j],b[i]-b[j]) - double(c[i]+c[j]));
            edge x,y;
            x.cost = y.cost = dis;
            x.to = j;y.to = i;
            G[i].PB(x);
            G[j].PB(y);
        }
    }

    dijkstra(V-1);

    printf("%.15lf\n",d[0]);

    return 0;
}
