#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

typedef long long ll;

const ll MAX_N = 200000;

int main(int argc, char const *argv[]) {
  ll n, sum = 0;
  cin >> n;
  vector<ll> a(n);
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  ll y = sum-a[0], x = a[0];
  ll ans = abs(x-y);
  for (size_t i = 1; i < n-1; i++) {
    y -= a[i];
    x += a[i];
    ans = min(ans,abs(x-y));
  }
  cout << ans << endl;

  return 0;
}
