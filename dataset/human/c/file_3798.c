#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void){
  int a, b;
  scanf("%d", &a);
  scanf("%d", &b);
  if(a<b){
    int tmp = a;
    a = b;
    b = tmp;
  }

  long int i=1;
  long int mul;
  while(1){
    mul = (long int)a*i;
    if(mul%b == 0)
      break;
    i++;
  }

  printf("%ld\n", mul);
  
  return 0;
}
