#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll sign(ll x) {
  return (x>0)-(x<0);
}

int main() {
  ll N; cin >> N;
  vector<ll> A(N);
  ll mc = 0;
  for (ll j=0; j < N; ++j){
    cin >> A[j];
    if (A[j] < 0) mc += 1;
  }
  ll ans = 0;
  if (mc % 2 == 0) {
    for (ll j=0; j < N; ++j) {
      ans += abs(A[j]);
    }
  } else {
    ll midx = 0, tmp = abs(A[0]);
    for (ll j=1; j < N; ++j) {
      if (tmp > abs(A[j])) {
        midx = j;
        tmp = abs(A[j]);
      }
    }
    for (ll j=0; j < N; ++j) {
      if (j != midx) ans += abs(A[j]);
    }
    ans -= abs(A[midx]);
  }
  cout << ans << endl;
  return 0;
}
