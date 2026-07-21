#include <stdio.h>

int main(void){
  int A, B, C, D, i, X, Y;
  
  scanf("%d", &A);
  scanf("%d", &B);
  scanf("%d", &C);
  scanf("%d", &D);
  
  X = A * B;
  Y = C * D;
  
  if(X < Y)
    printf("%d", Y);
  else if(Y < X)
    printf("%d", X);
  else if(X = Y)
    printf("%d", X);
  
  return 0;
}
