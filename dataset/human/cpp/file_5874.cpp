#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  int N;
  ll C;
  cin >> N >> C;
  vector<ll> x(N), v(N), rv;
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> v[i];
  }
  rv = v;
  reverse(rv.begin(), rv.end());
  vector<ll> a = v, b = rv;
  for (int i = 0; i + 1 < N; i++) {
    a[i + 1] += a[i];
    b[i + 1] += b[i];
  }
  for (int i = 0; i < N; i++) {
    a[i] -= x[i];
    b[i] -= C - x[N - i - 1];
  }

  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ans = max(ans, a[i]);
    ans = max(ans, b[i]);
  }
  vector<int> idxa(N, 0), idxb(N, 0);
  for (int i = 1; i < N; i++) {
    idxa[i] = idxa[i - 1];
    if (a[i] > a[idxa[i]]) idxa[i] = i;
    idxb[i] = idxb[i - 1];
    if (b[i] > b[idxb[i]]) idxb[i] = i;
  }
  for (int i = 0; i + 1 < N; i++) {
    ll sum = a[i] - x[i];
    sum += b[idxb[N - i - 2]];
    ans = max(ans, sum);
  }
  for (int i = 0; i + 1 < N; i++) {
    ll sum = b[i] - (C - x[N - i - 1]);
    sum += a[idxa[N - i - 2]];
    ans = max(ans, sum);
  }
  cout << ans << endl;

  return 0;
}
