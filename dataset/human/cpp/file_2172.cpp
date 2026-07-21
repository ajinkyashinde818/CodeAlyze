#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<int, int>;

const int INF = 1e9;
const int MOD = 1e9 + 7;

// 4近傍、8近傍
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
  int N;
  cin >> N;
  ll a[N];
  for (int i = 0; i < N; i++) cin >> a[i];

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (a[i] < 0) {
      cnt++;
      a[i] *= -1;
    }
  }

  sort(a, a + N);
  if (cnt & 1) {
    cout << accumulate(a + 1, a + N, 0LL) - a[0] << endl;
  } else {
    cout << accumulate(a, a + N, 0LL) << endl;
  }
  return 0;
}
