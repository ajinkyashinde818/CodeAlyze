#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iomanip>
#include <sys/time.h>
#include <random>
using namespace std;

#define endl '\n'
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define UNIQ(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

typedef long long ll;
typedef long double ld;
typedef pair<double, int> P;
typedef complex<double> comp;
typedef vector< vector<ld> > matrix;
struct pairhash {
public:
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &x) const {
	size_t seed = hash<T>()(x.first);
	return hash<U>()(x.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
};
const double inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1);

int n;
double x[1010], y[1010], r[1010];

const int MAX = 1010;
struct edge {
    int to;
    double cost;
};

vector<edge> G[MAX];
double d[MAX];

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    for (int i = 0; i < MAX; i++) d[i] = inf;
    d[s] = 0;
    que.push(P(0, s));
    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

double dist(int i, int j) {
    return max(0.0, sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j])) - r[i] - r[j]);
}

double solve() {
    n += 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j)
                G[i].push_back(edge{j, dist(i, j)});
        }
    }
    dijkstra(0);
    return d[n-1];
}

void input() {
    double xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    cin >> n;
    x[0] = xs; y[0] = ys; r[0] = 0;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i] >> r[i];
    x[n+1] = xt; y[n+1] = yt; r[n+1] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
