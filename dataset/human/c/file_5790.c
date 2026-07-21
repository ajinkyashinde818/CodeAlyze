#include <stdio.h>

int main() {
  int i;
  long long int profit = -2147483648;
  long long int num, min;

  scanf("%lld", &num);
  scanf("%lld", &min);
  for (i = 1; i < num; i++) {
    long long int n;
    scanf("%lld", &n);
    if (profit < (n - min))
      profit = n - min;
    if (min > n)
      min = n;
  }

  printf("%lld\n", profit);

  return 0;
}
