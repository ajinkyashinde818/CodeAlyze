/**
 *    author:  otera    
**/
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<deque>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

#define int long long
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60 ;
const ll mod=1e9+7 ;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<int, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<int> test(int x) {
    vector<int> res(x);
    rep(i, x) {
        if(i == 0) {
            res[i] = 1;
            continue;
        }
        set<int> se;
        se.insert(0);
        int now = 0;
        for(int k = i - 1; k >= 0; --k) {
            now ^= res[k];
            se.insert(now);
        }
        for(int y = 0; y <= x + 1; ++y) {
            if(se.find(y) == se.end()) {
                res[i] = y;
                break;
            }
        }
    }
    return res;
}

struct node{
    int d, lch, rch;
    node() {lch = rch = -1;}
    node(int d): d(d) {lch = rch = -1;}
};
vector<node> nodes;

void solve() {
    auto res = test(100);
    int a = 0;
    for(int v: res) {
        //cerr << a << " " << v << endl;
        ++a;
    }
	int n; ll l; cin >> n >> l;
    vector<string> s(n);
    rep(i, n) {
        cin >> s[i];
    }
    nodes.push_back(node(0));
    rep(i, n) {
        int now = 0;
        rep(j, (int)s[i].size()) {
            if(s[i][j] == '0') {
                if(nodes[now].lch != -1) {
                    now = nodes[now].lch;
                } else {
                    nodes[now].lch = nodes.size();
                    nodes.push_back(node(nodes[now].d + 1));
                    now = nodes[now].lch;
                }
            } else {
                if(nodes[now].rch != -1) {
                    now = nodes[now].rch;
                } else {
                    nodes[now].rch = nodes.size();
                    nodes.push_back(node(nodes[now].d + 1));
                    now = nodes[now].rch;
                }
            }
        }
    }
    int tot = 0;
    for(auto e: nodes) {
        if(e.lch == -1 && e.rch == -1) {
            continue;
        } else if(e.lch == -1 || e.rch == -1) {
            tot ^= (l - e.d) & (e.d - l);
        }
    }
    if(tot == 0) {
        cout << "Bob" << endl;
    } else {
        cout << "Alice" << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}
