#include <stdio.h>

int main(void){

  long k,n;
  scanf("%ld %ld", &k, &n);
  long a[n];
  for (long i = 0; i < n; i++) {
    scanf("%ld", &a[i]);
  }

  long toNext[n];
  for (long i = 0; i < n-1; i++) {
    toNext[i] = a[i+1] - a[i];
  }
  toNext[n-1] = k - a[n-1];
  toNext[n-1] += a[0];

  long max = toNext[0];
  for (long i = 1; i < n; i++) {
    if (toNext[i] > max) {
      max = toNext[i];
    }
  }

  long answer;
  answer = k - max;
  printf("%ld\n", answer);

  return 0;
}
