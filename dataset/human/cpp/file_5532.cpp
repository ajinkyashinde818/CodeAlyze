#include <iostream>
#include <assert.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;
constexpr int64_t MOD = 1e9 + 7;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int32_t N, R;
  int32_t res;
  //string N;
  cin >> N >> R;
  if (N > 10) {
    res = R;
  } else {
    //R = res - 100 * (10 - N);
    res = R + 100 * (10 - N);
  }
  cout << res << endl;
  return 0;
}
