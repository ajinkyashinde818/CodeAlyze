#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

#define Rep(b, e, i) for(int i = b; i <= e; i++)
#define Repr(e, b, i) for(int i = e; i >= b; i--)
#define rep(n, i) Rep(0, n-1, i)
#define repr(n, i) Repr(n-1, 0, i)
#define all(v) (v).begin(), (v).end()
#define pb(v) push_back(v)
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define bitcnt(x) __builtin_popcount(x)

typedef long long ll;
typedef pair<double, double> P;
typedef std::priority_queue<int> IntPrioQueue; //Z->A
typedef std::priority_queue<int, std::vector<int>, std::greater<int> > IntReversePrioQueue; //A->Z

//vector の中身を出力
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

const ll INF = 1e18;

const int MAX_V = 1010;

struct edge{int to; double cost;};

//V := number of nodes
//G := adj
int V;
vector<edge> G[MAX_V];
double d[MAX_V];
void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        rep((int)G[v].size(), i) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

double dis(double x1, double y1, double x2, double y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void solve(void){
    int sx, sy, gx, gy, N;
    cin >> sx >> sy >> gx >> gy >> N;
    V = N + 2;
    vector <double> xs(N), ys(N), rs(N);
    rep(N, i) {
        cin >> xs[i] >> ys[i] >> rs[i];
    }

    G[0].push_back(edge{N+1, dis(sx, sy, gx, gy)});
    G[N+1].push_back(edge{0, dis(sx, sy, gx, gy)});
    rep(N, i) {
        G[i+1].push_back(edge{0, max(0., dis(sx, sy, xs[i], ys[i])-rs[i])});
        G[i+1].push_back(edge{N+1, max(0., dis(gx, gy, xs[i], ys[i])-rs[i])});
        G[0].push_back(edge{i+1, max(0., dis(sx, sy, xs[i], ys[i])-rs[i])});
        G[N+1].push_back(edge{i+1, max(0., dis(gx, gy, xs[i], ys[i])-rs[i])});
    }
    rep(N, i) Rep(i+1, N-1, j) {
        G[i+1].push_back(edge{j+1, max(0., dis(xs[i], ys[i], xs[j], ys[j])-rs[i]-rs[j])});
        G[j+1].push_back(edge{i+1, max(0., dis(xs[i], ys[i], xs[j], ys[j])-rs[i]-rs[j])});
    }

    dijkstra(0);

    printf("%.10lf\n", d[N+1]);

}

int main(void){
  solve();
  //cout << "yui(*-v・)yui" << endl;
  return 0;
}
