#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main() {
  int N, R;
  cin >> N >> R;
  int ans;
  if (N < 10) {
    ans = R + 100 * (10 - N);
  } else {
    ans = R;
  }

  cout << ans << endl;
  return 0;
}
