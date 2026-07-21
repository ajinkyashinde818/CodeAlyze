#include <bits/stdc++.h>
using namespace std;

int main() {
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int ans = 0;
  for (int r = 0; r <= N; ++r) {
    for (int g = 0; g <= N; ++g) {
      int b = (N - R * r - G * g) / B;
      if (r >= 0 && g >= 0 && b >= 0 && R * r + G * g + B * b == N)
        ++ans;
    }
  }
  cout << ans << endl;
}
