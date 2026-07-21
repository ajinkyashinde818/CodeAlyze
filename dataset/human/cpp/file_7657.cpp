#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N);
  ll sum = 0;
  for (ll i = 0; i < N; i++) {
    cin >> A.at(i);
    sum += A.at(i);
  }
  ll acc = 0;
  ll ans = LLONG_MAX;
  for (ll i = 0; i < N-1; i++) {
    acc += A.at(i);
    ll y = sum - acc;
    ans = min(ans, abs(acc - y));
  }
  cout << ans << endl;

  return 0;
}
