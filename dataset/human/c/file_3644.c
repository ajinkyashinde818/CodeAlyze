#include <stdio.h>

int main(){
  long int a,b;
  long int c;
  int r,tmp;
  scanf("%ld %ld",&a,&b);
  
  c = a * b;
  if (a < b) {
    tmp = a;
    a = b;
    b = tmp;
  }
  
  r = a % b;
  while (r != 0) {
    a = b;
    b = r;
    r = a % b;
  }
  printf("%ld\n", c / b);
  
  return 0;
}
