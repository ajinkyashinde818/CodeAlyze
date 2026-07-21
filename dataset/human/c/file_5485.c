#include <stdio.h>
#define max 200000

int main(void) {
  long long i, j, k, n, sum[max], now = 0;
  bool prime[max];
  for(i = 0; i < max; ++i) prime[i] = true;
  prime[0] = prime[1] = false;
  for(i = 2; i < 500; ++i) if(prime[i]) for(j = 2; i * j < max; ++j) prime[i * j] = false;
  sum[0] = 0;
  for(i = 1; i < max; ++i) if(prime[i]) {
    now++;
    sum[now] = sum[now - 1] + i;
  }
  while( 1 ) {
    scanf("%lld", &n);
    if(!n) break;
    printf("%lld\n", sum[n]);
  }
  return 0;
}
