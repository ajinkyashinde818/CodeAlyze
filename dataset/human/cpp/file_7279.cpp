#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ll N, s{};
  cin >> N;
  vector<ll> a(N);
  for (int i = 0; i != N; ++i) {
    cin >> a[i];
    s += a[i];
    a[i] <<= 1;
  }
  a.pop_back();
  partial_sum(begin(a), end(a), begin(a));
  auto m = *min_element(begin(a), end(a),
                        [&](ll x, ll y) { return abs(s - x) < abs(s - y); });
  cout << abs(s - m) << endl;
}
