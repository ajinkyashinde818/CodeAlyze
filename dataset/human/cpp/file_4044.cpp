#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#define _repargs(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _repargs(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define inf 2000000007
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
template <typename T>
inline void output(T a, int p = 0) {
    if(p) cout << fixed << setprecision(p)  << a << "\n";
    else cout << a << "\n";
}
// end of template

struct edge {int to; double cost;};
struct node {int pos; double cost;};
bool operator < (const node &a, const node &b){
    return a.cost > b.cost;
}

vector<double> dijkstra(vector<vector<edge>> &G){
    vector<double> ret(G.size(), inf);
    priority_queue<node> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        node t = pq.top();
        pq.pop();
        
        if (ret[t.pos] == inf) ret[t.pos] = t.cost;
        else continue;
        
        for (edge e : G[t.pos]) {
            pq.push({e.to, t.cost + e.cost});
        }
    }
    return ret;
}

struct barrier {
    double x, y, r;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    double xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    int N;
    cin >> N;
    vector<barrier> B(N + 2);
    vector<vector<edge>> G(N + 2);
    rep(i, 1, N + 1){
        cin >> B[i].x >> B[i].y >> B[i].r;
    }
    B[0] = {xs, ys, 0};
    B[N + 1] = {xt, yt, 0};
    rep(i, N + 2) rep(j, i + 1, N + 2){
        barrier s = B[i], t = B[j];
        double d = sqrt((s.x - t.x) * (s.x - t.x) + (s.y - t.y) * (s.y - t.y));
        double dist;
        if(d <= s.r + t.r) dist = 0;
        else dist = d - s.r - t.r;
        G[i].pb({j, dist});
        G[j].pb({i, dist});
    }
    
    
    auto dijk = dijkstra(G);
    
    output(dijk[N + 1], 10);
    
    return 0;
}
