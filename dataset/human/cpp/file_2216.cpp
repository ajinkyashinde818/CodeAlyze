#include <iostream>
#include <vector>
int main(){
  long n;
  std::cin >> n;
  std::vector<long> a(n);
  for(long i = 0; i < n; ++i){
    std::cin >> a[i];
  }
  long absMin = 1000000000;
  long minusCount = 0;
  long sum = 0;
  for(long i = 0; i < n; ++i){
    long minus = (a[i] < 0);
    long abs = (minus ? -a[i] : a[i]);
    if(abs < absMin)
      absMin = abs;
    if(minus)
      ++minusCount;
    sum += abs;
  }
  if(minusCount%2 == 1){
    sum -= 2*absMin;
  }

  std::cout << sum << std::endl;
  return 0;
}
