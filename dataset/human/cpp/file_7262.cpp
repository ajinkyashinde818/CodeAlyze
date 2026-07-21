#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N, y = 0;
  cin >> N;
  vector<int> xs(N);
  for (auto& x : xs) {
    cin >> x;
    y += x;
  }
  int64_t x = 0, abs_min = numeric_limits<int64_t>::max();
  for (int i = 0; i <= N - 2; ++i) {
    x += xs[i];
    y -= xs[i];
    abs_min = min(abs_min, abs(x - y));
  }
  cout << abs_min << endl;
}
