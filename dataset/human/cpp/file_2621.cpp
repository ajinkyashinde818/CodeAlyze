#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N;
vector<ll> A;

void solve() {
  ll res = 0, cnt = 0;
  bool zero = false;

  for (int i = 0; i < N; i++) {
    if (A[i] < 0) {
      cnt++;
    }
    if (A[i] == 0) {
      zero = true;
    }
  }
  for (int i = 0; i < N; i++) {
    res += abs(A[i]);
  }

  if (!(cnt % 2 == 0 || zero)) {
    {
      ll Amin = 10000000000;
      for (int i = 0; i < N; i++) {
        Amin = min(Amin, abs(A[i]));
      }
      res -= 2 * Amin;
    }
  }

  cout << res << "\n";
  return;
}
int main() {
  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  solve();
  return 0;
}
