#include <iostream>
#include <vector>

using ll = long long;

void print() {std::cout << std::endl;}
template<class H> void print(H head) {std::cout << head << std::endl;}

int main()
{
  ll N, R;
  std::cin >> N >> R;

  if (N < 10) R += 100 * (10 - N);
  print(R);

  return 0;
}
