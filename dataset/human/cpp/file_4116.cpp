#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <numeric>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <bitset>
#include <queue>

using namespace std;
typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
#define rep(i, n) for(int i = 0;i < n;i++)
//const long long INF = 1LL << 60;
double inf = 1e18;

int MOD = 1000000007;

#define MAX_V 1002
int V;//number of vertices
double d[MAX_V];
bool used[MAX_V];
struct edge{int to; double cost;};
vector<edge> graph[MAX_V];
void dijkstra(int s){
    rep(i,V) d[i]=inf;
    rep(i,V) used[i] = false;

    d[s]=0.0;
    for(int i=0;i<V;i++){
        int id=-1;
        for(int j=0;j<V;j++)if(!used[j]&&(id==-1||d[id]>d[j]))id=j;
        used[id]=true;
        for(int j=0;j<V;j++){
            edge e=graph[id][j];
            d[e.to]=min(d[e.to],d[id]+e.cost);
        }
    }
    return;
}


int main(){
    std::ios_base::sync_with_stdio(false);

    ll xs,ys,xt,yt; cin>>xs>>ys>>xt>>yt;
    int n; cin >> n;

    std::vector<tuple<ll, ll, ll>> nodes;

    nodes.push_back(make_tuple(xs,ys,0));
    rep(i,n){
        ll x,y,r; cin>>x>>y>>r;
        nodes.push_back(make_tuple(x,y,r));
    }
    nodes.push_back(make_tuple(xt,yt,0));

    rep(i,n+2){ rep(j,n+2){
        double di = sqrt(pow(abs(get<0>(nodes[i])-get<0>(nodes[j])), 2.0) + pow(abs(get<1>(nodes[i])-get<1>(nodes[j])), 2.0));
        di-=get<2>(nodes[i])+get<2>(nodes[j]);
        di=max(0.0, di);
        edge e = {j, di};
        graph[i].push_back(e);
    }}


    V = n+2;
    dijkstra(0);
    cout.precision(30);
    cout<<d[n+1]<<endl;

    return 0;
}
