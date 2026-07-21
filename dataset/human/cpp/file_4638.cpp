#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
typedef long long LL;

int main() {
  int N, R; std::cin >> N >> R;
  if (N >= 10) std::cout << R << std::endl;
  else         std::cout << R + 100 * (10 - N) << std::endl;
}
