#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>

typedef long long ll;

int main (void) {
  int N;
  std::cin >> N;

  std::vector<ll> A;
  A.resize(N);

  int count_minus = 0;
  ll sum = 0;
  for(int i=0; i<N; i++){
    std::cin >> A[i];
    sum += std::abs(A[i]);
    if ( A[i] < 0  ) count_minus++;
  }

  ll min_abs = 999999999999;
  for(int i=0; i<N; i++){
    min_abs = std::min(min_abs, std::abs(A[i]));
  }

  if (count_minus % 2 == 0) std::cout << sum << std::endl;
  else std::cout << sum - (2*min_abs) << std::endl;

  return 0;
}
