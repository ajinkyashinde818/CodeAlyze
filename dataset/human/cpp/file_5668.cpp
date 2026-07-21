#include <stdio.h>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
#include <array>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//typedef long long int;
const int mod = 1000000009;
ll P = 301;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  ll l;
  cin >> n >> l;
  vs s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    for (int j = 0; j < s[i].size(); ++j) s[i][j] -= '0';
  }
  sort(s.begin(), s.end());
  set<pii> bad, good;
  for (const string& v : s) {
    ll sum = 0;
    for (int i = 0; i < v.size(); ++i) {
      good.insert(pii((sum * P + 1 - (int)v[i]) % mod, i + 1));
      sum = (sum * P + v[i]) % mod;
      bad.insert(pii(sum, i + 1));
//      cerr << "bad: " << sum << ' ' << i + 1 << endl;
    }
  }
  vi c(100001);
  for (pii p : good) {
//    cerr << p.first << ' ' << p.second << endl;
    if (!bad.count(p)) {
      c[p.second] ^= 1;
    }
  }
  ll xr = 0;
  for (int i = 0; i < c.size(); ++i) if (c[i]) {
    ll d = l - i + 1;
    for (int b = 0; b < 64; ++b) if (d & (1LL << b)) {
      xr ^= 1LL << b;
      break;
    }
//    cerr << i << ' ' << d << ' ' << xr << endl;
  }
  if (xr) cout << "Alice\n";
  else cout << "Bob\n";
  return 0;
}
