#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, r;
  cin >> n >> r;
  int x = r + max(0, 100 * (10 - n));
  cout << x << endl;
}
