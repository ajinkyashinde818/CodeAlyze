#include <bits/stdc++.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <cassert>
#include <queue>
#include <random>
#include <stack>
#include <iomanip>
#include <math.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repf(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define repr(i, a, b) for (ll i = (ll)a; i > (ll)b; i--)
#define repv(x, arr) for (auto &x : arr)
#define all(v) (v).begin(), (v).end()
#define vec(name, num) vector<ll> name((num), 0);
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vii;
typedef vector<vii> vvii;
const ll mod = 1e9 + 7;
const int infi = 2147483600;
const ll infl = 1e17;

struct point{
    long double x, y;
};

long double sq(long double x){
    return x * x;
}
long double sqr(long double d){
    if (d==0)
        return 0;
    long double x = sqrtl(d);
    rep(i,20){
        x = (x + d / x) / 2.0;
    }
    return x;
}

int main()
{
    std::cout << std::fixed;
    ll n;
    point s, t;
    cin >> s.x >> s.y >> t.x >> t.y >> n;
    vector<pair<point, long double>> circle(n+2);
    circle[0] = mp(s, 0);
    circle[n + 1] = mp(t, 0);
    rep(i,n){
        long double x, y, r;
        point p;
        cin >> x >> y >> r;
        p.x = x;
        p.y = y;
        circle[i+1] = mp(p, r);
    }
    vector<vector<long double>> edges(n+2, vector<long double>(n+2));
    rep(i,n+2){
        rep(j,n+2){
            ld d = sq(circle[i].F.x - circle[j].F.x) + sq(circle[i].F.y - circle[j].F.y);
            edges[i][j] = max((long double)0,sqr(d)-circle[i].S-circle[j].S);
        }
    }
    vector<long double> dist(n + 2,(ld)infl);
    dist[0] = (long double)0;
    set<int> check;
    check.insert(0);
    while (!(check.empty())){
        int now = *check.begin();
        check.erase(now);
        rep(nex,n+2){
            if (dist[now]+edges[now][nex]<dist[nex]){
                dist[nex] = dist[now] + edges[now][nex];
                check.insert(nex);
            }
        }
    }
    cout << setprecision(10) << dist[n + 1] <<  endl;
}
