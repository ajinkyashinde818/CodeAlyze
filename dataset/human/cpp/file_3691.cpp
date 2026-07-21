#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int64> xs(n);
  int64 sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
    sum += xs[i];
  }

  sort(xs.begin(), xs.end());
  for (int i = 0; i + 1 < n; i += 2) {
    int64 y = xs[i] + xs[i + 1];
    if (y < 0) sum += -2 * y; 
  }
  cout << sum << endl;
}
