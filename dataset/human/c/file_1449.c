#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int N, a;
  scanf("%d", &N);
  a = N%10;
  if (a==0){
    printf("No");
  }else if (a%9==0 || N/90==1)
  {
    printf("Yes");
  }else{
    printf("No");
  }
}
