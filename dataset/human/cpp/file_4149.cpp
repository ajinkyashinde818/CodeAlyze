#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <unistd.h>
#include <string.h>
#include <string>
#include <numeric>
#include <queue>
#include <deque>
#include <sstream>
#include <iomanip>
#include <set>
#include <stack>
#include <cassert>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vvb> vvvb;
typedef vector<vvvb> vvvvb;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<ll, ll> PL;
typedef vector<PL> vpl;
typedef vector<vector<PL>> vvpl;
const int INF = 1001001001;
const ll LINF = 1e17;
const double pi = 3.1415926535897932;
const string endstr = "\n";
#define FOR(i, a, b) for(ll i = (a); i < b; i++)
#define RFOR(i, a, b) for(ll i = (a); i > b; i--)
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rrep(i, n) for(ll i = n-1; i > -1; i--)
#define FORMAP(it, m) for(auto it = m.begin(); it != m.end(); it++)
#define ff first
#define ss second
#define pb push_back
#define epb emplace_back
#define ALL(X) (X).begin(),(X).end()

template <typename T>
T gcd(T a, T b) {
    return (a == 0) ? b : gcd(b%a, a);
}
template <typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

bool p_comp_fs(const PL p1, const PL p2){ return p1.first < p2.first;};
bool p_comp_fg(const PL p1, const PL p2){ return p1.first > p2.first;};
bool p_comp_ss(const PL p1, const PL p2){ return p1.second < p2.second;};
bool p_comp_sg(const PL p1, const PL p2){ return p1.second > p2.second;};
template <typename T>
vector<T> uniquen(vector<T> vec){
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    return vec;
}

inline ll popcnt(ll x){return __builtin_popcountll((unsigned long long)x);};
template<class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
//friend bool operator<(const stc& lhs, const stc& rhs){
//    return std::tie(lhs.l, lhs.r) < std::tie(rhs.l, rhs.r);
//}

struct cir{double x, y, r;};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    double xs, ys, xt, yt; cin >> xs >> ys >> xt >> yt;
    ll N; cin >> N;
    vector<cir> vc(N+2);
    rep(i, N){
        cin >> vc[i].x >> vc[i].y >> vc[i].r;
    }
    vc[N] = {xs, ys, 0.0};
    vc[N+1] = {xt, yt, 0.0};
    ll NN = N+2;
    
    vvd G(NN, vd(NN, 1e18));
    rep(i, NN) rep(j, NN){
        G[i][j] = sqrt(pow(vc[i].x-vc[j].x, 2.0) + pow(vc[i].y-vc[j].y, 2.0));
        G[i][j] = max(G[i][j]- vc[i].r - vc[j].r, 0.0);
    }
    
    priority_queue<pair<double, ll>, vector<pair<double, ll>>, greater<pair<double, ll>>> pq;
    pq.push({0.0, N});
    vd dist(NN, 1e18); dist[N] = 0.0;
    while (!pq.empty()) {
        ll now = pq.top().ss; double now_d = pq.top().ff; pq.pop();
        if(now_d > dist[now]) continue;
        rep(c, NN) if(c != now){
            if(chmin(dist[c], dist[now] + G[now][c])){
                pq.push({dist[c], c});
            }
        }
    }
    
    cout << fixed << setprecision(20) << dist[N+1] << endstr;
    return 0;
}
