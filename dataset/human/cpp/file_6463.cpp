#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <list>

using namespace std;

const long long MOD = 1000000007;

void solve(long long N, std::string S){
  long long depth = 1;
  long long ans = 1;
  if (S[0] == 'W') {
    std::cout << 0 << std::endl;
    return;
  }
  long long dire = 1;
  for (int i = 1; i < N*2; i++) {
    if (S[i-1] == S[i]) {
      dire *= -1;
    } else {
      depth += dire;
    }
    if (dire < 0) {
      ans *= depth;
      ans %= MOD;
    }
    if (depth < 1) {
      std::cout << 0 << std::endl;
      return;
    }
  }
  if (depth != 1) {
    std::cout << 0 << std::endl;
    return;
  }
  for (int i = 0; i < N; i++) {
      ans *= i+1;
      ans %= MOD;
  }
  std::cout << ans << std::endl;
}

int main(){
  long long N;
  scanf("%lld",&N);
  std::string S;
  std::cin >> S;
  solve(N, S);
  return 0;
}
