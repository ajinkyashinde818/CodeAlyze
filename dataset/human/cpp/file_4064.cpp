#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    if(v.size() >= 200) {
        return "Too big length";
    }

    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define reps(i,s,n) for (int i = s; i < (int)(n); ++i)
#define rep1(i,n) for (int i = 1; i <= (int)(n); ++i)
#define per(i,n) for (int i = (int)(n) - 1; i >= 0; --i)
#define all(c) begin(c),end(c)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PINT;
typedef pair<long long, long long> PLL;
void precout(int n = 20) { cout << std::fixed << std::setprecision(n); }
#define print(a) cout << a << endl;
const int INFI = (1 << 30) - 1;
const long long INFLL = (1LL << 62) - 1;
template<typename T> void printv(vector<T>&v) {
    int n = v.size() - 1;
    rep(i, n) cout << v[i] << " ";
    cout << v.back() << endl;
}
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
const int dy8[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
const int dx8[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
double deg2rad(double deg) { return deg * M_PI / 180; }
double rad2deg(double rad) { return rad * 180 / M_PI; }
void yesorno(bool flag) {
    if(flag) print("Yes")
    else print("No");
}
template<typename T> T ceil_int(T A, T B) {
    return (A + (B - T(1))) / B;
}
const long long MOD = 1e9+7;
// const long long MOD = 998244353;

namespace mylib {

template <class Cost> struct dijkstra_graph {
  public:
    dijkstra_graph() : _n(0) {}
    dijkstra_graph(int n) : _n(n), g(n) {}

    void add_edge(int from, int to, Cost cost) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cost);
        g[from].push_back(_edge{to, cost});
    }

    std::vector<Cost> dijkstra(int s) {
        assert(0 <= s && s < _n);

        // using Q = pair<Cost, int>;
        struct Q {
            Cost cost;
            int to;
            bool operator<(Q r) const { return cost > r.cost; }
        };
        std::priority_queue<Q> pq;
        pq.push(Q{Cost{0}, s});

        const Cost unvisit = Cost{-1};
        std::vector<Cost> dist(_n, unvisit);
        dist[s] = Cost{0};

        while (!pq.empty()) {
            Q q = pq.top();
            pq.pop();

            if(dist[q.to] < q.cost) continue;

            for (int i = 0; i < int(g[q.to].size()); i++) {
                _edge e = g[q.to][i];
                Cost cost = q.cost + e.cost;

                if(dist[e.to] == unvisit || dist[e.to] > cost) {
                    dist[e.to] = cost;
                    pq.push(Q{cost, e.to});
                }
            }
        }

        return dist;
    }

  private:
    int _n;
    struct _edge {
        int to;
        Cost cost;
    };
    std::vector<std::vector<_edge>> g;
};

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll xs,ys,xt,yt; cin >> xs >> ys >> xt >> yt;
    int N; cin >> N;
    N += 2;
    mylib::dijkstra_graph<double> dg(N);

    vector<ll> X(N),Y(N),R(N);
    rep(i, N - 2) {
        cin >> X[i] >> Y[i] >> R[i];
    }

    int s = N - 2, t = N - 1;
    X[s] = xs;
    Y[s] = ys;
    R[s] = 0;
    X[t] = xt;
    Y[t] = yt;
    R[t] = 0;

    rep(i, N) {
        reps(j, i + 1, N) {
            double cost = max<double>(0, sqrt(abs(X[i] - X[j]) * abs(X[i] - X[j]) + abs(Y[i] - Y[j]) * abs(Y[i] - Y[j])) - R[i] - R[j]);
            dg.add_edge(i, j, cost);
            dg.add_edge(j, i, cost);
        }
    }

    auto dist = dg.dijkstra(s);
    double ans = dist[t];
    debug(dist);
    precout(20);
    cout << ans << endl;
}
