#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <array>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cstdint>
#include <unordered_set>
#include <ctime>
typedef long long int llint;

int main(void){

  int n, r;
  std::cin >> n >> r;

  if(n <= 10) std::cout << r + 100*(10-n) << std::endl;
  else        std::cout << r << std::endl;
  return 0;
}
