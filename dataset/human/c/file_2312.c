#include <stdio.h>

int main(void){

  long n,k,s;
  scanf("%ld %ld %ld", &n, &k, &s);

  long other = s+1;
  if (other > 1000000000) {
    other = 1;
  }

  if (k != 0) {
    printf("%ld", s);
    for (long i = 1; i < k; i++) {
      printf(" %ld", s);
    }
    for (long i = k; i < n; i++) {
      printf(" %ld", other);
    }
  } else {
    printf("%ld", other);
    for (long i = 1; i < n; i++) {
      printf(" %ld", other);
    }
  }

  printf("\n");

  return 0;
}
