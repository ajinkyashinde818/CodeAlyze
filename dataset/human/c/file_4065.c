#include <stdio.h>

int main(){
  int A; scanf("%d", &A);
  int B; scanf("%d", &B);
  int K; scanf("%d", &K);

  int div[51] = {};
  int small, i;
  int count = 0;
  small = A <= B ? A : B;

  for(i = small; i > 0; i--){
    if(A % i == 0 && B % i == 0){
      count++;
      div[count] = i;
    }
  }

  printf("%d", div[K]);

  return 0;
}
