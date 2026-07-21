#include <stdio.h>
int main(){
  
  int A, B, K, a, i, j = 0, b;
  
  scanf("%d%d%d", &A, &B, &K);
  
  if(A < B){
    a = A;
  } else {
    a = B;
  }
  
  int Num[a + 1];
  
  for(i = 1; i <= a; ++i){
    Num[i] = 0;
    if(A % i == 0 && B % i == 0){
      Num[i] = 1;
    }
  }
  
  for(i = a; i >= 1; --i){
    if(Num[i] == 1){
      ++j;
    }
    if(j == K){
      b = i;
      break;
    }
  }
  
  printf("%d\n", b);
  
  return 0;
}
