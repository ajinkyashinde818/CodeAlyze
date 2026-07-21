#include <stdio.h>
#include <stdlib.h>

#define MAX_N (100000)
#define MAX_M (MAX_N - 1)
#define NUM_MOD (1000000007)

int main(int argc, char *argv[]) {
  // read inputs
  int N, M, as[MAX_M];
  scanf("%d %d", &N, &M);
  // printf("N = %d, M = %d\n", N, M);
  for (int i = 0; i < M; i++) {
    scanf("%d", &as[i]);
    // printf("i = %d, as[i] = %d\n", i, as[i]);
  }

  // create boolean array
  int bs[MAX_N + 1] = {};
  for (int i = 0; i < M; i++) {
    bs[as[i]] = 1;
  }

  // solve
  int dps[MAX_N + 1];
  dps[N] = 1;
  for (int i = N - 1; i >= 0; i--) {
    if (bs[i]) {
      dps[i] = 0;
    } else {
      dps[i] = (dps[i + 1] + (i + 2 <= N ? dps[i + 2] : 0)) % NUM_MOD;
    }
  }
  printf("%d\n", dps[0]);

  return 0;
}
