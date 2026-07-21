#include <stdio.h>

long gojo(long a, long b){
  if(a % b)
    gojo(b, a%b);
  else
    return b;
}

int main(){
  long a, b;  scanf("%ld %ld", &a, &b);
  if(b > a){
    long t = a; a = b; b = t;
  }
  long gcd = gojo(a, b);

  printf("%ld\n", a*b/gcd);
  return 0;
}
