// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("no-stack-protector")
// #pragma GCC optimize("fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,popcnt,avx,avx2,tune=native")

#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;

const ll LINF = 9187201950435737471;
const ll nLINF = -9187201950435737472;
const ll INF = 2139062143;
const int nINF = -2139062144;
const ull ULINF = numeric_limits<ull>::max();
const ll MAXN = 1000 + 15;
const ll MAXE = 1000 + 15;
const double PI = acos(-1);
const ll MOD = 998244353;
const double EPS = 1e-10;
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rnd(seed);

bool isEqual(double a, double b) {
    return abs(a - b) <= EPS;
}

#define all(_v) _v.begin(), _v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)(v.size())
#define sqr(_v) ((_v) * (_v))
#define vpi vector<pair<int, int>>
#define eb emplace_back
#define pb push_back
#define mod(x, m) ((x) % m + ((x) < 0  && ((x % m) != 0) ? m : 0))
#define vi vector<int>
#define pi pair<int, int>
#define minq(x, y) (x) = min(x, y)
#define maxq(x, y) (x) = max(x, y)


inline void IO() {
#if(DEBUG_LEVEL > 0)
    freopen("../input.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
}

template <typename T>
istream& operator >> (istream& in, vector<T>& a) {
    for (auto& i : a)
        in >> i;
    return in;
}

template <typename T>
ostream& operator << (ostream& out, const vector<T>& a) {
    for (auto& i : a) {
        out << i << " ";
    }
    return out;
}

template <typename T, typename D>
istream& operator >> (istream& in, pair<T, D>& a) {
    in >> a.first >> a.second;
    return in;
}

template <typename T, typename D>
ostream& operator << (ostream& out, const pair<T, D>& a) {
    out << a.first << " " << a.second;
    return out;
}

#define int ll
#define double long double

double dist[MAXN];
bool used[MAXN];

struct circle{
    int x, y, r;
    circle(int xx = 0, int yy = 0, int rr = 0) {
        x = xx;
        y = yy;
        r = rr;
    }
    double dist(const circle& p) const {
        double rast = sqrt(sqr(p.x - x) + sqr(p.y - y));
        return max((double)0, rast - p.r - r);
    }
};

inline void solve() {
    for (int i = 0; i < MAXN; ++i) {
        dist[i] = LINF;
    }
    vector <circle> a;
    int x, y;
    cin >> x >> y;
    a.pb({x, y, 0});
    cin >> x >> y;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int xx, yy, rr;
        cin >> xx >> yy >> rr;
        a.pb({xx, yy, rr});
    }
    a.pb({x, y, 0});
    dist[0] = 0;
    n += 2;
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!used[j] && (v == -1 || dist[j] < dist[v])) {
                v = j;
            }
        }
        if (v == -1) {break;}
        used[v] = 1;
        for (int j = 0; j < n; ++j) {
            if (used[j]) {continue;}
            dist[j] = min(dist[j], dist[v] + a[v].dist(a[j]));
        }
    }
    cout << setprecision(9) << fixed;
    cout << dist[n - 1] + EPS;
}

signed main() {
    IO();
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
