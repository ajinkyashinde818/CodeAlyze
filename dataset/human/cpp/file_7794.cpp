#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define REP(var, a, b) for (int var = (a); var < (b); var++)
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()
#define rALL(c) (c).rbegin(), (c).rend()

int main() {
  //
  int n;
  cin >> n;
  ll sum = 0;
  vl a(n), s(n);
  rep(i, n) {
    cin >> a[i];
    if (i > 0) {
      s[i] = s[i - 1] + a[i];
    } else {
      s[i] = a[i];
    }
    sum += a[i];
  }
  ll m = INT_MAX;
  rep(i, n - 1) { m = min(m, abs(s[i] - (sum - s[i]))); }
  cout << m << endl;
  return 0;
}
