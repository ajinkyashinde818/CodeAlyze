#include <stdio.h>
#include <stdint.h>
#define OK 0
#define NG 1
#define MOD 1000000007
  
static char A[100002];
static int64_t memo[100002];

int main(void) {
  int N, M;
  scanf("%d%d", &N, &M);
  for(int i = 0; i < M; i++) {
    int a;
    scanf("%d", &a);
    A[a] = NG;
  }

  memo[0] = 1;
  if(A[1] == OK)
    memo[1] = 1;
  for(int i = 2; i <= N; i++) {
    if(A[i] == NG) {
      memo[i] = 0;
      continue;
    }
    memo[i] = (memo[i-1] + memo[i-2]) % MOD;
  }
  
  printf("%ld\n", memo[N]);
  return 0;
}
