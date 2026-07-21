#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#include <unordered_set>
#include <unordered_map>

using namespace std;

#define all(c) ((c).begin()), ((c).end())
#define dump(c) cerr << "> " << #c << " = " << (c) << endl;
#define iter(c) __typeof((c).begin())
#define tr(i, c) for (iter(c) i = (c).begin(); i != (c).end(); i++)
#define REP(i, a, b) for (int i = a; i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define mp make_pair
#define fst first
#define snd second
#define pb push_back
#define debug( fmt, ... ) \
        fprintf( stderr, \
                  fmt "\n", \
                  ##__VA_ARGS__ \
        )

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1 << 30;
const double EPS = 1e-10;

double zero(double d) {
    return d < EPS ? 0.0 : d;
}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    return os << '(' << p.first << ',' << p.second << ')';
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &a) {
    os << '[';
    rep(i, a.size()) os << (i ? " " : "") << a[i];
    return os << ']';
}

string toString(int i) {
    stringstream ss;
    ss << i;
    return ss.str();
}

const int MOD = 1000000007;
// a^k
ll fpow(ll a, ll k, int M) {
    ll res = 1ll;
    ll x = a;
    while (k != 0) {
        if ((k & 1) == 1)
            res = (res * x) % M;
        x = (x * x) % M;
        k >>= 1;
    }
    return res;
}

struct prepare {
	prepare() {
	    cout.setf(ios::fixed, ios::floatfield);
	    cout.precision(12);
	    ios_base::sync_with_stdio(false);
	}
} _prepare;

struct Edge{
    int to;
    double cost;
};

vector<double> dijkstra(int start, vector< vector<Edge> >& graphs) {
    priority_queue<pii, vector<pii>, greater<pii> > que;
    vector<double> d(graphs.size(), 1ll<<50);
    d[start] = 0;
    que.push(mp(0, start));

    while(!que.empty()){
        pii p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first)
            continue;

        tr(it, graphs[v]) {
            if(d[it->to] > d[v] + it->cost) {
                d[it->to] = d[v] + it->cost;
                que.push(mp(d[it->to], it->to));
            }
        }
    }

    return d;
}


struct Info {
    int x;
    int y;
    int r;
};

int main() {
	int xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    int N;
    cin >> N;

    vector<Info> info(N+2);
    rep(i, N) {
        int x, y, r;
        cin >> x >> y >> r;
        info[i] = Info({x,y,r});
    }
    info[N] = Info({xs, ys, 0});
    info[N+1] = Info({xt, yt, 0});

    vector< vector<Edge> > graphs(N+2);
    rep(i, N+2) {
        REP(j, i+1, N+2) {
            double dx = info[i].x - info[j].x;
            double dy = info[i].y - info[j].y;
            double d = sqrt(dx*dx + dy*dy);
            double calc_d = max(0.0, d - info[i].r - info[j].r);
            graphs[i].push_back(Edge({j, calc_d}));
            graphs[j].push_back(Edge({i, calc_d}));
        }
    }

    vector<double> d = dijkstra(N, graphs);
    cout << d[N+1] << endl;
	
    return 0;
}
