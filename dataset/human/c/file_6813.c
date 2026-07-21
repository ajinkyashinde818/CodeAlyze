#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b){
  return *(int *)b - *(int *)a;
}

int main(int argc, char const *argv[]) {

  int N;
  scanf("%d", &N);
  int M = 3 * N;
  int a[M];
  for (int i = 0; i < M; i++) {
    scanf("%d", a + i);
  }
  qsort(a, M, sizeof(int), compare_int);

  // for (int i = 0; i < M; i++) {
  //   printf("a[%d] = %d\n", i, a[i]);
  // }

  long long int sum = 0;
  for (int i = 0; i < N; i++) {
    //printf("a[%d] = %d\n", 1 + 2 * i, a[1 + 2 * i]);
    sum += a[1 + 2 * i];
  }

  printf("%lld\n", sum);

  return 0;
}
