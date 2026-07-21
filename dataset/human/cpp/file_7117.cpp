#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll N;
  cin >> N;
  vector<ll> a(N), accum(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    if (i == 0)
      accum[0] = a[0];
    else
      accum[i] = accum[i - 1] + a[i];
  }
  ll ans = INF;
  for (int i = 0; i < N - 1; i++) {
    ll x = accum[i];
    ll y = accum[N - 1] - accum[i];
    ans = min(ans, abs(x - y));
  }
  cout << ans << endl;
  return 0;
}
