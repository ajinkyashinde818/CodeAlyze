#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, r;
  cin >> n >> r;
  if (n < 10) {
    cout << 100 * (10 - n) + r;
  } else {
    cout << r;
  }

  return 0;
}
