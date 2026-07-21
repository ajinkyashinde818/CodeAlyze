#include <bits/stdc++.h>

using namespace std;

int main()
{
  int R, G, B, N;
  cin >> R;
  cin >> G;
  cin >> B;
  cin >> N;

  int ans = 0;
  int maxR = N / R;
  for (int r = 0; r <= maxR; r++) {
    int maxG = (N - R * r) / G;
    for (int g = 0; g <= maxG; g++) {
      if ((N - R * r - G * g) % B == 0) {
        ans += 1;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
