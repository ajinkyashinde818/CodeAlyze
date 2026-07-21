#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
  int N, A[200010], ans = 1;
  int num[200010] = { 0 };
  long long K, i;
  scanf("%ld %lld", &N, &K);
  for (i = 0; i < N; i++) scanf("%ld", A + i);
  for (i = 0; i < K; i++) {
    if (num[ans - 1] == 0) {
      num[ans - 1] = i;
    }
    else {
      K = (K - num[ans - 1]) % (i - num[ans - 1]) + num[ans - 1];
      break;
    }
    ans = A[ans - 1];
  }
  ans = 1;
  for (i = 0; i < K; i++) {
    ans = A[ans - 1];
  }
  printf("%ld", ans);
  return 0;
}
