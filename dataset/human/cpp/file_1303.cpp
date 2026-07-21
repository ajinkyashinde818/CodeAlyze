/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int32_t, int32_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int32_t R, G, B, N;
  cin >> R >> G >> B >> N;
  int32_t count = 0;
  for (int32_t r = 0; r <= N / R; ++r) {
    for (int32_t g = 0; g <= N / G; ++g) {
      const int32_t b = (N - r * R - g * G) / B;
      if (b >= 0 && r * R + g * G + b * B == N) {
        ++count;
      }
    }
  }
  cout << count << endl;

  return 0;
}
