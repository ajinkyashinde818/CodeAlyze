#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;
  std::vector<int> A(N);
  std::vector<int> B(N);
  for(auto &a:A) std::cin >> a;
  int mcnt = 0;
  int zcnt = 0;
  long long sum = 0;
  int abs_min = 1000000000;
  for(int i=0;i<N;i++){
    if(A[i] < 0) mcnt++;
    if(A[i] == 0) zcnt++;
    B[i] = std::abs(A[i]);
    sum += B[i];
    if(B[i] < abs_min) abs_min = B[i];
  }
  if((mcnt&1) && zcnt==0) sum -= abs_min*2;  
  std::cout << sum << std::endl;
  return 0;
}
