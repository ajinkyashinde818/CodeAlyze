#include <stdio.h> 
int main() {
  long A, B, r, x, tmp;
  scanf("%ld", &A);
  scanf("%ld", &B);
  x = A * B;
  if(A < B){
    tmp = A;
    A = B;
    B = tmp;
  }
  r = A % B;
  while(r != 0){
    A = B;
    B = r;
    r = A % B;
  }
  printf("%ld\n", x/B);
  return 0;
}
