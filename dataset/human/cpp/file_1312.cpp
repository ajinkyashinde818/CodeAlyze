#include <algorithm>
#include <iostream>
#include <iomanip>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  int R, G, B, N;
  cin >> R >> G >> B >> N;

  int ans = 0;

  for (int r = 0; r <= 3000; ++r) {
    int rcnt = r * R;
    if (rcnt > N) break;

    for (int g = 0; g <= 3000; ++g) {
      int cnt = g * G + rcnt;
      if (cnt > N) break;

      int remain = N - cnt;
      if (remain % B != 0) continue;

      ++ans;
    }
  }

  cout << ans << endl;

  return 0;
}
