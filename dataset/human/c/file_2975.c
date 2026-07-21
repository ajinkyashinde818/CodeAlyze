#include <stdio.h>
#include <stdlib.h>

#define MAX_N (100000L)

int main(int argc, char *argv[]) {
  // read inputs
  long N, as[MAX_N];
  scanf("%ld", &N);
  for (long i = 0; i < N; i++) {
    scanf("%ld", &as[i]);
  }

  // xs[i] : the number of times the box i is chosen.
  //    N       xs[0] + (N - 1) xs[1] + ... + 1       xs[N - 1] = as[0]
  //    1       xs[0] + N       xs[1] + ... + 2       xs[N - 1] = as[1]
  //    ...
  //    (N - 1) xs[0] + (N - 2) xs[1] + ... + N       xs[N - 1] = as[N - 1]
  long xs[MAX_N];

  // calculate sum_a, sum_x, and sum_i
  long sum_a = 0, sum_i = N * (N + 1) / 2;
  for (long i = 0; i < N; i++) {
    sum_a += as[i];
  }
  if (sum_a % sum_i != 0) {
    printf("NO\n");
    return 0;
  }
  const long sum_x = sum_a / sum_i;
  
  // calculate xs[i]
  for (long i = 0; i < N; i++) {
    const long Nx = sum_x + as[i] - as[(i + 1) % N];
    if (Nx % N != 0) {
      printf("NO\n");
      return 0;
    }
    const long x = Nx / N;
    if (x < 0) {
      printf("NO\n");
      return 0;
    }
    xs[i] = x;
  }
  printf("YES\n");
  
  return 0;
}
