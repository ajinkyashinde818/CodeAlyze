#include <stdio.h>

int main(void){
  unsigned long int a, b, n, r, tmp;
  scanf("%ld", &a);
  scanf("%ld", &b);

  n=a*b;//あとで最大公約数で割ると最小公倍数になる

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

  n /= b;
  printf("%ld\n", n);
  return 0;
}
