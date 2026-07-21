#include <bits/stdc++.h>

int main() {
  int R, G, B, N;
  std::cin >> R >> G >> B >> N;

  int ans = 0;
  for(int r = 0; r <= N / R; ++r) {
    for(int g = 0; g <= (N - R * r) / G; ++g) {
      if((N - R * r - G * g) % B == 0) ++ans;
    }
  }

  std::cout << ans << std::endl;
}
