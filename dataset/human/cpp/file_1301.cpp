#include <bits/stdc++.h>
using namespace std;

int main() {
  int R, G, B, N, ans;
  cin >> R >> G >> B >> N;
  for (int r = 0; N - R * r >= 0; r++) {
    for (int g = 0; N - R * r - G * g >= 0; g++) {
      if ((N - R * r - G * g) % B == 0) ans++;
    }
  }
  cout << ans << endl;
}
