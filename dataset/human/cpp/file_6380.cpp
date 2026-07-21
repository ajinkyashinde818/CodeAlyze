/**
 *      purpose : 
 *      author  : kyomukyomupurin
 *      created : 
**/

// input/output
#include <iostream>
#include <fstream>
#include <sstream>
// container class
#include <array>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// math, algorithm
#include <algorithm>
#include <cmath>
#include <complex>
#include <numeric>
// etc
#include <bitset>
#include <cassert>
#include <cctype>
#include <cstring>
#include <chrono>
#include <functional>
#include <iomanip>
#include <random>
#include <utility>
// using-directive
using namespace std;
// alias template
using int64 = long long;
using uint64 = unsigned long long;
using vi = vector<int>;
using vl = vector<int64>;
using pii = pair<int, int>;
using pll = pair<int64, int64>;
// text macro replacement
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define print(x) cout << (x) << '\n'
#define debug(x) cerr << #x << ": " << (x) << '\n'
#define dbg(v) for (size_t _ = 0; _ < v.size(); ++_){cerr << #v << "[" << _ << "] : " << v[_] << '\n';}
// variadic template
template<typename T> inline void chmin(T &a, T b) {if (a > b) a = b; return;}
template<typename T> inline void chmax(T &a, T b) {if (a < b) a = b; return;}
// constant
const int INF = (1<<30) - 1;
const int64 INF64 = (1LL<<62) - 1;
const int64 MOD = 1000000007;

string convert(const string& s) {
  string ret = "";
  for (size_t i = 0; i < s.size(); ++i) {
    if (s[i] == 'W') {
      ret += 'L';
    } else {
      ret += 'R';
    }
  }
  return ret;
}

int64 fact(int n) {
  int64 res = 1;
  for (int i = 1; i <= n; ++i) {
    (res *= (int64) i) %= MOD;
  }
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  string s; cin >> s;
  int SIZE = 2 * n;

  for (int i = 0; i < SIZE; ++i) {
    if (i & 1) {
      continue;
    } else {
      if (s[i] == 'W') {
        s[i] = 'B';
      } else {
        s[i] = 'W';
      }
    }
  }

  string t = convert(s);
  int cntw = count(all(s), 'W');
  if (cntw != n) {
    cout << 0 << endl; return 0;
  }

  int cur = 0;
  int64 ans = 1;

  for (size_t i = 0; i < t.size(); ++i) {
    if (t[i] == 'L') {
      ++cur;
    } else {
      (ans *= cur) %= MOD;
      --cur;
    }
  }

  (ans *= fact(n)) %= MOD;

  cout << ans << endl;

  return 0;
}
