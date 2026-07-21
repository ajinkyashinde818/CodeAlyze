#include <cstdio>
#include <vector>

long long magic = 1000 * 1000 * 1000 + 7;

int main()
{
  long long n;
  scanf("%lld\n", &n);
  std::vector<long long> table(256, 1);
  for (long long i = 0; i < n; i++) {
    char ch = getchar();
    table.at(ch)++;
  }
  long long res = 1;
  for (const auto& x : table) {
    res = (res * x) % magic;
  }
  printf("%lld\n", res-1);
  return 0;
}
