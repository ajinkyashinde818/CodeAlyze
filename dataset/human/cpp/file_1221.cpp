#include <bits/stdc++.h>

using namespace std;

int main() {
  int R, G, B, N;
  cin >> R >> G >> B >> N;

  int ans = 0;
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= N; ++j) {
      int r = R * i;
      int g = G * j;
      if (r + g > N) break;
      int remain = N - (r + g);
      if (remain % B == 0) {
	ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
