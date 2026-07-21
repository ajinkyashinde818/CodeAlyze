#include <iostream>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int n, r;
  cin >> n >> r;

  int ans = n < 10 ? r + (100 * (10 - n)) : r;
  cout << ans << endl;
  return 0;
}
