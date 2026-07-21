#include <algorithm>
#include <array>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define REP(X, Y, Z) for (ll(X) = (Y); (X) < (Z); (X)++)

using namespace std;
using ll = long long;
using dll = deque<ll>;
using pll = pair<ll, ll>;
using qll = queue<ll>;
using usll = unordered_set<ll>;
using umll = unordered_map<ll, ll>;
using sll = stack<int>;
using vll = vector<ll>;
using vvll = vector<vll>;

constexpr ll kMod = 1e9 + 7;

ll gcd(ll a, ll b) {
  if (a < b) {
    return gcd(b, a);
  }
  ll c = a % b;
  while (c != 0) {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}

ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

void init() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}

int main() {
  init();

  ll N;
  cin >> N;
  vll A(N);
  vll dp(N);
  ll asum = 0;
  REP(i, 0, N) {
    ll a;
    cin >> a;
    A[i] = a;
    asum += a;
    if (i == 0) {
      dp[i] = a;
    } else {
      dp[i] = dp[i - 1] + a;
    }
  }

  if (N == 2) {
    min(abs(A[0]), A[1]);
    if (A[0] > A[1]) {
      cout << A[0] - A[1] << endl;
    } else {
      cout << A[1] - A[0] << endl;
    }
    return 0;
  }

  ll res = 0;
  if (A[0] > (asum - A[0])) {
    res = A[0] - (asum - A[0]);
  } else {
    res = (asum - A[0]) - A[0];
  }
  REP(i, 1, N) {
    res = min(res, abs(asum - 2 * dp[i-1]));
  }
  cout << res << endl;

  return 0;
}
