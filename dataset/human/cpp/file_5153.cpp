#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <complex>

int main(){

  long long int N, R;
  scanf("%lld%lld", &N, &R);

  std::cerr << "Answer: " << std::endl;
  if(N >= 10){
    std::cout << R << std::endl;
  }
  else{
    std::cout << R + 100*(10-N) << std::endl;
  }

  return 0;
  
  
}
