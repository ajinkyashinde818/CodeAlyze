#include <stdio.h>

int main(){
  long long a, b, x;
  
  scanf("%lld", &a);
  scanf("%lld", &b);
  
  x = a * b;
  
  if(a < b){
    long long temp = a;
    a = b;
    b = temp;
  }
  
  long long r = a % b;
  while(r != 0){
    a = b;
    b = r;
    r = a % b;
  }
  
  printf("%lld\n", x / b);
  return 0;
}
