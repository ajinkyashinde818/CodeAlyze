#include <iostream>
#include <cmath>
#include <vector>

using lli=long long int;
int main(){
  int N;
  std::cin >> N;

  std::vector<lli> A_arr(N);
  for(int i = 0; i < N; i++) std::cin >> A_arr[i];

  int sign = 1;
  lli min_A = std::pow(10,10);
  lli sum_A = 0;
  for(int i = 0; i < N; i++){
    if(A_arr[i] < 0) sign *= -1;
    min_A = std::min(min_A, std::abs(A_arr[i]));
    sum_A += std::abs(A_arr[i]);
  }

  if(sign == 1) std::cout << sum_A << std::endl;
  else std::cout << sum_A-2*min_A << std::endl;

  return 0;
}
