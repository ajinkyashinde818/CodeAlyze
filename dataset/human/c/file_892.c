#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000000

int main(void) {
  long long int n;
  scanf("%lld", &n);

  long long int factors[MAX];
  long long int pointer = 0;
  for (long long int i = 2; i * i <= n; i++) {
    if (pointer > MAX) {
      printf("over\n");
      break;
    } else {
      factors[pointer] = 0;
    }
    while (!(n % i)) {
      factors[pointer]++;
      n /= i;
      if (n % i) pointer++;
    }
  }

  // printf("%lld\n", pointer);
  long long int result = 0;
  for (long long int i = 0; i < pointer; i++) {
    long long int count = factors[i];
    // printf("count: %lld\n", count);
    for (long long int j = 1; j <= count; j++) {
      result++;
      count -= j;
    }
  }
  if (n != 1) result++;

  printf("%lld\n", result);

  return 0;
}
