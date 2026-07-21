#include <iostream>
#include <algorithm>

typedef long long ll;

int main()
{
  ll N, K;
  ll a[200000];
  ll sum = 0;
  std::cin >> N;

  for (ll i = 0; i < N; i++) {
    std::cin >> a[i];
    sum += a[i];
  }

  ll left = a[0];
  ll min_num = std::abs(2 * left - sum);
  for (ll i = 1; i < N - 1; i++) {
    min_num = std::min(std::abs(2 * left - sum), min_num);
    left += a[i];
  }

  std::cout << min_num << std::endl;

  return 0;
}
