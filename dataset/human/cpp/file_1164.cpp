#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int ans = 0;
  for (int r = 0; r <= N; ++r) {
    for (int g = 0; g <= N; ++g) {
      int b = (N - r * R - g * G) / B;
      if (b * B + r * R + g * G == N and b >= 0) ++ans;
    }
  }
  cout << ans << '\n';
}
