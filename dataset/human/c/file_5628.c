#include <stdio.h>
int main(void){
  long long int x;
  scanf("%lld",&x);
  if(1 <= x && x <= 6){
    printf("1");
  }else if(x <= 10){
    printf("2");
  }else if(x % 11 == 0){
    printf("%lld",2*x/11);
  }else if(1 <= x % 11 && x % 11 <= 6){
    printf("%lld",2*(x/11)+1);
  }else if(7 <= x % 11 && x  % 11 <= 10){
    printf("%lld",2*(x/11)+2);
  }
  return 0;
}
