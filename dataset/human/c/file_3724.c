#include <stdio.h>
 
int main(){
  long long int A, B, r, p, tmp;
  scanf("%lld %lld", &A, &B);
 
  p = A * B;
 
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
 
  printf("%lld", p/B);
 
  return 0;
}
