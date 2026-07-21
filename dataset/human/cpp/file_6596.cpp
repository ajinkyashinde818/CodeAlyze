#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <memory>
#include <complex>
#include <numeric>
#include <cstdio>
#include <iomanip>
#include <random>

#define REP(i,m,n) for(int i=int(m);i<int(n);i++)
#define RREP(i,m,n) for(int i=int(n)-1;i>=int(m);--i)
#define EACH(i,c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
//#define int long long

#ifdef LOCAL
#define DEBUG(s) cout << (s) << endl
#define dump(x)  cerr << #x << " = " << (x) << endl
#define BR cout << endl;
#else
#define DEBUG(s) do{}while(0)
#define dump(x) do{}while(0)
#define BR 
#endif
using namespace std;

using UI = unsigned int;
using UL = unsigned long;
using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VS = vector<string>;
using PII = pair<int,int>;
using VP = vector<PII>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

constexpr int MOD = 1'000'000'007;

// auto mod int
struct mint {
    LL x;
    mint(LL x=0):x((x%MOD+MOD)%MOD){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += MOD-a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(const LL &t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime MOD
    mint inv() const {
        return pow(MOD-2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
    LL operator()() const {
        return x;
    }
};
using VM = vector<mint>;
using VVM = vector<VM>;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    n *= 2;

    bool b = true;
    for (char c: s) if (c == 'B') {
        b = false;
        break;
    }
    if (b || s[0] == 'W' || s[n-1] == 'W') {
        cout << 0 << endl;
        return;
    }

    string d = "L";
    REP(i,1,n) {
        if (s[i] == s[i-1]) d += (d.back() == 'L' ? 'R' : 'L');
        else d += (d.back() == 'L' ? 'L' : 'R');
    }
    int balance = 0;
    for (char c: d) balance += (c == 'L' ? 1 : -1);
    if (balance) {
        cout << 0 << endl;
        return;
    }

    mint ans = 1;
    int lcnt = 1;
    REP(i,1,n) {
        if (d[i] == 'R') ans *= lcnt--;
        else lcnt++;
    }
    REP(i,1,n/2+1) ans *= i;
    cout << ans() << endl;
    dump(d);
}

signed main() {
    solve();
    
    return 0;
}
