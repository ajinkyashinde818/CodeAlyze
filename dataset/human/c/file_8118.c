#include<stdio.h>
int main(){
  int unused __attribute__((unused));
  int A, B, C, D;

  unused = scanf("%d %d %d %d", &A, &B, &C, &D);
  if(A*B >= C*D) printf("%d", A*B);
  else printf("%d", C*D);

  return 0;
}
