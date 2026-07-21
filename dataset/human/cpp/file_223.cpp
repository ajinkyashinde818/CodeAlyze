#include <bits/stdc++.h>
using namespace std;

int main() {
  int R, G, B, N, ans = 0;
  cin >> R >> G >> B >> N;
  for (int i = 0; R * i <= N; i++) {
    for (int j = 0; R * i + G * j <= N; j++) {
      if ((N - R * i - G * j) % B == 0) ans++;
    }
  }
  cout << ans;
  return 0;
}
