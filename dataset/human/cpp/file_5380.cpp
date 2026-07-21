#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <sstream>
#include <fstream>

typedef long long int64;

int main(void) {
  int n, r;
  std::cin >> n >> r;

  if (n >= 10) {
    std::cout << r << std::endl;
  }
  else {
    std::cout << r + 100 * (10 - n) << std::endl;
  }
  return 0;
}
