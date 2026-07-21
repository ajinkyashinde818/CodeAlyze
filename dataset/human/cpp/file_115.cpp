#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int R, G, B, N;
  cin >> R >> G >> B >> N;

  int ans = 0;
  for (int r = 0; r <= N; r++) {
    for (int g = 0; g <= N; g++) {
      int t = N - r * R - g * G;
      if (t >= 0 && t % B == 0) {
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
