#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <cstdint>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000000000
#define MAX 200001

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const ll MOD = 1000000007;

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

struct edge{
    int to;
    long double cost;
};

int V = 10000;
vector<edge> G[10000];
long double d[10000];

void dijkstra(int s){
    priority_queue<pair<int,long double>, vector<pair<int,long double>>, greater<pair<int,long double>>> que;
    fill(d, d + V, INF);
    d[s] = 0;
    que.push({0, s});
    while (!que.empty()){
        auto p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i++){
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push({d[e.to], e.to});
            }
        }
    }
}

int main(){
    long double xs,ys,xt,yt;
    cin >> xs >> ys >> xt >> yt;
    int N;
    cin >> N;
    vector<long double> x(N),y(N),r(N);
    rep(i,N) cin >> x[i] >> y[i] >> r[i];
    rep(i,N-1){
        for(int j = i+1; j < N; j++){
            long double xd = x[i] - x[j];
            long double yd = y[i] - y[j];
            long double dd = pow(xd*xd + yd*yd, 0.5);
            dd -= r[i] + r[j];
            if(dd < 0) dd = 0;
            G[i+1].push_back({j+1,dd});
            G[j+1].push_back({i+1,dd});
        }
    }
    rep(i,N){
        long double xd = x[i] - xs;
        long double yd = y[i] - ys;
        long double dd = pow(xd * xd + yd * yd, 0.5);
        dd -= r[i];
        if (dd < 0) dd = 0;
        G[i + 1].push_back({0, dd});
        G[0].push_back({i + 1, dd});
        xd = x[i] - xt;
        yd = y[i] - yt;
        dd = pow(xd * xd + yd * yd, 0.5);
        dd -= r[i];
        if(dd < 0) dd = 0;
        G[i + 1].push_back({N + 1, dd});
        G[N + 1].push_back({i + 1, dd});
    }
    long double xd = xs - xt;
    long double yd = ys - yt;
    long double dd = pow(xd * xd + yd * yd, 0.5);
    G[0].push_back({N+1,dd});
    G[N+1].push_back({0,dd});
    dijkstra(0);
    cout << setprecision(10) << d[N+1] << endl;
}
