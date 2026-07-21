#include <stdio.h>

int N(int A, int B, int K){
  int n, c;
  c = 0;
  for(n = 100;n > 0;n--){
    if(A % n + B % n == 0) c++;
    if(c == K) break;
  }
  return n;
}

int main(void){
  int A, B, K;
  scanf("%d %d %d", &A, &B, &K);
  printf("%d\n", N(A, B, K));
  return 0;
}
