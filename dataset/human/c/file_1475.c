#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
  int N, a, b;
  scanf("%d",&N);
  a = N%10;
  b = (N-a)/10;
  if(a!=9 && b!=9) printf("No\n");
  else printf("Yes\n");

  return 0;
}
