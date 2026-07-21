#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
template <typename T> 
using lim = numeric_limits<T>;
template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct barrier{
    ll x, y, r;
};

const int N = 1005;
barrier b[N];
vector<pair<int, ld>> graph[N];

int n;
ld dijkstra(int s){
    priority_queue<pair<ld, int>, vector<pair<ld, int>>, greater<pair<ld,int>> > pq;
    vector<ld> dist(n+2, 1e18);

    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for (auto p : graph[u]){
            int v = p.first;
            ld w = p.second;
            if (dist[v] > dist[u]+w){
                dist[v] = dist[u]+w;
                pq.push({dist[v], v});
            }
        }
    } 
    return dist[n+1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    cin >> n;

    b[0] = {xs,ys, 0};
    b[n+1] = {xt, yt, 0};
    for (int i = 1; i <= n; i++){
        int x, y, r;
        cin >> x >> y >> r;
        b[i] = {x,y,r};
    }

    for (int i = 0; i < n+2; i++){
        for (int j = i+1; j < n+2; j++){
            ld dist = sqrtl((b[i].x-b[j].x)*(b[i].x-b[j].x)+(b[i].y-b[j].y)*(b[i].y-b[j].y));
            ld w = dist-(b[i].r+b[j].r);
            w = max((ld)0, w);
            graph[i].push_back({j, w});
            graph[j].push_back({i, w});
        }
    }

    cout << setprecision(10) << fixed << dijkstra(0) << "\n";
}
