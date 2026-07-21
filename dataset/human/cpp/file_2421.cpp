#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  bool minus = 0, zero = 0;
  ll ans = 0;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    minus ^= (A[i] < 0);
    zero |= (A[i] == 0);
    ans += abs(A[i]);
  }
  if (!zero && minus)
    ans -=
        2 * abs(*min_element(A.begin(), A.end(), [](const ll& l, const ll& r) {
          return abs(l) < abs(r);
        }));
  cout << ans << endl;
  return 0;
}
