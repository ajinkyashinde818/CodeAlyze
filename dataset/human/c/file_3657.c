#include <stdio.h>
 
int main(void)
{
 
  long int a, b, r, x, tmp;
  scanf("%ld", &a);
  scanf("%ld", &b);
 
  x = a * b;
  if(a<b){
    tmp = a;
    a = b;
    b = tmp;
  }
  r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }
  printf("%ld\n", x/b);
 
  return 0;
}
