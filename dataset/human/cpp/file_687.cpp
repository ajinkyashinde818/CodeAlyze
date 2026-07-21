#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll R, G, B, N;
  cin >> R >> G >> B >> N;
  int b;
  ll ans = 0;
  for (int r = 0; r <= N; r++) {
    for (int g = 0; g <= N; g++) {
      b = N - R * r - G * g;
      if (b % B != 0 || b < 0) continue;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
