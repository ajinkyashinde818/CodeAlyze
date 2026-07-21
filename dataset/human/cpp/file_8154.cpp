#include <iostream>
#include <vector>
#include <climits>
#include <numeric>

using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  vector<ll> vec(n);
  for (auto &v : vec)
    cin >> v;

  ll ans = INT_MAX;
  ll vsum = accumulate(vec.begin(), vec.end(), 0LL);
  partial_sum(vec.begin(), vec.end(), vec.begin());
  for (ll i = 0; i < n - 1; ++i)
    ans = min(ans, abs(vec[i] - (vsum - vec[i])));
  cout << ans << endl;
}
