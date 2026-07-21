#include <bits/stdc++.h>

using namespace std;

int main() {
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int ans = 0;
  for (int r = 0; r <= 3000; ++r)
    for (int g = 0; g <= 3000; ++g)
      if (R * r + G * g <= N && (N - R * r - G * g) % B == 0) ans++;
  cout << ans << endl;
  return 0;
}
