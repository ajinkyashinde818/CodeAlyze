#include <bits/stdc++.h>
using namespace std;

int main() {
  int R,G,B,N;
  std::cin >> R >> G >> B >> N;

  if (R+G+B == 3) {
    std::cout << (N+2)*(N+1)/2 << '\n';
    return 0;
  }

  int ans = 0;
  for (size_t i = 0; i < N+1; i++) {
    for (size_t j = 0; j < N+1; j++) {
      for (size_t k = 0; k < N+1; k++) {
        if (R*i+B*j+G*k == N) {
          ans++;
        } else if (R*i+B*j+G*k > N) {
          break;
        }
      }
    }
  }

  std::cout << ans << '\n';
 }
