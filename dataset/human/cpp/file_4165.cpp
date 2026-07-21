#include <bits/stdc++.h>

using namespace std;

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1000000000;
const ll LINF = (ll) 4000000000000000000;
const ll MOD = (ll) 1000000007;
const double PI = acos(1.0);
const int limit = 100010;

#define REP(i,m,n) for(ll i = m; i < (ll)(n); ++i)
#define rep(i,n) REP(i, 0, n)
#define MP make_pair
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl
#define NP(v) next_permutation(v.begin(),v.end())
#define smaller_queue  priority_queue <ll, vector<ll>, greater<ll> >
#define smaller_queue_p  priority_queue <pll, vector<pll>, greater<pll> >
//------------------------------------------------------
using pd = pair<ld, ld>;

template <typename T, typename U> class dijkstra {
public:

    struct edge {
        T to;
        U cost;
    };

    typedef pair<U, T> P;
    map<T, vector<edge> > E;
    map<T, U> d;

    void calc(T s) {
        priority_queue <P, vector<P>, greater<P> > que;
        REP(i, -1, limit) d[i] = LINF;
        que.emplace((U) 0, s);
        d[s] = 0;
        while (!que.empty()) {
            P p = que.top();
            que.pop();
            T v = p.second;
            if (d[v] < p.first) continue;

            for (auto& e : E[v]) {
                if (d[e.to] > d[v] + e.cost) {
                    d[e.to] = d[v] + e.cost;
                    que.emplace(d[e.to], e.to);
                }
            }
        }
    }
};

struct query {
    ld x, y, r;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    dijkstra<int, ld> ds;
    map<int, query> Q;

    ld xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    int n;
    cin >> n;
    Q[-1] = {xs, ys, 0.0};
    Q[n] = {xt, yt, 0.0};

    rep(i, n) {
        ld xi, yi, ri;
        cin >> xi >> yi >> ri;
        Q[i] = {xi, yi, ri};
    }

    for (int i = -1; i <= n; ++i) for (int j = -1; j <= n; ++j) {
            if (i == j) continue;
            ld c = max((ld) 0, sqrt((Q[i].x - Q[j].x)*(Q[i].x - Q[j].x) + (Q[i].y - Q[j].y)*(Q[i].y - Q[j].y))
                    - Q[i].r - Q[j].r);
            ds.E[i].push_back({j, c});
        }

    ds.calc(-1);
    cout << setprecision(20) << ds.d[n] << endl;

    return 0;
}
