// R x + G y + B z = N

#include <iostream>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int ans = 0;
  for (int x = 0; x <= N; x++) {
    for (int y = 0; y <= N; y++) {
      int tmp = N - R * x - G * y;
      if (tmp >= 0 && tmp % B == 0)
        ++ans;
    }
  }
  cout << ans << endl;
  
  return 0;
}
