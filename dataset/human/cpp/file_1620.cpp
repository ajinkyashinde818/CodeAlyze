#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <array>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>
#include <functional>

using namespace std;
using lli = long long int;
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n, size_t o = 0) 
{ v = vector<T>(n+o); for (lli i=o; i<n+o; ++i) cin >> v[i]; }
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

lli n;
int main() {
  cin >> n;
  lli k=1; bool ok = false;
  for (; k<10000; ++k) {
    if (n == k * (k+1) / 2) { ok = true; break; }
  }
  if (!ok) { cout << "No" << endl; return 0; }
  vector<vector<lli>> s(k+1);
  lli x=1;
  for (lli j=0; j<k+1; ++j) {
    lli ss = s[j].size();
    for (lli i=0; i<k-ss; ++i) {
      s[j].push_back(x);
      s[j+i+1].push_back(x);
      ++x;
    }
  }
  cout << "Yes" << '\n' << k+1 << '\n';
  for (auto& v : s) {
    cout << k;
    for (lli x : v) {
      cout << ' ' << x;
    }
    cout << '\n';
  }
  return 0;
}
