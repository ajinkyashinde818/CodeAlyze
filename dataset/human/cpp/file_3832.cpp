#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <random>
#include <chrono>
using namespace std;

const int maxn = 1005;
int n;
int x[maxn], y[maxn], r[maxn];
bool vis[maxn];
double dis[maxn];

vector<pair<int, double> > G[maxn];

void add(int u, int v, double w){
    G[u].push_back(make_pair(v, w));
    G[v].push_back(make_pair(u, w));
}

double dijkstra(int s, int t){
    memset(vis, 0, sizeof(vis));
    for(int i = 0;i <= n + 1;i++){
        dis[i] = 1e18;
    }
    dis[s] = 0.0;
    priority_queue<pair<double, int> , vector<pair<double, int> >, greater<pair<double, int> > > pq;
    pq.push(make_pair(0, s));
    while(!pq.empty()){
        pair<double, int> p = pq.top();
        int u = p.second;
        pq.pop();
        if(vis[u])
            continue;
        vis[u] = true;
        for(auto edge : G[u]){
            int v = edge.first;
            double cost = edge.second;
            if(cost + dis[u] < dis[v]){
                dis[v] = dis[u] + cost;
                pq.push(make_pair(dis[v], v));
            }
        }
    }
    return dis[t];
}

int xs, ys, xt, yt;

long long sqr(int x){
    return 1LL * x * x;
}

long long dist(int i, int j){
    return sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
}

int main(){
    cin >> xs >> ys >> xt >> yt;     
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d%d%d", &x[i], &y[i], &r[i]);
    }
    x[0] = xs;
    y[0] = ys;
    x[n + 1] = xt;
    y[n + 1] = yt;
    for(int i = 0;i <= n + 1;i++){
        for(int j = i + 1;j <= n + 1;j++){
            double w = max(0.0, sqrt(dist(i, j)) - r[i] - r[j]);
            add(i, j, w);
        }
    }
    printf("%.10lf\n", dijkstra(0, n + 1));
    return 0;
}
