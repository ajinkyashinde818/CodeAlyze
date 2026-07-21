#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> A(N), B(N), C(N + 10, 0), D(N + 10, 0);
  for (auto&& e : A) {
    cin >> e;
    C[e]++;
  }
  for (auto&& e : B) {
    cin >> e;
    D[e]++;
  }
  for (int i = 0; i < N + 10; i++) {
    if (C[i] + D[i] > N) {
      cout << "No" << '\n';
      return 0;
    }
  }
  for (int i = 0; i < N; i++) {
    C[i + 1] += C[i], D[i + 1] += D[i];
  }
  int d = 0;
  for (int i = 0; i < N; i++) {
    d = max(d, D[i + 1] - C[i]);
  }
  cout << "Yes" << '\n';
  for (int i = 0; i < N; i++) {
    cout << B[(i + d) % N] << (i == N - 1 ? '\n' : ' ');
  }
  return 0;
}
