#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int N;
  cin >> N;
  ll a[N];
  ll r[N] = {0};
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  r[0] = a[0];
  for (int i = 1; i < N; i++) {
    r[i] = r[i - 1] + a[i];
  }
  ll ans = 9999999999999;
  for (int i = 0; i < N - 1; i++) {
    ans = min(ans,abs(r[N - 1] - r[i] - r[i]));
  }
  cout << ans << endl;
  return 0;
}
