#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int ans = 0;
  for (int r = 0; r*R <= N; r++) {
    for (int g = 0; g*G <= N - r*R; g++) {
      int x = N - r*R - g*G;
      if (x%B == 0) {
        int b = x/B;
        if (r*R + g*G + b*B == N) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
