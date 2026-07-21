#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void) {
  long long int k, n;
  scanf("%lld %lld", &n, &k);

  long long int diff[k];
  long long int start = 0;
  long long int point = 0;
  long long int max = 0;
  long long int max_i = 0;

  scanf(" %lld", &start);
  point = start;
  for (long long int i = 0; i < k; i++) {
    
    if (i == k - 1) {
      // printf("i: %lld\n", i);
      diff[i] = n - point + start;
    } else {
      scanf(" %lld", &diff[i]);
      diff[i] -= point;
      point += diff[i];
    }

    if (max < diff[i]) {
      max = diff[i];
      max_i = i;
    }
    // printf("%lld\n", diff[i]);
  }

  long long int result = 0;
  long long int pointer_i = max_i + 1;
  for (long long int i = 0; i < k - 1; i++) {
    result += diff[(i + pointer_i) % k];
  }

  printf("%lld\n", result);

  return 0;
}
