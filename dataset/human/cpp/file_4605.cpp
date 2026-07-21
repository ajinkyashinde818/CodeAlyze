#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <numeric>
#include <string>
#include <cassert>
#include <bitset>

using namespace std;
typedef long long ll;

int main() {
  int N, R;
  cin >> N >> R;
  if (N > 10) {
    cout << R << endl;
  } else {
    // R = X - 100 * (10 - N)
    cout << R + 100 * (10 - N) << endl;
  }
  return 0;
}
