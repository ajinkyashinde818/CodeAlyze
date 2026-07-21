#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N; cin >> N;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector<vector<ll>> B(N, vector<ll>(2, 0));

  B[0][0] = A[0], B[0][1] = -A[0];
  for (int i = 0; i < N - 1; i++) {
    B[i + 1][0] = max(B[i][0] + A[i + 1], B[i][1] - A[i + 1]);
    B[i + 1][1] = max(B[i][0] - A[i + 1], B[i][1] + A[i + 1]);
  }
  ll ans = max(B[N - 2][0] + A[N - 1], B[N - 2][1] - A[N - 1]);
  cout << ans << '\n';
  return 0;
}
