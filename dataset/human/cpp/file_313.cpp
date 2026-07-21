#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
typedef long long LL;

int main() {
  int R, G, B, N; std::cin >> R >> G >> B >> N;
  int cnt = 0;
  for (int r = 0; r*R <= N; ++r) {
    for (int g = 0; r*R + g*G <= N; ++g) {
      int b = N - r*R - g*G;
      if (b%B == 0) ++cnt;
    }
  }
  std::cout << cnt << std::endl;
}
