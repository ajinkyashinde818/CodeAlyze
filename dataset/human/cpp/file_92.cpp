#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll R, G, B, N;

void solve() {
  ll res = 0;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      if ((N - i * R - j * G >= 0) && (N - i * R - j * G) % B == 0) {
        res++;
      }
    }
  }
  cout << res << "\n";
}

int main() {
  cin >> R >> G >> B >> N;
  solve();
  return 0;
}
