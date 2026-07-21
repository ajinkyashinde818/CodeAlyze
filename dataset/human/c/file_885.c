#include <stdio.h>
#include <math.h>

int main(void){

  long n;
  scanf("%ld", &n);
  long prime_list[1000001];
  prime_list[0] = 0;
  prime_list[1] = 0;
  for (long i = 2; i <= 1000000; i++) {
    prime_list[i] = 1;
  }
  for (long i = 2; i <= 1000000; i++) {
    if (prime_list[i] == 1) {
      for (long j = 2; i*j <= 1000000; j++) {
        prime_list[i*j] = 0;
      }
    }
  }
  long ans = 0;
  long tmp = n;
  long e;
  long count;
  for (long i = 2; i <= sqrt(n); i++) {
    if (prime_list[i] == 1) {
      e = 0;
      while (tmp%i == 0) {
        e++;
        tmp /= i;
      }
      if (e != 0) {
        count = 0;
        for (long j = 1; ; j++) {
          count = j;
          e -= j;
          if (e <= count) {
            break;
          }
        }
        ans += count;
      }
    }
  }
  if (tmp != 1) {
    ans++;
  }
  printf("%ld\n", ans);

  return 0;
}
