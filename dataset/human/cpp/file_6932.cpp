#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <array>
#include <chrono>
#include <random>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cassert>

#define sq(x) ((x) * (x))
#define err(x) cerr << "["#x"]  " << (x) << "\n";
#define errp(x) cerr << "["#x"]  {" << ((x).first) << ", " << ((x).second) << "}\n";
#define errv(x) {cerr << "["#x"]  [";for(const auto& ___ : (x)) cerr << ___ << ", "; cerr << "]\n";}
#define errvn(x, n) {cerr << "["#x"]  [";for(auto ___ = 0; ___ < (n); ++___) cerr << (x)[___] << ", "; cerr << "]\n";}
#define errf() cerr << "\n\n";

#pragma GCC optimize("Ofast, unroll-loops", "omit-frame-pointer","inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native,avx2")

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getrnd(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}

template <typename T1, typename T2> inline bool relax(T1& a, const T2& b) {
    return a > b ? a = b, true : false;
}

template <typename T1, typename T2> inline bool strain(T1& a, const T2& b) {
    return a < b ? a = b, true : false;
}

// :::::::::::::::::::::::::::::::

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    
    vector<int> l(n + 1, -1), r(n + 1, -1);
    for (int i = 0; i < n; ++i)
        r[a[i]] = i;
    for (int i = n - 1; i >= 0; --i)
        l[b[i]] = i;
    
    int mx = 0;
    for (int i = 0; i <= n; ++i)
        if (r[i] != -1 && l[i] != -1)
            strain(mx, r[i] - l[i] + 1);
    
    vector<int> res(n);
    for (int i = 0; i < n; ++i)
        res[(i + mx) % n] = b[i];
    for (int i = 0; i < n; ++i) {
        if (res[i] == a[i]) {
            cout << "No\n";
            return;
        }
    }
    
    cout << "Yes\n";
    for (int i : res)
        cout << i << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    srand(time(0));
    
    int t = 1;
//    cin >> t;
    while (t--)
        solve();
    
    return 0;
}
