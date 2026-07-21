#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<ll> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  for (int i = 1; i < N; i++) {
    a[i] += a[i - 1];
  }
  ll ans = abs(a[0] - (a[N - 1] - a[0]));
  for (int i = 0; i < N - 1; i++) {
    ans = min(ans, abs(a[i] - (a[N - 1] - a[i])));
  }
  cout << ans << endl;
  return 0;
}
