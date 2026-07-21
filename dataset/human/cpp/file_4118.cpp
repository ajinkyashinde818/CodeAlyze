#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, int> pdi;

int x[1005];
int y[1005];
int r[1005];
double dp[1005];
int n;

double getDist(int i, int j) {
  double xx = x[i] - x[j];
  double yy = y[i] - y[j];
  double ret = sqrt(xx*xx + yy*yy);
  ret -= r[i];
  ret -= r[j];
  ret = max(0., ret);
  return ret;
}

void relax() {
  priority_queue<pdi> q;
  q.push({0, 0});
  while(!q.empty()) {
    pdi curr = q.top();
    q.pop();
    if(-curr.first != dp[curr.second]) continue;
    for(int i = 0; i < n; i++) {
      double nw = dp[curr.second] + getDist(curr.second, i);
      if(nw < dp[i]) {
        dp[i] = nw;
        q.push({-dp[i], i});
      }
    }
  }
}

void solve() {
  cin >> x[0] >> y[0] >> x[1] >> y[1] >> n;
  n += 2;
  for(int i = 2; i < n; i++) {
    cin >> x[i] >> y[i] >> r[i];
  }
  for(int i = 1; i < n; i++) dp[i] = 1e18;
  relax();
  cout << fixed << setprecision(10) << dp[1] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
}
