#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  vector<ll> vec(n);
  ll cnt = 0;
  ll vmin = 1e10;
  ll vsum = 0;
  for (auto &v : vec) {
    cin >> v;
    if (v < 0)
      ++cnt;
    vmin = min(vmin, abs(v));
    vsum += abs(v);
  }
  if (cnt % 2 == 0)
    cout << vsum << endl;
  else
    cout << vsum - 2 * vmin << endl;
}
