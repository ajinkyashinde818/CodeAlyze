#include <stdio.h>

int main(void)
{
  int A, B, C, D;
  long long S1, S2;
  
  scanf("%d %d %d %d", &A, &B, &C, &D );
  
  S1 = A*B;
  S2 = C*D;
  
  if( S1 < S2 ) printf("%lld\n", S2);
  else{         printf("%lld\n", S1);}
  
  
  
  return 0;
}
