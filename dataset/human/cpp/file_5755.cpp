#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<functional>
#include<map>
#include <iomanip>
#include <limits>
#include<unordered_set> 
#include<cmath>
using namespace std;
//long long p = 998244353;
long long p = 1000000007;
#define int long long
#define vel vector<long long>
#define vvel vector<vel>
#define rep(i,n) for(int i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mmax(a,b) a=max(a,b)
#define mmin(a,b) a=min(a,b)
#define mkp make_pair
#define pin pair<int,int>
#define qin pair<int,pin>
#define V vector
#define Endl endl
#define veb vector<bool>
#define fcout cout << fixed << setprecision(15)
#define rev(s) reverse(s.begin(),s.end())
#define lower(h,val) lower_bound(h.begin(),h.end(),val)-h.begin()
#define upper(h,val) upper_bound(h.begin(),h.end(),val)-h.begin()
int max_kai = 150000;
vel kai(max_kai, 1);
vel inv_kai;
int rui(int a, int n) {
    if (n == 0) { return 1; }
    int x = rui(a, n / 2);
    x *= x; x %= p;
    if (n % 2 == 1) { x *= a; x %= p; }
    return x;
}
int inv(int a) { return rui(a, p - 2); }
void make_kai() {
    for (int i = 1; i < max_kai; i++) { kai[i] = kai[i - 1] * i; kai[i] %= p; }
    inv_kai = kai;
    rep(i, max_kai) { inv_kai[i] = inv(kai[i]); }
}
int nCr(int n, int r) {
    if (n < 0 || r<0 || r>n) { return 0; }
    int a = kai[n] * inv_kai[r]; a %= p;
    a *= inv_kai[n - r]; a %= p;
    return a;
}
vel pa;
int root(int x) {
    if (pa[x] == -1) { return x; }
    int ans = root(pa[x]); pa[x] = ans;
    return ans;
}
void marge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) { pa[x] = y; }
}
int gcd(int x, int y) {
    if (x < y) { return gcd(y, x); }
    if (y == 0) { return x; }
    return gcd(y, x % y);
}
#define pd pair<int,double>
#define ved vector<double>
int l;
V<string> s;
int ord_2(int n) {
    if (n % 2 == 1) { return 1; }
    return 2 * ord_2(n / 2);
}
int solve(string &now, int st, int to) {
    if (st == to) {
        int ql = l - now.size();
        return ord_2(ql + 1);
    }
    if (s[st] == now) { return 0; }
    now.append(1, '1');
    int mid = lower_bound(s.begin()+st, s.begin()+to, now)-s.begin();
    int ans1 = solve(now, mid, to);
    now.erase(now.end() - 1);
    now.append(1, '0');
    int ans0 = solve(now, st, mid);
    now.erase(now.end() - 1);
    return (ans0 ^ ans1);
}
signed main() {
    int n; cin >> n >> l;
    s = V<string>(n);
    rep(i, n) { cin >> s[i]; }
    sor(s);
    string now = "";
    int ans = solve(now, 0, n);
    //cout << ans << endl;
    if (ans == 0) { cout << "Bob" << endl; return 0; }
    cout << "Alice" << endl;
    return 0;
}
