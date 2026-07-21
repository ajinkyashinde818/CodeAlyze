#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct a {
  long long int next;
  int flag;
  long long int from_start;
};

int main(void) {
  long long int n, k;
  scanf("%lld %lld", &n, &k);
  struct a a[n];
  for (long long int i = 0; i < n; i++) {
    scanf(" %lld", &a[i].next);
    a[i].flag = 0;
    a[i].from_start = 0;
  }

  long long int count = 0, pointer = 1;
  int break_flag = 0;
  for (long long int i = 0; i < k; i++) {
    a[pointer - 1].flag += 1;
    if (a[pointer - 1].flag == 2) {
      break_flag = 1;
      break;
    }
    a[pointer - 1].from_start = count;
    count++;
    pointer = a[pointer - 1].next;
  }

  if (!break_flag) printf("%lld\n", pointer);
  else {
    k -= a[pointer - 1].from_start;
    long long int hop = k % (count - a[pointer - 1].from_start);
    for (long long int i = 0; i < hop; i++) {
      pointer = a[pointer - 1].next;
    }
    printf("%lld\n", pointer);
  }

  return 0;
}
