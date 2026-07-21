#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int R, G, B, N;
  cin >> R >> G >> B >> N;

  int r_max = N / R;
  int g_max = N / G;

  int ans = 0;
  for (int i = 0; i <= r_max; i++) {
    for (int j = 0; j <= g_max; j++) {
      int rest = N - i * R - j * G;
      if (rest >= 0 && rest % B == 0) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}
