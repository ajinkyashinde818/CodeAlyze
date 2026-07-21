#include <algorithm>
#include <climits>
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
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;
#define REP(var, a, b) for (int var = (a); var < (b); var++)
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()
#define rALL(c) (c).rbegin(), (c).rend()
ll MOD = 1000000007;

int main() {
  //
  ll n;
  cin >> n;
  string s;
  cin >> s;
  vi r(2 * n);
  ll open = 0, close = 0;
  ll ans = 1;
  rep(i, 2 * n) {
    if (s[i] == 'B')
      r[i] = 1;
    else
      r[i] = 0;

    if ((i & 1) == 0) {
      r[i] = !r[i];
    }

    if (r[i] == 0) {
      open++;
    } else {
      // cout << open << ":" << close << endl;
      ans = ans * (open - close) % MOD;
      close++;
    }
  }
  if (open != n) {
    cout << 0 << endl;
    return 0;
  }
  REP(i, 1, n + 1) { ans = ans * i % MOD; }

  cout << ans << endl;
  return 0;
}
