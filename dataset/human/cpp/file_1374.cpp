// Last Change: 05/11/2019 21:21:15.
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

namespace NS {
void LoopUntilZeroInpput() {
  int hogegegege = 0;
  while (cin >> hogegegege && hogegegege != 0) {
  }
}
} // namespace NS

int main() {
  int R, G, B, N, ans;
  cin >> R >> G >> B >> N;

  ans = 0;

  for (int i = 0; i * R <= N; ++i) {
    for (int j = 0; j * G <= N; ++j) {
      ll tmp = N - i * R - j * G;
      if (tmp % B == 0 and tmp >= 0) {
        ++ans;
      }
    }
  }

  cout << ans << endl;

  //NS::LoopUntilZeroInpput();
}
