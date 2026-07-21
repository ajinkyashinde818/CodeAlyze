#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <iomanip>

using namespace std;

#define int long long

#define fst first
#define scd second
#define PB push_back
#define MP make_pair
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define omajinai ios::sync_with_stdio(false);cin.tie(0)
#define rep(i,x) for(int i=0;i<(int)(x);++i)
#define rep1(i,x) for(int i=1;i<=(int)(x);++i)

using ll=long long;
using ld=long double;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int, int>;
using vpii=vector<pii>;

template<class T,class U>ostream&operator<<(ostream&os,const pair<T,U>p){os<<"("<<p.fst<<", "<<p.scd<<")";return os;}
template<class T>ostream&operator<<(ostream&os,const vector<T>v){rep(i,v.size()){if(i)os<<", ";os<<v[i];}return os;}
template<typename T>T&max(T&a,T&b){if(a>=b)return a;return b;}
template<typename T>T&min(T&a,T&b){if(a < b)return a;return b;}
template<typename T>bool chmax(T&a,T b){if(a < b){a=b;return true;}return false;}
template<typename T>bool chmin(T&a,T b){if(a > b){a=b;return true;}return false;}

constexpr int inf = 1e9;
constexpr ll linf = 3e18;
constexpr double eps = 1e-9;

int in() { int x; cin >> x; return x; }

struct V {
    int x, y, r;
    V(int x,int y,int r):x(x),y(y),r(r){
        //cout<<"x="<<x<<",y="<<y<<",r="<<r<<endl;
    }
};

typedef pair<double, int> P;

vector<V> G;
double d[1010];

signed main()
{
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    G.PB(V(x1, y1, 0));
    G.PB(V(x2, y2, 0));

    int N; cin >> N;

    rep(i, N) {
        int x, y, r; cin >> x >> y >> r;
        G.PB(V(x, y, r));
    }

    priority_queue<P,vector<P>,greater<P>> q;
    fill_n(d, 1010, linf);
    d[0] = 0;
    q.push(P(0.0, 0));

    while (q.size()) {
        P p = q.top(); q.pop();

        int num = p.scd, c = p.fst;

        if (d[num] < c) continue;

        V v = G[num];

        for (int i = 0; i < G.size(); ++i) {
            if (i == num) continue;

            V u = G[i];

            double dist = max(sqrt(pow(v.x - u.x, 2) + pow(v.y - u.y, 2)) - (v.r + u.r), 0.0);

            if (d[i] > d[num] + dist) {
                d[i] = d[num] + dist;
                q.push(P(d[i], i));
            }
        }
    }

    cout << fixed << setprecision(10) << d[1] << endl;
}
