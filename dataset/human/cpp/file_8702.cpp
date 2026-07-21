#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <deque>
#include <iterator>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
  ll n, m; cin >> n >> m;
  V<string> a(n); REP(i, n) cin >> a[i];
  V<string> b(m); REP(i, m) cin >> b[i];
  bool in_a = true;
  REP(i, n-m+1) REP(j, n-m+1) {
    in_a = true;
    REP(k, m) REP(l, m) {
      if (a[i+k][j+l] != b[k][l]) {in_a = false; break;}
    }
    if (in_a) {cout << "Yes" << endl; return 0;}
  }
  cout << "No" << endl;
  return 0;
}
