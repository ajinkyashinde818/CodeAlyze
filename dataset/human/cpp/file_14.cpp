#include <bits/stdc++.h>
using namespace std;

int main() {
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int ans = 0;
  for (int r = 0; r * R <= N; r++) {
    for (int g = 0; r * R + g * G <= N; g++) {
      int tmp = N - r * R - g * G;
      if (tmp % B == 0) ans++;
    }
  }
  cout << ans << "\n";
}
